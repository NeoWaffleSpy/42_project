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

void    ScavTrap::attack(const std::string& target)
{
    if (this->HP <= 0)
        std::cout << this->name <<" is dead and can't attack. but SCAVTRAP!" << std::endl;
    else if (this->EP <= 0)
        std::cout << this->name << " is tired and can't attack. but SCAVTRAP!" << std::endl;
    else
    {
        std::cout << this->name << " attacked " << target << " dealing him " << this->Attack << " damages. but SCAVTRAP!" << std::endl;
        this->EP--;
    }
}

void    ScavTrap::guardGate(void)
{
    if (this->HP <= 0)
		std::cout << this->name << " couldn't enter gatekeeper mode, as he is dead." << std::endl;
	else
	    std::cout << this->name << " is now in gatekeeper mode." << std::endl;
}