/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:22:50 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/21 16:22:51 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Robotomy Request", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& copy): Form("Robotomy Request", 72, 45)
{
    *this = copy;
    this->target = copy.target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &src)
{
    if (this == &src)
        return *this;

    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const &bur) const
{
    if (bur.getGrade() > this->getGradeToExec())
        throw Bureaucrat::GradeTooLowException();
    if (!this->getIsSigned())
        throw Form::FormNotSignedException();
    if (rand() % 2)
        std::cout << bur.getName() << " has been robotomized" << std::endl;
    else
        std::cout << bur.getName() << "'s robotomization failed" << std::endl;
}