/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:22:09 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/26 19:22:09 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <iomanip>
# include <string>

template <typename T>
void    swap(T &a,T &b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T       min(T a, T b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
T       max(T a, T b)
{
    if (a > b)
        return a;
    return b;
}

#endif
