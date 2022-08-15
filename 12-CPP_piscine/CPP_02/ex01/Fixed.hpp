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
		Fixed(Fixed& copy);
		~Fixed();
		Fixed &operator=(Fixed &src);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
