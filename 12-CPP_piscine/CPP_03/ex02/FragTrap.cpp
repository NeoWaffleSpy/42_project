/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:22:15 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/17 19:22:17 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->HP = 100;
    this->EP = 100;
	this->Attack = 30;
	this->maxHealth = 100;
    std::cout << "FragTrap creation: " << this->name << std::endl;
}

FragTrap::FragTrap(FragTrap& copy): ClapTrap(copy)
{
    *this = copy;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destruction: " << this->name << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &src)
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

void    FragTrap::highFiveGuys(void)
{
    if (this->HP <= 0)
        std::cout << "although he is already dead, " << this->name << "'s hand is still raised, requesting a high five." << std::endl;
    else
        std::cout << this->name << " is requesting an epic high five." << std::endl;
}