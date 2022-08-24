/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:22:21 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/17 19:22:22 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
private:
    /* data */

public:
    FragTrap(std::string = "Unnamed");
    FragTrap(FragTrap& copy);
    ~FragTrap();
    FragTrap &operator=(FragTrap &src);

    void    highFiveGuys(void);
};

#endif