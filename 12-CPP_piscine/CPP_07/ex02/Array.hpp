/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:04:32 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/26 20:04:33 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <iomanip>
# include <string>

template <typename T>
class Array
{
private:
    T   *array;
    int size_array;

public:
    Array(int n = 0): array(NULL), size_array(n)
    {
        std::cout << "Array Default Constructor called on array size = " << this->size_array << std::endl;
		if (n < 0)
			throw std::exception();
        if (n > 0)
            this->array = new T[n];

    }
    Array(Array& copy)
    {
        std::cout << "Array Copy Constructor called" << std::endl;
        *this = copy;
        if (copy.size() < 1)
            this->array = NULL;
        else
        {
            this->size_array = copy.size();
            this->array = new T[this->size_array];
            for (int i = 0; i < this->size_array; i++)
                this->array[i] = copy[i];
        }
    }
    ~Array()
    {
        std::cout << "Array Destructor called" << std::endl;
        if (this->array)
            delete [] this->array;
    }
    Array &operator=(Array &copy)
    {
        std::cout << "Array Assignation Constructor called" << std::endl;
        if (this == &copy)
            return *this;

        if (copy.size() < 1)
            this->array = NULL;
        else
        {
            this->size_array = copy.size();
            this->array = new T[this->size_array];
            for (int i = 0; i < this->size_array; i++)
                this->array[i] = copy[i];
        }
        return *this;
    }

    T &operator[](int i)
    {
        if (i < 0 || i >= this->size_array)
            throw std::exception();
        return (this->array[i]);
    }

    int size()
    {
        return this->size_array;
    }
};

#endif