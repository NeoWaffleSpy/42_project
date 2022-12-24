/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:39:34 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 03:39:35 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
    Weapon      *weapon;
    std::string name;

public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();

    void    attack(void);
    void	setWeapon(Weapon &var);
};

#endif
