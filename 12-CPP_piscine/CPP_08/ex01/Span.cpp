/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:05:31 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/26 22:05:32 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int i): array(NULL), length(i)
{
    std::cout << "Constructor with a constant length of " << this->length << std::endl;
}

Span::Span(Span& copy): length(copy.length)
{
    std::cout << "Copy Constructor" << std::endl;
    *this = copy;
}

Span::~Span()
{
    std::cout << "Destructor" << std::endl;
    this->array.clear();
}

Span &Span::operator=(Span &src)
{
    std::cout << "Assignation Constructor" << std::endl;
    if (this == &src)
        return *this;

    return *this;
}

void    Span::addNumber(int val)
{
    if (this->array.size() > this->length)
        throw std::out_of_range("Cannot add numbers to a full array");
    else
        this->array.push_back(val);
}

void    Span::shortestSpan()
{
    if (this->array.size() < 2)
        throw std::logic_error("Cannot span less tthan 2 numbers");
}

void    Span::longestSpan()
{
	std::vector<int>    tmp = this->array;

    if (this->array.size() < 2)
        throw std::logic_error("Cannot span less tthan 2 numbers");
	sort(tmp.begin(), tmp.end());
}