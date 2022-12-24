/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:28:05 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 17:28:06 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Creation of a Brain !" << std::endl;
}

Brain::Brain(Brain& copy)
{
    std::cout << "Copy of a Brain !" << std::endl;
    *this = copy;
}

Brain::~Brain()
{
    std::cout << "Destruction of a Brain !" << std::endl;
}

Brain &Brain::operator=(Brain &src)
{
    std::cout << "Assignation of a Brain !" << std::endl;
	if (this == &src)
		return *this;
	for (int i = 0; i < 100; i++)
	{
		if (src.ideas[i].length() > 0)
			this->ideas[i].assign(src.ideas[i]);
	}
	return *this;
}