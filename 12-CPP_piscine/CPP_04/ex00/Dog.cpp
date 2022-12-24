/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:17:31 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 16:17:31 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
    this->type = "Dog";
    std::cout << "Creation of a Dog" << std::endl;
}

Dog::Dog(Dog& copy): Animal()
{
    std::cout << "Copy of a Dog" << std::endl;
    *this = copy;
}

Dog::~Dog()
{
    std::cout << "Destruction of a Dog" << std::endl;
}

Dog &Dog::operator=(Dog &src)
{
    std::cout << "Assignation of a Dog" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	return *this;
}

void    Dog::makeSound(void) const
{
    std::cout << "*woof* say the dog" << std::endl;
}