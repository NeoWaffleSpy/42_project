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
# include <cstdlib>
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

    void            addNumber(int val);
    int             shortestSpan();
    int             longestSpan();
    unsigned int    getLength();
    void            randomFill();
};
 
struct Spanner
{
    int min;
    int max;
    Spanner()
    {
        min = -1;
        max = -1;
    }
    void operator()(int n)
    {
        pile.push_back(n);
        if (pile.size() >= 3)
            pile.erase(pile.begin());
        if (pile.size() >= 2)
        {
            int tmp;
            tmp = pile[0] - pile[1];
            if (tmp < 0)
                tmp *= -1;
            if (min == -1 || tmp < min)
                min = tmp;
            if (max == -1 || tmp > max)
                max = tmp;
        }
    }
    std::vector<int> pile;
};

std::ostream	&operator<<(std::ostream &o, Span &a);

#endif