/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:28:11 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 17:28:11 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <iterator>

class Brain
{
public:
    Brain();
    Brain(Brain& copy);
    ~Brain();
    Brain &operator=(Brain &src);

    std::string ideas[100];
};

#endif