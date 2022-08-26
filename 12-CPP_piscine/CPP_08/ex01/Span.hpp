/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:05:35 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/26 22:05:41 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <algorithm>
# include <iterator>
# include <vector>

class Span
{
private:
    std::vector<int>    array;
    const unsigned int  length;

public:
    Span(unsigned int i = 0);
    Span(Span& copy);
    ~Span();
    Span &operator=(Span &src);

    void    Span::addNumber(int val);
    void    Span::shortestSpan();
    void    Span::longestSpan();
};

#endif