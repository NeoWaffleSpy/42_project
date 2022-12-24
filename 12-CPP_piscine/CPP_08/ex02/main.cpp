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

# include "MutantStack.hpp"
# include <iostream>
# include <list>

int main(){

    std::cout << "MUTANTSTACK" << std::endl;

    MutantStack<int>    mstack;

    mstack.push(5);
    mstack.push(99);

    std::cout << "TOP : " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "SIZE : " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while(it != ite){
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\nMUTANTSTACK reverse" << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    ++rit;
    --rit;

    while(rit != rite){
        std::cout << *rit << std::endl;
        ++rit;
    }
    return 0;
}