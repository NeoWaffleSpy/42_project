/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:14:48 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 03:14:49 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie  *zombieHorde(int n, std::string name)
{
    Zombie  *horde = new Zombie[n];

    for (int i = 0; i < n; i++)
    {
        horde[i].setName(name);
    }
    return (horde);
}