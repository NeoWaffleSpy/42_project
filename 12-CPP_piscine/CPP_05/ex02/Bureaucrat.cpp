/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:57:37 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 18:57:38 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name)
{
    this->setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat& copy)
{
    *this = copy;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &src)
{
	if (this == &src)
		return *this;

    this->setGrade(src.grade);
	return *this;
}

void	Bureaucrat::signForm(Form *form)
{
	try
	{
		form->beSigned(this);
		std::cout << this->name << " signed the form " << form->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[33m" << this->getName() << " was not able to sign the Form " << form->getName() << ": " << e.what() << "\033[0m" << std::endl;
	}
	
}

void	Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed the form " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\033[33m" << this->getName() << " was not able to execute the Form " << form.getName() << ": " << e.what() << "\033[0m" << std::endl;
	}
	
}

const std::string	Bureaucrat::getName(void) const
{
    return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

void	Bureaucrat::setGrade(int var)
{
	if (var > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (var < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = var;
}

void    Bureaucrat::incGrade(void)
{
    this->setGrade(this->grade - 1);
}
void    Bureaucrat::decGrade(void)
{
    this->setGrade(this->grade + 1);
}

/* EXCEPTIONS */

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

/* OS OVERLOAD */

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}