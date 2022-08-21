/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:43:35 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/21 20:43:37 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern& copy)
{
    *this = copy;
}

Intern::~Intern()
{}

Intern &Intern::operator=(Intern &src)
{
    if (this == &src)
        return *this;

    return *this;
}

Form *Intern::makeForm(const std::string form, const std::string target)
{
    if (!form.compare("PresidentialPardonForm"))
        return new PresidentialPardonForm(target);
    if (!form.compare("RobotomyRequestForm"))
        return new RobotomyRequestForm(target);
    if (!form.compare("ShrubberyCreationForm"))
        return new ShrubberyCreationForm(target);
    std::cout << "No form matches the name: " << form << std::endl;
    return NULL;
}