/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:39:49 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 03:39:50 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name): type(name)
{}

Weapon::~Weapon()
{}

const std::string	&Weapon::getType(void)
{
    return (this->type);
}

void	Weapon::setType(std::string var)
{
    this->type = var;
}