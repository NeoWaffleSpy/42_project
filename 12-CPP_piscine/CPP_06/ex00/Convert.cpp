/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:24:41 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/23 16:24:42 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert()
{}

Convert::Convert(Convert& copy)
{
    *this = copy;
}

Convert::~Convert()
{}

Convert &Convert::operator=(Convert &src)
{
    if (this == &src)
        return *this;

    return *this;
}

int    Convert::isFloat(std::string val)
{
    int i;
    i = 0;
    if (val[i] == '-')
        i++;
    for (; i < (int)val.length(); i++)
    {
        if (!isdigit(val[i]))
        {
            if (val[i] != '.')
                return 0;
            break;
        } 
    }
    i++;
    if (!isdigit(val[i]))
        return 0;
    for (; i < (int)val.length(); i++)
    {
        if (!isdigit(val[i]))
        {
            if (val[i] != 'f')
                return 0;
            break;
        } 
    }
    if (val[i + 1])
        return 0;
    double num = strtod(val.c_str(), NULL);
    if (num <= std::numeric_limits<float>::min() ||
        num >= std::numeric_limits<float>::max() ||
        errno == ERANGE)
    {
        return 8;
    }
    return 1;
}

int    Convert::isDouble(std::string val)
{
    int i;
    i = 0;
    if (val[i] == '-')
        i++;
    for (; i < (int)val.length(); i++)
    {
        if (!isdigit(val[i]))
        {
            if (val[i] != '.')
                return 0;
            break;
        } 
    }
    i++;
    if (!isdigit(val[i]))
        return 0;
    for (; i < (int)val.length(); i++)
        if (!isdigit(val[i]))
            return 0;

    double num = strtod(val.c_str(), NULL);
    (void)num;
    if (errno == ERANGE)
    {
        return 4;
    }
    return 1;
}

int    Convert::isChar(std::string val)
{
    if (val.length() > 1 || !isalpha(val[0]))
        return 0;
    return 1;
}

int    Convert::isInt(std::string val)
{
    int i;
    i = 0;
    if (val[i] == '-')
        i++;
    for (; i < (int)val.length(); i++)
    {
        if (!isdigit(val[i]))
            return 0;
    }

    long num = strtol(val.c_str(), 0, 10);
    if (((num == std::numeric_limits<long>::min() ||
        num == std::numeric_limits<long>::max()) &&
        errno == ERANGE) ||
        num < std::numeric_limits<int>::min() ||
        num > std::numeric_limits<int>::max())
    {
        return 2;
    }
    return 1;
}

int Convert::getType(std::string val)
{
    // std::cout << std::fixed;
    if (val.compare("nan") == 0 || val.compare("+inf") == 0 ||
		val.compare("-inf") == 0 || val.compare("+inff") == 0 ||
		val.compare("-inff") == 0)
        return 5;
    if ((int)val.find('f') != -1)
        return (isFloat(val) * 1);
    if ((int)val.find('.') != -1)
        return (isDouble(val) * 2);
    if (isalpha(val[0]))
        return (isChar(val) * 3);
    return (isInt(val) * 4);
}

void    Convert::printDouble(double val)
{
    std::cout << std::setw(10) << std::right << "char : ";
    if (val < 32 || val > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

    std::cout << std::setw(10) << std::right << "int : ";
    if (val > (double)std::numeric_limits<int>::max() || val < (double)std::numeric_limits<int>::min())
        std::cout << "overflow" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;

    std::cout << std::setw(10) << std::right << "float : ";
    std::cout << static_cast<float>(val) << "f" << std::endl;

    std::cout << std::setw(10) << std::right << "double : ";
    std::cout << static_cast<double>(val) << std::endl;
}

void    Convert::printChar(char val)
{
    std::cout << std::setw(10) << std::right << "char : ";
    std::cout << "'" << val << "'" << std::endl;

    std::cout << std::setw(10) << std::right << "int : ";
    std::cout << static_cast<int>(val) << std::endl;

    std::cout << std::setw(10) << std::right << "float : ";
    std::cout << static_cast<float>(val) << "f" << std::endl;

    std::cout << std::setw(10) << std::right << "double : ";
    std::cout << static_cast<double>(val) << std::endl;
}

void    Convert::printInt(int val)
{
    std::cout << std::setw(10) << std::right << "char : ";
    if (val < 32 || val > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;

    std::cout << std::setw(10) << std::right << "int : ";
    std::cout << val << std::endl;

    std::cout << std::setw(10) << std::right << "float : ";
    std::cout << static_cast<float>(val) << "f" << std::endl;

    std::cout << std::setw(10) << std::right << "double : ";
    std::cout << static_cast<double>(val) << std::endl;
}

void    Convert::printNan(std::string str)
{
    std::cout << std::setw(10) << std::right << "char : ";
    std::cout << "impossible" << std::endl;

    std::cout << std::setw(10) << std::right << "int : ";
    std::cout << "impossible" << std::endl;

    std::cout << std::setw(10) << std::right << "float : ";
    if (str[0] == '+')
        std::cout << "+inff" << std::endl;
    else if (str[0] == '-')
        std::cout << "-inff" << std::endl;
    else
        std::cout << "nanf" << std::endl;
    
    std::cout << std::setw(10) << std::right << "double : ";
    if (str[0] == '+')
        std::cout << "+inf" << std::endl;
    else if (str[0] == '-')
        std::cout << "-inf" << std::endl;
    else
        std::cout << "nan" << std::endl;
}