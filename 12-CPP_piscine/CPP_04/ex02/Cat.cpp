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

Cat::Cat(): Animal(), brain(new Brain())
{
    this->type = "Cat";
    std::cout << "Creation of a cat" << std::endl;
}

Cat::Cat(Cat& copy): Animal()
{
    std::cout << "Copy of a cat" << std::endl;
    *this = copy;
    this->brain = new Brain(*copy.brain);
	this->type = copy.type;
}

Cat::~Cat()
{
    std::cout << "Destruction of a cat" << std::endl;
    delete this->brain;
}

Cat &Cat::operator=(Cat &src)
{
    std::cout << "Assignation of a cat" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

void    Cat::makeSound(void) const
{
    std::cout << "*mew* say the cat" << std::endl;
}

void	Cat::getIdea(void)
{
	for (int i = 0; i < 100; i++)
        if (!this->brain->ideas[i].empty())
		    std::cout << "\tIdea " << i << " of the " << this->type << " is: " << this->brain->ideas[i] << std::endl;
}

void	Cat::setIdea(int i, std::string idea)
{
    if (i < 0 || i >= 100)
        std::cout << "idea creation out of bounds for index " << i << ": " << idea << std::endl;
    else
	    this->brain->ideas[i] = idea;
}
