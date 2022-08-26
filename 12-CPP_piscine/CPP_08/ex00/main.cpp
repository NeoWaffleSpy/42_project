/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:03:12 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 03:03:13 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

template<typename T>
void	displayIterator( T it, T end )
{
	if (it != end)
		std::cout << "iterator: " << *it << std::endl;
	else
		std::cout << "iterator reached the end of container" << std::endl;
}

int	main( void )
{
	std::vector<int>			vect;
	std::vector<int>::iterator	it;

	for (int i = 1; i < 59; i += 2)
		vect.push_back(i);
	it = easyfind(vect, 43);
	displayIterator(it, vect.end());
	it = easyfind(vect, 42);
	displayIterator(it, vect.end());
}
