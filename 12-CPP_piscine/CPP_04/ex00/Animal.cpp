/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:17:13 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 16:17:14 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Undefined")
{
    std::cout << "Creation of an undefined animal" << std::endl;
}

Animal::Animal(Animal& copy)
{
    *this = copy;
    std::cout << "Copy of an undefined animal" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Destruction of an undefined animal" << std::endl;
}

Animal &Animal::operator=(Animal &src)
{
    std::cout << "Assignation of an undefined animal" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	return *this;
}

void    Animal::makeSound(void) const
{
    std::cout << "*Undefined animal noise*" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}
