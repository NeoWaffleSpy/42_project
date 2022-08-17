/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:50:46 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/17 16:50:47 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>
# include <string>

class ClapTrap
{
protected:
    std::string     name;
    unsigned int    HP;
    unsigned int    EP;
    unsigned int    Attack;
    unsigned int    maxHealth;

public:
    ClapTrap(std::string name);
    ClapTrap(ClapTrap& copy);
    ~ClapTrap();
    ClapTrap &operator=(ClapTrap &src);

    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};

#endif