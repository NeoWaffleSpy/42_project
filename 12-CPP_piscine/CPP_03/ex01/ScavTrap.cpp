/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:33:37 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/17 17:33:39 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->HP = 100;
    this->EP = 50;
	this->Attack = 20;
	this->maxHealth = 100;
    std::cout << "ScavTrap creation: " << this->name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& copy): ClapTrap(copy)
{
    *this = copy;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destruction: " << this->name << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &src)
{
	if (this != &src)
    {
		this->name = src.name;
		this->HP = src.HP;
		this->EP = src.EP;
		this->Attack = src.Attack;
    }
	return *this;
}

void    ScavTrap::guardGate(void)
{
    if (this->HP <= 0)
		std::cout << this->name << " couldn't enter gatekeeper mode, as he is dead." << std::endl;
	else
	    std::cout << this->name << " is now in gatekeeper mode." << std::endl;
}