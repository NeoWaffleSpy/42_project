/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:03:12 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 03:03:13 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>

int	main(int ac, char** av)
{
	std::fstream	fs_in;
	std::ofstream	fs_out;
	std::string		str;
	int				pos;
	bool			first;

	first = true;
	if (ac != 4)
	{
		std::cout << "Invalid parameters, use " << av[0] << " <Filemame> <PatternToReplace> <PatternThatReplace>" << std::endl;
		exit(1);
	}
	fs_in.open(av[1], std::fstream::in);
	if (fs_in.fail())
	{
		std::cout << "Error while trying to open file :" << av[1] << std::endl;
		exit(1);
	}
	fs_out.open(std::string(av[1]).append(".replace").c_str(), std::fstream::out | std::fstream::trunc);
	if (fs_out.fail())
	{
		std::cout << "Error while trying to open file :" << av[1] << ".replace" << std::endl;
		fs_in.close();
		exit(1);
	}
	do
	{
		if (!first)
			fs_out << std::endl;
		first = false;
		getline(fs_in, str);
		pos = str.find(av[2]);
		while (pos != -1)
		{
			str.erase((unsigned long)pos, std::string(av[2]).length());
			str.insert((unsigned long)pos, std::string(av[3]));
			pos = str.find(av[2]);
		}
		fs_out << str;
	} while (!fs_in.eof());
	fs_in.close();
	fs_out.close();
}