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
    srand (time(NULL));
    
    A a;
    B b;
    C c;

    std::cout << "Pointers :" << std::endl;
    identify(&b);
    identify(&a);
    identify(&c);

    std::cout << "References :" << std::endl;
    identify(c);
    identify(b);
    identify(a);

    std::cout << "Random Generation:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base *tmp;
        tmp = generate();
        identify(*tmp);
        identify(tmp);
        delete tmp;
        std::cout << std::endl;
    }
}
