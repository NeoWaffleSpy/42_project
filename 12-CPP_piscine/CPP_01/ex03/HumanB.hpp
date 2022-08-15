/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:39:45 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 03:39:46 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
    Weapon      *weapon;
    std::string name;

public:
    HumanB(std::string name);
    ~HumanB();

    void    attack(void);
    void	setWeapon(Weapon &var);
};

#endif
