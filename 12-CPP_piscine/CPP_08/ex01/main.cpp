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

#include "Span.hpp"

int	main( void )
{
	Span	span1(5);

	srand(time(NULL));
	try
	{
		span1.addNumber(4);
		std::cout << "\nspan1:" << span1 << std::endl;
		span1.addNumber(7);
		std::cout << "\nspan1:" << span1 << std::endl;
		span1.addNumber(2);
		std::cout << "\nspan1:" << span1 << std::endl;
		span1.addNumber(6);
		std::cout << "\nspan1:" << span1 << std::endl;
		span1.addNumber(25);
		std::cout << "\nspan1:" << span1 << std::endl;
		span1.addNumber(4);
	}
	catch (std::logic_error &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << span1 << std::endl;


	Span	span2(5000);
	/* Span	span2(500); */

	span2.addNumber(3);
	span2.randomFill();
		std::cout << "\nspan2:" << span2 << std::endl;
}