/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 18:57:42 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 18:57:43 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string   name;
    int                 grade;

public:
	Bureaucrat(const std::string = "Unnamed", int = 150);
    Bureaucrat(Bureaucrat& copy);
    ~Bureaucrat();
    Bureaucrat &operator=(Bureaucrat &src);

    const std::string   getName(void) const;
    int	                getGrade(void) const;
    void	            setGrade(int var);
    void	            incGrade(void);
    void	            decGrade(void);
    void                signForm(Form *form);
    void                executeForm(Form const &form);

    class GradeTooLowException : public std::exception
    { public: virtual const char *what() const throw(); };

    class GradeTooHighException : public std::exception
    { public: virtual const char *what() const throw(); };
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif