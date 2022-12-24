/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:50:30 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/29 21:50:31 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <stack>

template< typename T > 
class MutantStack : public std::stack<T>
{
    public:

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        // Coplien
        MutantStack() : std::stack<T>() {};
        MutantStack(const MutantStack& copy) : std::stack<T>(copy){};
        virtual ~MutantStack() {};

        MutantStack &operator=(const MutantStack &op)
        {
            if (this == &op)
                return (*this);
            std::stack<T>::operator=(op);
            return (*this);
        };

        iterator begin()
        {
            return (std::stack<T>::c.begin());
        }
        const_iterator begin() const
        {
            return (std::stack<T>::c.begin());
        }
        iterator end()
        {
            return (std::stack<T>::c.end());
        }
        const_iterator end() const
        {
            return (std::stack<T>::c.end());
        }
        reverse_iterator rbegin()
        {
            return (std::stack<T>::c.rbegin());
        }
        const_reverse_iterator rbegin() const
        {
            return (std::stack<T>::c.rbegin());
        }
        reverse_iterator rend()
        {
            return (std::stack<T>::c.rend());
        }
        const_reverse_iterator rend() const
        {
            return (std::stack<T>::c.rend());
        } 
};

#endif