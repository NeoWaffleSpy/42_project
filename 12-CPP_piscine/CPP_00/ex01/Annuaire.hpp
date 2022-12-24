/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Annuaire.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:43:21 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/12 21:43:22 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANNUAIRE_H
# define ANNUAIRE_H

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class Annuaire
{
private:
    Contact contact[8];
    int     number;
    Contact clear;

public:
    Annuaire();
    ~Annuaire();
    void    add_contact(void);
    void    show_list(void);
    void    show_contact(int index);
};

#endif // ANNUAIRE_H