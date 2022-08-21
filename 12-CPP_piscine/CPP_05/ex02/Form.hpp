/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:04:02 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/19 20:04:03 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string   name;
    const int           gradeToSign;
    const int           gradeToExec;
    bool                isSigned;

protected:
    std::string         target;

public:
    Form(std::string name, const int gradeToSign, const int gradeToExec);
    Form(Form& copy);
    virtual ~Form();
    Form &operator=(Form &src);

    std::string     getName(void) const;
    int             getGradeToSign(void) const;
    int             getGradeToExec(void) const;
    bool            getIsSigned(void) const;
    void            beSigned(Bureaucrat *bur);

    virtual void    execute(Bureaucrat const &bur) const = 0;

    class FormNotSignedException : public std::exception
    { public: virtual const char *what() const throw(); };
};

std::ostream	&operator<<(std::ostream &o, Form *a);

#endif