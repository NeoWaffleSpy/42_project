/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 06:46:44 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/15 06:46:46 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cmath>

class Fixed
{
	private:
		int	        		_fp_value;
		static int const	_fract_bits;

	public:
		Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed &operator=(const Fixed &src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(Fixed fix) const;
		bool	operator>=(Fixed fix) const;
		bool	operator<(Fixed fix) const;
		bool	operator<=(Fixed fix) const;
		bool	operator==(Fixed fix) const;
		bool	operator!=(Fixed fix) const;

		float	operator+(Fixed fix) const;
		float	operator-(Fixed fix) const;
		float	operator*(Fixed fix) const;
		float	operator/(Fixed fix) const;

		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed		&min(Fixed &first, Fixed &second);
		static Fixed		&max(Fixed &first, Fixed &second);
		static const Fixed	&min(const Fixed &first, const Fixed &second);
		static const Fixed	&max(const Fixed &first, const Fixed &second);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif
