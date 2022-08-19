/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:59:52 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 16:59:53 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <iomanip>
# include <string>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(WrongAnimal& copy);
    virtual ~WrongAnimal();
    WrongAnimal &operator=(WrongAnimal &src);

    void            makeSound(void) const;
    std::string     getType() const;
};

#endif