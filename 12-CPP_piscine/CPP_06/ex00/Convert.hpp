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
# include <climits>
# include <errno.h>

class Convert
{
private:
    static int isFloat(std::string val);
    static int isDouble(std::string val);
    static int isChar(std::string val);
    static int isInt(std::string val);

public:
    Convert();
    Convert(Convert& copy);
    ~Convert();
    Convert &operator=(Convert &src);

    static int  getType(std::string val);
    static void printDouble(double val);
    static void printChar(char val);
    static void printInt(int val);
    static void printNan(std::string str);
};

#endif