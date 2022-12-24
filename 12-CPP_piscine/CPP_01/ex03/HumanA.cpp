/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:39:29 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 03:39:30 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): weapon(&weapon), name(name)
{}

HumanA::~HumanA()
{}

void	HumanA::setWeapon(Weapon &var)
{
    this->weapon = &var;
}

void    HumanA::attack()
{
    std::cout << this->name << " attacked with " << this->weapon->getType() << std::endl;
}