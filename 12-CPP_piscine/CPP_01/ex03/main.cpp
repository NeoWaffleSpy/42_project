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

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	Weapon club = Weapon("a crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("a motherfucking Morgenshtern");
	bob.attack();

	Weapon shuriken = Weapon("a vicious shuriken");
	HumanB jim("Jim");
	jim.setWeapon(shuriken);
	jim.attack();
	shuriken.setType("some other ninja shit");
	jim.attack();
}