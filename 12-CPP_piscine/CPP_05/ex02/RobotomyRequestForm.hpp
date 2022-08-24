/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:22:55 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/21 16:22:55 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm: public Form
{
private:
    /* data */

public:
    RobotomyRequestForm(std::string = "Unnamed");
    RobotomyRequestForm(RobotomyRequestForm& copy);
    ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(RobotomyRequestForm &src);

    void    execute(Bureaucrat const &bur) const;
};

#endif