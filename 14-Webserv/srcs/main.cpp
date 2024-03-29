/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:33:01 by tmoragli          #+#    #+#             */
/*   Updated: 2022/11/19 22:23:37 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <vector>
#include "Parsing.hpp"
#include "Webserv.hpp"
#include <csignal>
#include <string>

Webserv webserv;

void close_client()
{
	if (webserv.client < 3)
		return ;
	close(webserv.client);
}

void signalHandler(int signum)
{
	if (signum == SIGINT)
	{
		for (std::map<int, Upload>::iterator it = webserv.uploads.begin(); it != webserv.uploads.end(); it++)
			if ((*it).second._file.is_open())
				(*it).second.closeFile();
		close_client();
		std::cout << RED << "\rTerminating server" << END << std::endl;
		for (int i = 0; i < 16; i++)
		{
			std::cout << GREEN << "🟩" << std::flush;
			usleep(50000);
		}
		std::cout << END << "]" << std::endl;
		std::cout << GREEN << "Done ✓" << END <<std::endl;
		exit(0);
	}
}

void	separate_lines(std::vector<std::string> &lines, std::string content)
{
	size_t	n;
	while (!content.empty())
	{
		n = find_first_line(content, 1);
		lines.push_back(content.substr(0, n));
		if (n != std::string::npos)
			content = content.substr(n, std::string::npos);
		else
			content.clear();
	}
}

bool	is_empty(std::string str)
{
	if (str == "\n" || str == "\r\n" || str == "\r" || str.empty())
		return (true);
	return (false);
}

bool	complete_request(std::string str, size_t maxBodySize)
{
	std::vector<std::string>	v;
	size_t						bodySize = 0;
	size_t						i = 0;
	std::string					tmp;

	if (str.empty())
		return (false);
	separate_lines(v, str);
	v_str_it	it = v.begin();

	if (v.empty())
		return (false);
	i = std::string::npos;
	while (it != v.end() && !is_empty(*it) && i == std::string::npos)
	{
		i = (*it).find("Content-Length: ");
		if (i == std::string::npos)
			it++;
		if (it == v.end())
			return (false);
	}
	if (i != std::string::npos)
	{
		i = ((*it).find("\n") < (*it).find("\r") ? (*it).find("\n") : (*it).find("\r"));
		tmp = (*it).substr(16, i);
		bodySize=atoi(tmp.c_str());

		if (bodySize > maxBodySize)
			return (true);
	}
	while (it != v.end() && !is_empty((*it)))
		it++;
	if (bodySize == 0)
		return (true);
	it++;
	while (it != v.end() && bodySize > (*it).size())
	{
		bodySize -= ((*it).size());
		it++;
	}
	if (it == v.end())
		return (false);
	return (true);
}

void	send_answers(std::map<int, std::string>& answers)
{
	for (std::map<int, std::string>::iterator it = answers.begin(); it != answers.end(); it++)
		if (webserv.getEvent((*it).first).events & EPOLLOUT)
			send((*it).first, (*it).second.c_str(), (*it).second.size(), MSG_NOSIGNAL);
	answers.clear();
}

void	closeFd(int fd)
{
	if (fd < 3)
		return ;
	close(fd);
	webserv.remove_event(fd);
}

void	start(std::vector<Server>& servers)
{
	int		fd_listen;
	int		fdMax = 0;
	int		ret;
	int		read_char;
	int		count = 0;
	char	buff[BUFFER_SIZE + 1];
	bool	found = false;

	printWebserv();
	std::signal(SIGINT, signalHandler);
	webserv.allocating(servers.size());
	webserv.setMaxEvent(0);
	for (std::vector<Server>::iterator it = servers.begin(); it != servers.end(); it++)
	{
		fd_listen = (*it).init_socket();
		if (fd_listen > 0)
		{
			(*it).setSocket(fd_listen);
			if (fd_listen > fdMax)
			{
				fdMax = fd_listen;
				webserv.setMaxEvent(fdMax);
			}
			try
				{webserv.setServer(count, (*it));}
			catch(const std::exception& e)
				{std::cerr<< RED << " " << fd_listen << e.what() << END << '\n';}
			webserv.add_event(fd_listen, EPOLLIN);
			count++;
		}
		else
			exit(fd_listen);
	}
	while (true)
	{
		ret = epoll_wait(webserv.getEpollfd(), webserv.getEvents(), webserv.getNbEvents(), -1);
		for (int i = 0; i < ret; i++)
		{
			found = false;
			for (size_t j = 0; j < servers.size(); j++)
			{
				if (webserv.getEvent(i).data.fd == webserv.getServer(j).getSocket())
				{
					int new_client;
					found = true;
					new_client = accept(webserv.getServer(j).getSocket(), NULL, NULL);
					if (new_client <= 0)
					{
						std::cerr << RED << "/!\\ Accept for client failed /!\\" << END << std::endl;
						continue ;
					}
					if (new_client > fdMax)
					{
						fdMax = new_client;
						webserv.setMaxEvent(fdMax);
					}
					webserv.client_serv[new_client] = webserv.getServer(j);
					webserv.add_event(new_client, EPOLLIN | EPOLLOUT);
				}
			}
			if (!found)
			{
				webserv.client = webserv.getEvent(i).data.fd;
				if (webserv.getEvent(i).events & EPOLLIN)
				{
					usleep(100);
					read_char = 1;
					while (!complete_request(webserv.buffer_strings[webserv.client], webserv.client_serv[webserv.client].getBody()))
					{
						memset(buff, 0, sizeof(char) * (BUFFER_SIZE + 1));
						read_char = recv(webserv.client, buff, BUFFER_SIZE, MSG_DONTWAIT);
						if (read_char < 0)
						{
							webserv.buffer_strings[webserv.client].clear();
							closeFd(webserv.client);
						}
						if (read_char <= 0)
						{
							webserv.requests.erase(webserv.client);
							break;
						}
						webserv.buffer_strings[webserv.client].append(buff, read_char);
					}
					found = true;
				}
			}
		}
		for (int i = 0; i <= fdMax ; i++)
		{
			if (complete_request(webserv.buffer_strings[i], webserv.client_serv[i].getBody()))
			{
				HttpRequest	tmp_request(webserv.client_serv[i]);
				try
				{
					if (parsingRequest(tmp_request, webserv.buffer_strings[i]))
						webserv.buffer_strings[i].clear();
					else
						webserv.requests.insert(std::pair<int, HttpRequest>(i, tmp_request));
				}
				catch(const std::exception& e)
					{std::cerr << e.what() << '\n';}
			}
		}
		answers_gen(webserv.requests, webserv.answers, webserv.uploads, webserv.client_serv);
		if (!webserv.answers.empty())
			send_answers(webserv.answers);
	}
}

int	checkFile(char* filePath)
{
	std::string		str = filePath;
	int				fd;
	if (str.find_last_of(".conf") != str.length() - 1)
	{
		std::cerr << RED <<
		"/!\\ Wrong file extension:\nTry yourfile.conf /!\\"
		<< END << std::endl;
		return (1);
	}
	fd = open(filePath, O_RDONLY);
	if (fd < 3)
	{
		std::cerr << RED
		"/!\\ Unable to open the configuration file:\ncheck the spelling and the permissions of the file/!\\"
		<< END << std::endl;
		return (1);
	}
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	
	if (ac == 1)
		parse_config("default.conf", webserv.servs);	
	else if (ac > 2)
	{
		std::cerr << RED <<
		"/!\\ Wrong number of arguments:\nTry ./webserv <path_to_config_file> /!\\"
		<< END << std::endl;
		return (1);
	}
	else
	{
		if (!parse_config(av[1], webserv.servs))
			return (1);
		start(webserv.servs);
	}
	start(webserv.servs);
	return (0);
}