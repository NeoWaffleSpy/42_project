/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:03:56 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 20:03:57 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, const int gradeToSign, const int gradeToExec):
    name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec), isSigned(false)
{
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Bureaucrat::GradeTooLowException();
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Bureaucrat::GradeTooHighException();
}

Form::Form(Form& copy):
    name(copy.name), gradeToSign(copy.gradeToSign), gradeToExec(copy.gradeToExec), isSigned(copy.isSigned)
{
    *this = copy;
}

Form::~Form()
{}

Form &Form::operator=(Form &src)
{
    if (this == &src)
        return *this;

    return *this;
}

std::string	Form::getName(void)
{
    return (this->name);
}

int    Form::getGradeToSign(void)
{
    return this->gradeToSign;
}

int    Form::getGradeToExec(void)
{
    return this->gradeToExec;
}

bool    Form::getIsSigned(void)
{
    return this->isSigned;
}

void    Form::beSigned(Bureaucrat *bur)
{
    if (bur->getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw Bureaucrat::GradeTooLowException();
}

/* OS OVERLOAD */

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() <<
        ":\n\tis signed: " << a->getIsSigned() <<
        "\n\tgrade to sign: " << a->getGradeToSign() <<
        "\n\tgrade to exec: " << a->getGradeToExec() <<
        std::endl;
	return (o);
}