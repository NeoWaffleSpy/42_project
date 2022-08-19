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

Dog::Dog(): Animal(), brain(new Brain())
{
    this->type = "Dog";
    std::cout << "Creation of a Dog" << std::endl;
}

Dog::Dog(Dog& copy): Animal()
{
    std::cout << "Copy of a Dog" << std::endl;
    *this = copy;
    this->brain = new Brain(*copy.brain);
}

Dog::~Dog()
{
    std::cout << "Destruction of a Dog" << std::endl;
    delete this->brain;
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

void	Dog::getIdea(void)
{
	for (int i = 0; i < 100; i++)
        if (!this->brain->ideas[i].empty())
		    std::cout << "\tIdea " << i << " of the " << this->type << " is: " << this->brain->ideas[i] << std::endl;
}

void	Dog::setIdea(int i, std::string idea)
{
    if (i < 0 || i >= 100)
        std::cout << "idea creation out of bounds for index " << i << ": " << idea << std::endl;
    else
	    this->brain->ideas[i] = idea;
}