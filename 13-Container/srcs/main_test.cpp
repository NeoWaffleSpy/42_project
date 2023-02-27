#include "../include/vector.hpp"
#include "../include/map.hpp"
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iterator>
#include <stdlib.h>
#include <time.h>
#include <list>

#define PRINT_V 1

#define FILE_TO_READ "./Makefile"

#define COLOR_TITLE	BLUE
#define COLOR_FT	MAGENTA
#define COLOR_STD	CYAN

# if !defined(USING_STD)
#  define TESTED_NAMESPACE ft
# else
#  define TESTED_NAMESPACE std
# endif


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
		typedef TESTED_NAMESPACE::vector<T>::iterator									ft_it;

		std::cout << std::endl << COLOR_TITLE << "[TEST DES ITERATORS DE VECTEURS]" << COLOR_FT << std::endl;
		exec_test<TESTED_NAMESPACE::vector<T>, ft_it>									("vector");
		std::cout << END;
	}
	{
		typedef TESTED_NAMESPACE::vector<T>::reverse_iterator							ft_rev_it;

		std::cout << std::endl << COLOR_TITLE << "[TEST DES REVERSE ITERATORS DE VECTEURS]" << COLOR_FT << std::endl;
		exec_rev_test<TESTED_NAMESPACE::vector<T>, ft_rev_it>							("rev_vector");
		std::cout << END;
	}
	{
		typedef ft::vector<T>::const_reverse_iterator					ft_const_rev_it;

		std::cout << std::endl << COLOR_TITLE << "[TEST DES CONST REVERSE ITERATORS DE VECTEURS]" << COLOR_FT << std::endl;
		exec_rev_test<TESTED_NAMESPACE::vector<T>, ft_const_rev_it>					("const_rev_vector");
		std::cout << END;
	}
	{
		std::cout << std::endl << COLOR_TITLE << "[TEST DES COMPARAISONS DE VECTEURS]" << COLOR_FT << std::endl;
		exec_compare<TESTED_NAMESPACE::vector<T> >									("Lexicographical compare on vector");
		std::cout << END;
	}

	{
		std::cout << std::endl << COLOR_TITLE << "[TEST DE VECTEURS DANS VECTEURS]" << COLOR_FT << std::endl;
		TESTED_NAMESPACE::vector<ft::vector<int> >	vec2;
		for (int i = 0; i < 20; i++)
		{
			TESTED_NAMESPACE::vector<int>	j(2, i);
			vec2.push_back(j);
		}
		for (size_t i = 0; i < vec2.size(); i++)
			std::cout << vec2[i].back() << ' ';
		std::cout << END << std::endl;
	}
	std::cout << END << std::endl;

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

#define REF_SIZE 255

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << COLOR_FT <<  "- [" << it->first << ", " << it->second << "]" << END << std::endl;
	}
	std::cout << COLOR_TITLE << "###############################################" << END << std::endl;
}

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	mp.erase(param, param2);
	printSize(mp);
}

template <typename MAP, typename const_it>
void	ft_comp(const MAP &mp, const const_it &it1, const const_it &it2)
{
	bool res[2];

	res[0] = mp.key_comp()(it1->first, it2->first);
	res[1] = mp.value_comp()(*it1, *it2);
	std::cout << "with " << COLOR_STD << "[" << it1->first << " and " << it2->first << "]" << END <<": ";
	std::cout << COLOR_FT << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << END << std::endl;
}

void		main_map(void)
{
	{
		TESTED_NAMESPACE::map<char, int> mp;
		for (int i = 0; i < REF_SIZE; i++)
			mp.insert(TESTED_NAMESPACE::make_pair(i, 0));
		for (size_t i = 0; i < REF_SIZE / 10; i++)
		{
			if (i % 3 == 0)
				mp.erase(mp.begin());
			else if (i % 3 == 1)
				mp.erase((++(++mp.begin())));
			else
				mp.erase((--(--mp.end())));
		}
	}
	{
		typedef TESTED_NAMESPACE::map<char, double> _map;
		typedef _map::const_iterator const_it;
		_map	mp;

		mp['a'] = 2.3;
		mp['b'] = 1.4;
		mp['c'] = 0.3;
		mp['d'] = 4.2;
		printSize(mp);

		for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
			for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
				ft_comp(mp, it1, it2);

		printSize(mp);
	}
	{
		typedef TESTED_NAMESPACE::pair<const int, std::string> T3;
		std::list<T3> lst;
		unsigned int lst_size = 10;
		for (unsigned int i = 0; i < lst_size; ++i)
			lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
		TESTED_NAMESPACE::map<int, std::string> mp(lst.begin(), lst.end());
		printSize(mp);

		ft_erase(mp, ++mp.begin());

		ft_erase(mp, mp.begin());
		ft_erase(mp, --mp.end());

		ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
		ft_erase(mp, --(--(--mp.end())), --mp.end());

		mp[10] = "Hello";
		mp[11] = "Hi there";
		printSize(mp);
		ft_erase(mp, --(--(--mp.end())), mp.end());

		mp[12] = "ONE";
		mp[13] = "TWO";
		mp[14] = "THREE";
		mp[15] = "FOUR";
		printSize(mp);
		ft_erase(mp, mp.begin(), mp.end());
	}
	/*	 Ce test est cense faie une erreur de compilation
	{
		ft::map<T1, T2> const mp;
		ft::map<T1, T2>::iterator it = mp.begin(); // <-- error expected

		(void)it;
		return (0);
	}
	*/
}

int main()
{
	main_vector();
	main_map();
}
