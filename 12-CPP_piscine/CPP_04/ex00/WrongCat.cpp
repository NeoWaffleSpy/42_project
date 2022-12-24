/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:59:57 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 16:59:57 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "Creation of a WrongCat" << std::endl;
}

WrongCat::WrongCat(WrongCat& copy): WrongAnimal()
{
    std::cout << "Copy of a WrongCat" << std::endl;
    *this = copy;
}

WrongCat::~WrongCat()
{
    std::cout << "Destruction of a WrongCat" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &src)
{
    std::cout << "Assignation of a WrongCat" << std::endl;
	if (this == &src)
		return *this;

	this->type = src.type;
	return *this;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "*mew* say the wrong cat" << std::endl;
}