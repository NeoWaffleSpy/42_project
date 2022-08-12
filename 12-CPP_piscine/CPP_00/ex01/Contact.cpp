/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 21:43:27 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/12 21:43:27 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

std::string Contact::fields_name[6] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Login",
	"Address",
	"E-mail"
};

Contact::Contact()
{}

Contact::~Contact()
{}

    void    set_info(int index);
    void    display_small(void);
    void    display_full(void);
void    Contact::set_info(int index):
            this->index(index)
{

}