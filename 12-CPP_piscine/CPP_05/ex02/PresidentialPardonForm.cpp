/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:22:41 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/21 16:22:42 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("Presidential Pardon", 25, 5)
{
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& copy): Form("Presidential Pardon", 25, 5)
{
    *this = copy;
    this->target = copy.target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &src)
{
    if (this == &src)
        return *this;

    return *this;
}

void    PresidentialPardonForm::execute(Bureaucrat const &bur) const
{
    if (bur.getGrade() > this->getGradeToExec())
        throw Bureaucrat::GradeTooLowException();
    if (!this->getIsSigned())
        throw Form::FormNotSignedException();
    std::cout << bur.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}