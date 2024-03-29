/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:21:31 by tmoragli          #+#    #+#             */
/*   Updated: 2022/11/19 20:24:52 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

#include "Colors.hpp"
#include "Server.hpp"


void	print_separator()
{
	std::cout << WHITE << "~~~~~~~~~~~~~~~~~~" << END << std::endl;
}

void	display_v_str(std::vector<std::string> str)
{
	for (std::vector<std::string>::iterator i = str.begin(); i != str.end(); i++)
		std::cout << GREEN << "[" << (*i) << "]" << END << std::endl;
	if (str.empty())
		std::cout << YELLOW << "Empty arguments /!\\" << END << std::endl;
}

void	display_servers(std::vector<Server> servers)
{
	int count = 1;
	for (std::vector<Server>::iterator i = servers.begin(); i != servers.end(); i++)
	{
		print_separator();
		std::cout << BLUE << "Server number " << count << ":" << END << std::endl;
		std::cout << (*i) << std::endl;
		print_separator();
		count++;
	}
}