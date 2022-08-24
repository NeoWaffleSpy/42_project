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

#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "One Argument required." << std::endl;
		return (1);
	}
	switch (Convert::getType(argv[1]))
	{
	case 1:
		Convert::printFloat(atof(argv[1]));
		break;
	case 2:
		Convert::printDouble(atof(argv[1]));
		break;
	case 3:
		Convert::printChar(argv[1][0]);
		break;
	case 4:
		Convert::printInt(atoi(argv[1]));
		break;
	case 5:
		Convert::printNan(argv[1]);
		break;
	
	default:
		std::cout << "Unrecognized value: " << argv[1] << std::endl;
		break;
	}
	return (0);
}