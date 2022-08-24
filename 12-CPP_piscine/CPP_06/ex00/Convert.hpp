/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:24:45 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/23 16:24:45 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <string>

class Convert
{
private:
    static bool isFloat(std::string val);
    static bool isDouble(std::string val);
    static bool isChar(std::string val);
    static bool isInt(std::string val);

public:
    Convert();
    Convert(Convert& copy);
    ~Convert();
    Convert &operator=(Convert &src);

    static int  getType(std::string val);
    static void printFloat(float val);
    static void printDouble(double val);
    static void printChar(char val);
    static void printInt(int val);
    static void printNan(std::string str);
};

#endif