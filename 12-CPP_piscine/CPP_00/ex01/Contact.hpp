/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:43:31 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/12 21:43:32 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
private:
    int                 index;
    static std::string  fields_name[6];
    std::string         info[6];

public:
    Contact();
    virtual ~Contact();

    void    set_info(int index);
    void    display_small(void);
    void    display_full(void);
};

#endif