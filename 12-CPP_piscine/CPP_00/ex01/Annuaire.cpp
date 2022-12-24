/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Annuaire.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:43:15 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/12 21:43:15 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Annuaire.hpp"

Annuaire::Annuaire()
{
    this->number = 0;
}

Annuaire::~Annuaire()
{}

void    Annuaire::add_contact()
{
    this->contact[number % 8].set_info((this->number % 8) + 1);
    this->number++;
}

void    Annuaire::show_list()
{
    std::string str;
    int         num;

	std::cout << "|" << std::right << std::setw(10) << "index";
	std::cout << "|" << std::right << std::setw(10) << "First Name";
	std::cout << "|" << std::right << std::setw(10) << "Last Name";
	std::cout << "|" << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    num = 8;
    if (this->number < 8)
        num = this->number;
    for (int i = 0; i < num; i++)
    {
        this->contact[i].display_small();
    }
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    str.clear();
    while (str.empty())
    {
        std::cout << "\nSelect which contact to display or 0 to exit: ";
	    std::getline(std::cin, str);
        clear.clean_spaces(&str);
        for (int i = 0; i < (int)str.length(); i++)
        {
            if (isalpha(str[i]))
            {
                str.clear();
                std::cout << "Invalid identifier";
                break ;
            }
        }
        this->show_contact(atoi(str.c_str()));
    }
}

void    Annuaire::show_contact(int index)
{
    if (index == 0)
        return ;
    if (index < 0 || index > 8)
        std::cout << "index out of bounds" << std::endl;
    else if (index > (this->number + 1))
        std::cout << "Empty contact slot" << std::endl;
    else
        this->contact[index - 1].display_full();
}