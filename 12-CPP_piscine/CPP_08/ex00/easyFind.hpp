/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:55:37 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/26 21:55:38 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
typename T::iterator	easyfind( T &container, int goal )
{
	typename T::iterator    result = find(container.begin(), container.end(), goal);

	return result;
}

#endif