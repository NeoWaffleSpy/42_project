/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:39:54 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 03:39:54 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string name);
    ~Weapon();

    const std::string	&getType(void);
    void        setType(std::string var);
};


#endif

