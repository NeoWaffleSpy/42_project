/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:43:37 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/12 21:43:38 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Annuaire.hpp"

int main(void)
{
    Annuaire    annuaire;
    std::string command;
    Contact     clear;
    bool        is_running;

    is_running = true;
    std::cout << "Booting ze Annuaire" << std::endl;
    std::cout << "Use commands: ADD, SEARCH, EXIT" << std::endl;
    while (is_running)
    {
		std::cout << ">";
		std::getline(std::cin, command);
        clear.clean_spaces(&command);
        if (!command.compare("ADD"))
            annuaire.add_contact();
        else if (!command.compare("SEARCH"))
            annuaire.show_list();
        else if (!command.compare("EXIT"))
            is_running = false;
    }
    return 0;
}
