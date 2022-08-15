/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 06:09:45 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 06:09:47 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string Harl::level[4] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR"
};

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]   :";
	std::cout << "I love to get extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I just love it!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]    :";
	std::cout << "I cannot believe adding extra bacon cost more money.";
	std::cout << " You don’t put enough! If you did I would not have to ask";
	std::cout << " for it!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING] :";
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming here for years and you just started ";
	std::cout << "working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]   :";
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl;
}

void    Harl::complain(std::string level)
{
	void    (Harl::*ptr_complain[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
	for (int i = 0; i < 4; i++)
	{
		if (!this->level[i].compare(level))
		{
			(this->*ptr_complain[i])();
			break ;
		}
    }
}