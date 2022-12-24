/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:17:21 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 16:17:22 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
    this->type = "Cat";
    std::cout << "Creation of a cat" << std::endl;
}

Cat::Cat(Cat& copy): Animal()
{
    std::cout << "Copy of a cat" << std::endl;
    *this = copy;
}

Cat::~Cat()
{
    std::cout << "Destruction of a cat" << std::endl;
}

Cat &Cat::operator=(Cat &src)
{
    std::cout << "Assignation of a cat" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	return *this;
}

void    Cat::makeSound(void) const
{
    std::cout << "*mew* say the cat" << std::endl;
}
