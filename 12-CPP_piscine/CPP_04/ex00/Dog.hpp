/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:17:35 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 16:17:36 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Animal.hpp"

class Dog: public Animal
{
private:
    /* data */

public:
    Dog();
    Dog(Dog& copy);
    ~Dog();
    Dog &operator=(Dog &src);

    void    makeSound(void) const;
};

#endif