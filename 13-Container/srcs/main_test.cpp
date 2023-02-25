#include "../include/vector.hpp"
#include "../include/map.hpp"
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iterator>
#include <stdlib.h>
#include <time.h>

#define PRINT_V 1

#define FILE_TO_READ "./Makefile"

#define COLOR_TITLE	BLUE
#define COLOR_FT	MAGENTA
#define COLOR_STD	CYAN

template <typename T_vector>
T_vector	create_vec()
{
	typedef std::istream_iterator<char>	is_iterator;
	std::ifstream		file;
	is_iterator			my_it;

	file.open(FILE_TO_READ);
	my_it = is_iterator(file);
	T_vector vec(my_it, is_iterator());
	file.close();
	return (vec);
}

template <typename T_iter>
void	print_v(T_iter it, T_iter end)
{
	if (!PRINT_V)
		return;
	for (; it != end; it++)
		std::cout << *it;
	std::cout << std::endl;
}

template <typename T_vector, typename T_iter>
void	exec_test(std::string msg)
{
	std::cout << msg << std::endl;
	T_vector vec = create_vec<T_vector>();
	T_iter it(vec.begin());
	T_iter end(vec.end());

	size_t x = end - it;
	std::cout << msg << " len = " << x << " : " << std::endl;

	print_v<T_iter>(it, end);

	it += (x / 2);
	std::cout << "split in half : " << it - vec.begin() << std::endl;
}

template <typename T_vector, typename T_iter>
void	exec_rev_test(std::string msg)
{
	std::cout << msg << std::endl;
	T_vector vec = create_vec<T_vector>();
	T_iter it(vec.rbegin());
	T_iter end(vec.rend());

	size_t x = end - it;
	std::cout << msg << " len = " << x << " : " << std::endl;

	print_v<T_iter>(it, end);

	it += (x / 2);
	std::cout << "split in half : " << it - vec.rbegin() << std::endl;
}

template <typename T_vector>
void	exec_compare(std::string msg)
{
	std::cout << msg << std::endl;
	T_vector ref = create_vec<T_vector>();
	T_vector vec(ref);
	if (ref == vec)
		std::cout << "PASS ref == vec" << std::endl;
	if (ref < vec)
		std::cout << "PASS ref < vec" << std::endl;
	if (ref <= vec)
		std::cout << "PASS ref <= vec" << std::endl;
	if (ref > vec)
		std::cout << "PASS ref > vec" << std::endl;
	if (ref >= vec)
		std::cout << "PASS ref >= vec" << std::endl;
	if (ref != vec)
		std::cout << "PASS ref != vec" << std::endl;
	if (!(ref < vec))
		std::cout << "PASS !(ref < vec)" << std::endl;
	
	std::cout << "Call to pop_back()" << std::endl;
	vec.pop_back();

	if (ref == vec)
		std::cout << "PASS ref == vec" << std::endl;
	if (ref < vec)
		std::cout << "PASS ref < vec" << std::endl;
	if (ref <= vec)
		std::cout << "PASS ref <= vec" << std::endl;
	if (ref > vec)
		std::cout << "PASS ref > vec" << std::endl;
	if (ref >= vec)
		std::cout << "PASS ref >= vec" << std::endl;
	if (ref != vec)
		std::cout << "PASS ref != vec" << std::endl;
	if (!(ref < vec))
		std::cout << "PASS !(ref < vec)" << std::endl;
}

int main_vector()
{
	typedef	char														T;

	{
		typedef ft::vector<T>::iterator									ft_it;
		typedef std::vector<T>::iterator								std_it;

		std::cout << std::endl << COLOR_TITLE << "[TEST DES ITERATORS DE VECTEURS]" << COLOR_FT << std::endl;
		exec_test<ft::vector<T>, ft_it>									("ft::vector");
		std::cout << COLOR_STD;
		exec_test<std::vector<T>, std_it>								("std::vector");
		std::cout << END;
	}
	{
		typedef ft::vector<T>::reverse_iterator							ft_rev_it;
		typedef std::vector<T>::reverse_iterator						std_rev_it;

		std::cout << std::endl << COLOR_TITLE << "[TEST DES REVERSE ITERATORS DE VECTEURS]" << COLOR_FT << std::endl;
		exec_rev_test<ft::vector<T>, ft_rev_it>							("ft::rev_vector");
		std::cout << COLOR_STD;
		exec_rev_test<std::vector<T>, std_rev_it>						("std::rev_vector");
		std::cout << END;
	}
	{
		typedef ft::vector<T>::const_reverse_iterator					ft_const_rev_it;
		typedef std::vector<T>::const_reverse_iterator					std_const_rev_it;

		std::cout << std::endl << COLOR_TITLE << "[TEST DES CONST REVERSE ITERATORS DE VECTEURS]" << COLOR_FT << std::endl;
		exec_rev_test<ft::vector<T>, ft_const_rev_it>					("ft::const_rev_vector");
		std::cout << COLOR_STD;
		exec_rev_test<std::vector<T>, std_const_rev_it>					("std::const_rev_vector");
		std::cout << END;
	}
	{
		std::cout << std::endl << COLOR_TITLE << "[TEST DES COMPARAISONS DE VECTEURS]" << COLOR_FT << std::endl;
		exec_compare<ft::vector<T> >									("Lexicographical compare on ft::vector");
		std::cout << COLOR_STD;
		exec_compare<std::vector<T> >									("Lexicographical compare on std::vector");
		std::cout << END;
	}

	{
		std::cout << std::endl << COLOR_TITLE << "[TEST DE VECTEURS DANS VECTEURS]" << COLOR_FT << std::endl;
		ft::vector<ft::vector<int> >	vec2;
		for (int i = 0; i < 20; i++)
		{
			ft::vector<int>	j(2, i);
			vec2.push_back(j);
		}
		for (size_t i = 0; i < vec2.size(); i++)
			std::cout << vec2[i].back() << ' ';
		std::cout << END << std::endl;
	}
	{
		std::cout << COLOR_STD;
		ft::vector<ft::vector<int> >	vec2;
		for (int i = 0; i < 20; i++)
		{
			ft::vector<int>	j(2, i);
			vec2.push_back(j);
		}
		for (size_t i = 0; i < vec2.size(); i++)
			std::cout << vec2[i].back() << ' ';
		std::cout << END << std::endl;
	}

	/* CE TEST EST CENSE ECHOUER ET FAIRE UN INVALID READ
	ft::vector<std::string>    v2(8);
    ft::vector<std::string>::iterator    it2 = v2.begin();

    v2.push_back("AAAAAAAAAA");
    std::cout << (*it2) << std::endl;
	*/
	return 0;
}

#define T1 int
#define T2 int

/* Ce test est cense faie une erreur de compilation */

/*
int		main_map(void)
{
	ft::map<T1, T2> const mp;
	ft::map<T1, T2>::iterator it = mp.begin(); // <-- error expected

	(void)it;
	return (0);
}
*/

#define REF_SIZE 255
#define NSP ft

void		main_map(void)
{
	NSP::map<T1, T2> mp;
	for (int i = 0; i < REF_SIZE; i++)
		mp.insert(NSP::make_pair(i, 0));
	for (size_t i = 0; i < REF_SIZE / 10; i++)
	{
		std::cout << MAGENTA << "\rIter " << i << END << std::flush;
		if (i % 3 == 0)
			mp.erase(mp.begin());
		else if (i % 3 == 1)
			mp.erase((++(++mp.begin())));
		else
			mp.erase((--(--mp.end())));
	}
	std::cout << std::endl;
}

int main()
{
	// main_vector();
	main_map();
}
