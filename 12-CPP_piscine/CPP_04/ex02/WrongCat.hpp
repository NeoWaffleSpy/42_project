/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:00:01 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 17:00:02 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:
    /* data */

public:
    WrongCat();
    WrongCat(WrongCat& copy);
    ~WrongCat();
    WrongCat &operator=(WrongCat &src);

    void    makeSound(void) const;
};

#endif