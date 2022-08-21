/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:22:46 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/21 16:22:46 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm: public Form
{
private:
    /* data */

public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm& copy);
    ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(PresidentialPardonForm &src);

    void    execute(Bureaucrat const &bur) const;
};

#endif