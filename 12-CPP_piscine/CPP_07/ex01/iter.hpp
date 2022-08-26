/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:53:27 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/26 19:53:29 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void    iter(T array[], int n, void(*ft)(T&))
{
    for (int i = 0; i < n; i++)
        ft(array[i]);
}

#endif