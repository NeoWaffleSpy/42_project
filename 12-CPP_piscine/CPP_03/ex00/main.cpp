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

#include <iomanip>
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	ClapTrap a("Bobby");
	ClapTrap b("Wall-E");

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	a.attack("some other robot");
	a.takeDamage(5);
	a.beRepaired(1);
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("the Buddy-bot");
	b.beRepaired(3);
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	return (0);
}