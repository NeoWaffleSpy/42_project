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

Span::Span(unsigned int i): length(i)
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

int    Span::shortestSpan()
{
	std::vector<int>    tmp = this->array;

    if (this->array.size() < 2)
        { throw std::logic_error("Cannot span less than 2 numbers"); }
	sort(tmp.begin(), tmp.end());
    Spanner s = std::for_each(tmp.begin(), tmp.end(), Spanner());
    return s.min;
}

int    Span::longestSpan()
{
	std::vector<int>    tmp = this->array;

    if (this->array.size() < 2)
        { throw std::logic_error("Cannot span less than 2 numbers"); }
	sort(tmp.begin(), tmp.end());
    Spanner s = std::for_each(tmp.begin(), tmp.end(), Spanner());
    return s.max;
}

unsigned int    Span::getLength()
{
    return this->array.size();
}

void    Span::randomFill()
{

    for (unsigned int i = this->array.size(); i < this->length; i++)
    {
        srand(rand());
        this->array.push_back(rand() % 100000);
    }
}

std::ostream	&operator<<(std::ostream &o, Span &a)
{
    if (a.getLength() <= 1)
        o << "\n\tarray length = " << a.getLength() << ", Not enough arguments to get it's span";
    else
        o << "\n\tarray length = " << a.getLength() <<
        "\n\tmax span = " << a.longestSpan() <<
        "\n\tmin span = " << a.shortestSpan();
    return o;
}