/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:43:27 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/12 21:43:27 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::fields_name[6] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Login",
	"Address",
	"E-mail"
};

Contact::Contact()
{
	for (int i = 0; i < 6; i++)
		this->info[i] = std::string();
}

Contact::~Contact()
{}

void 	Contact::clean_spaces(std::string *str)
{
    for (int i = 0; i < (int)(*str).length(); i++)
    {
        if (isspace((*str)[i]))
		{
            (*str).erase(i, 1);
			i--;
		}
    }
}

void    Contact::set_info(int index)
{
	this->index = index;
	for (int i = 0; i < 6; i++)
	{
		this->info[i].clear();
		while (this->info[i].empty())
		{
			std::cout << "$->" << Contact::fields_name[i] << ": ";
			std::getline(std::cin, this->info[i]);
			this->clean_spaces(&this->info[i]);
		}
	}
}

void    Contact::display_small(void)
{
	std::cout << "|" << std::setw(10) << this->index;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "|";
		if (this->info[i].length() > 10)
			std::cout << this->info[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->info[i];
	}
	std::cout << "|" << std::endl;
}

void    Contact::display_full(void)
{
	std::cout << std::right << std::setw(13) << "index:";
	std::cout << std::right << this->index << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << std::right << std::setw(12) << Contact::fields_name[i] << ": ";
		std::cout << std::right << this->info[i] << std::endl;
	}
}