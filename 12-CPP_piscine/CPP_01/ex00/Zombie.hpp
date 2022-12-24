/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 02:42:10 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 02:42:11 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Zombie
{
private:
    std::string name;

public:
    Zombie(std::string name);
    ~Zombie();

    void    announce(void);
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

#endif