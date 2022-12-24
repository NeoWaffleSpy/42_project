/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:17:17 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 16:17:18 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <string>

class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal(Animal& copy);
    virtual ~Animal();
    Animal &operator=(Animal &src);

    virtual void    makeSound(void) const = 0;
    std::string     getType() const;
};

#endif