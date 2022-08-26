/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:03:12 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 03:03:13 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "identify.hpp"

int main()
{
    A a;
    B b;
    C c;

    std::cout << "Pointers :" << std::endl;
    identify_from_pointer(&b);
    identify_from_pointer(&a);
    identify_from_pointer(&c);

    std::cout << "References :" << std::endl;
    identify_from_reference(c);
    identify_from_reference(b);
    identify_from_reference(a);

}
