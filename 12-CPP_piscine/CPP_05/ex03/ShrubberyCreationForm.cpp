/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:23:00 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/21 16:23:00 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Shrubbery Creation", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy): Form("Shrubbery Creation", 145, 137)
{
    *this = copy;
    this->target = copy.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &src)
{
    if (this == &src)
        return *this;

    return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const &bur) const
{
    if (bur.getGrade() > this->getGradeToExec())
        throw Bureaucrat::GradeTooLowException();
    if (!this->getIsSigned())
        throw Form::FormNotSignedException();
    std::string tmp = this->target + "_shrubbery";
    std::ofstream outfile(tmp.c_str(), std::fstream::out | std::fstream::trunc);
	for (int i = 0; i < 5; i++)
	{
		outfile <<
		"         v" << std::endl <<
		"        >X<" << std::endl <<
		"         A" << std::endl <<
		"        d$b" << std::endl <<
		"      .d\\$$b." << std::endl <<
		"    .d$i$$\\$$b." << std::endl <<
		"       d$$@b" << std::endl <<
		"      d\\$$$ib" << std::endl <<
		"    .d$$$\\$$$b" << std::endl <<
		"  .d$$@$$$$\\$$ib." << std::endl <<
		"      d$$i$$b" << std::endl <<
		"     d\\$$$$@$b" << std::endl <<
		"  .d$@$$\\$$$$$@b." << std::endl <<
		".d$$$$i$$$\\$$$$$$b." << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
		"        ###" << std::endl <<
	    std::endl;
	}
	outfile.close();
}