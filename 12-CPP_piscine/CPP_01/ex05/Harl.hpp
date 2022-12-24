/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 06:09:52 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 06:09:54 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Harl
{
private:
    void                debug(void);
    void                info(void);
    void                warning(void);
    void                error(void);
    static std::string  level[4];

public:
    Harl();
    ~Harl();

	void	complain(std::string level);
};


#endif