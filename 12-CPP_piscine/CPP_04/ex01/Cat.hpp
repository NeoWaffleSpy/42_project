/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:17:26 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 16:17:27 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
private:
    Brain   *brain;

public:
    Cat();
    Cat(Cat& copy);
    ~Cat();
    Cat &operator=(Cat &src);

    void    makeSound(void) const;
    void	getIdea(void);
    void	setIdea(int i, std::string str);
};

#endif