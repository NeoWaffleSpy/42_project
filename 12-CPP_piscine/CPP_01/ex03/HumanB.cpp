/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:39:40 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 03:39:41 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(NULL), name(name)
{}

HumanB::~HumanB()
{}

void	HumanB::setWeapon(Weapon &var)
{
    this->weapon = &var;
}

void    HumanB::attack()
{
    if (this->weapon == NULL)
        std::cout << this->name << " injured himself trying to hit with his bare hands" << std::endl;
    else
        std::cout << this->name << " attacked with " << this->weapon->getType() << std::endl;
}