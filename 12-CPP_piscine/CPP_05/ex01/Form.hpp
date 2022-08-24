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

public:
    Form(std::string = "Unnamed", const int = 150, const int = 150);
    Form(Form& copy);
    ~Form();
    Form &operator=(Form &src);

    std::string         getName(void);
    int                 getGradeToSign(void);
    int                 getGradeToExec(void);
    bool                getIsSigned(void);
    void                beSigned(Bureaucrat *bur);
};

std::ostream	&operator<<(std::ostream &o, Form *a);

#endif