/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:03:30 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/26 19:03:31 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identify.hpp"

void identify(Base * p)
{
    if (p == NULL)
        std::cout << "Null Pointer" << std::endl;
    else if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify( Base & p)
{
    try
    {
        void(dynamic_cast<A&>(p));
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}
    try
    {
        void(dynamic_cast<B&>(p));
        std::cout << "B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}
    try
    {
        void(dynamic_cast<C&>(p));
        std::cout << "C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error" << std::endl;
    }
}

Base *generate(void)
{
    srand (rand());
    switch (rand() % 3)
    {
    case 0:
        return (new A());
        break;
    case 1:
        return (new B());
        break;
    case 2:
        return (new C());
        break;
    
    default:
        break;
    }
    return (new A());
}