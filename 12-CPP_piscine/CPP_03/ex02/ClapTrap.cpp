/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:50:40 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/17 16:50:42 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name = "Unnamed"): name(name), HP(10), EP(10), Attack(0), maxHealth(10)
{
    std::cout << "ClapTrap creation: " << this->name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& copy)
{
    *this = copy;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destruction: " << this->name << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &src)
{
	if (this != &src)
    {
		this->name = src.name;
		this->HP = src.HP;
		this->EP = src.EP;
		this->Attack = src.Attack;
		this->maxHealth = src.maxHealth;
    }
	return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->HP <= 0)
        std::cout << this->name <<" is dead and can't attack." << std::endl;
    else if (this->EP <= 0)
        std::cout << this->name << " is tired and can't attack." << std::endl;
    else
    {
        std::cout << this->name << " attacked " << target << " dealing him " << this->Attack << " damages." << std::endl;
        this->EP--;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HP <= 0)
        std::cout << this->name <<" is already dead and can't be attacked anymore." << std::endl;
    else
    {
        if (this->HP < amount)
            amount = this->HP;
        this->HP -= amount;
        std::cout << this->name << " took " << amount << " points of damages";
        if (this->HP <= 0)
            std::cout << " and tragically died !" << std::endl;
        else
            std::cout << " but survived the blow !" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->HP <= 0)
        std::cout << this->name <<" is already dead and can't repair itself." << std::endl;
    else if (this->HP >= this->maxHealth)
        std::cout << this->name <<" is already at full health." << std::endl;
    else if (this->EP <= 0)
        std::cout << this->name <<" is too tired and can't repair itself." << std::endl;
    else
    {
        if (this->HP + amount > this->maxHealth)
            amount = this->maxHealth - this->HP;
        this->HP += amount;
        EP--;
        std::cout << this->name <<" repaired itself for " << amount << " health points." << std::endl;
    }
}