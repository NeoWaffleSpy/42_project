/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:33:42 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/17 17:33:43 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:
    /* data */

public:
    ScavTrap(std::string = "Unnamed");
    ScavTrap(ScavTrap& copy);
    ~ScavTrap();
    ScavTrap &operator=(ScavTrap &src);

    void    attack(const std::string& target);
    void    guardGate(void);
};

#endif