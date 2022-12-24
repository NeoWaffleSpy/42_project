/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 02:42:05 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 02:42:06 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    this->name = "Unnamed";
    std::cout << "An unnamed zombie is born" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "The zombie " << this->name << " is born" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "The zombie " << this->name << " was killed" << std::endl;
}

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}