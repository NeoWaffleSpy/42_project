/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:59:46 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 16:59:47 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Undefined")
{
    std::cout << "Creation of an undefined WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& copy)
{
    *this = copy;
    std::cout << "Copy of an undefined WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destruction of an undefined WrongAnimal" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &src)
{
    std::cout << "Assignation of an undefined WrongAnimal" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	return *this;
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "*Undefined wrong animal noise*" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}