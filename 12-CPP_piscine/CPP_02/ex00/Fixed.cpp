/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 06:46:37 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 06:46:40 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fp_value(0)
{}

Fixed::Fixed(Fixed& copy)
{
    *this = copy;
}

Fixed::~Fixed()
{}

Fixed &Fixed::operator=(Fixed &src)
{
	std::cout << "Fixed Assignation operator called" << std::endl;
	if (this != &src)
		this->_fp_value = src.getRawBits();

	return *this;
}

int	Fixed::getRawBits(void) const
{
    return (this->_fp_value);
}

void	Fixed::setRawBits(int const raw)
{
    this->_fp_value = raw;
}