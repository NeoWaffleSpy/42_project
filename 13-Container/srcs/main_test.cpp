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

// template <typename T>
// int get_max_depth(T ref, int depth = 0)
// {
// 	int d1 = depth;
// 	int d2 = depth;
// 	if (ref->_child[LEFT])
// 		d1 = get_max_depth(ref->_child[LEFT], depth + 1);
// 	if (ref->_child[RIGHT])
// 		d2 = get_max_depth(ref->_child[RIGHT], depth + 1);
// 	return ((d1 > d2) ? d1 : d2);
// }

// template <typename T>
// void print_tree_visual(T ref, int depth, std::ostream* os)
// {
// 	T new_stack;
// 	int space = 1;
// 	int half;
// 	int j = 0;

// 	for (int i = 0; i < depth; i++)
// 		space = (space * 2) + 1;
// 	half = (space - 1) / 2;
// 	for (int i = 0; i < half; i++)
// 		*os << " ";
// 	while ((int)ref.size() > j)
// 	{
// 		typename T::value_type n = ref.at(j);
// 		if (n == NULL)
// 		{
// 			*os << "□";
// 			new_stack.push_back(NULL);
// 			new_stack.push_back(NULL);
// 		}
// 		else
// 		{
// 			if (n->_color == C_RED)
// 				*os << RED;
// 			*os << n->_value << END;
// 			new_stack.push_back(n->_child[LEFT] ? n->_child[LEFT] : NULL);
// 			new_stack.push_back(n->_child[RIGHT] ? n->_child[RIGHT] : NULL);
// 		}
// 		j++;
// 		if ((int)ref.size() > j)
// 			for (int i = 0; i < space; i++)
// 				*os << (j%2 ? "-" : " ");
// 	}
// 	*os << std::endl;
// 	if (depth > 0)
// 		print_tree_visual(new_stack, depth - 1, os);
// }

// template <typename T>
// void print_tree(T& rbtree, std::ostream* os = &(std::cout))
// {
// 	if (!rbtree.root())
// 	{
// 		std::cout << GREEN << "Empty tree" << END << std::endl;
// 		return;
// 	}
// 	typedef typename T::node*	ref;
// 	if (false)
// 	{
// 		ft::vector<ref>	pile;
// 		pile.push_back(rbtree.root());
// 		*os << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
// 		print_tree_visual(pile, get_max_depth(rbtree.root()), os);
// 	}
// 	*os << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
// 	ref n = rbtree.begin();
// 	*os << MAGENTA;
// 	while (n)
// 	{
// 		*os << n->_value << " ";
// 		n = n->next();
// 	}
// 	*os << END << std::endl;
// 	// for (int i = 0; i < (int)rbtree.size(); i++)
// 	// 	*os << (((i / 10) % 2) ? GREEN : YELLOW) << (i % 10) << " ";
// 	// *os << END << std::endl;
// }

// void main_map()
// {
// 	typedef ft::Rbtree<int, ft::allow_double_class_tag>		rbtree;
// 	// typedef ft::Rbtree<int, ft::forbid_double_class_tag>		rbtree;
	
// 	{
// 		rbtree tree;
// 		try
// 		{
// 			tree.insert(4);
// 			tree.insert(3);
// 			tree.insert(2);
// 			tree.insert(1);
// 			tree.insert(5);
// 			tree.insert(6);
// 			print_tree(tree);
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << CYAN << e.what() << END << '\n';
// 		}
// 		try
// 		{
// 			tree.insert(1);
// 			tree.insert(2);
// 			tree.insert(3);
// 			tree.insert(4);
// 			tree.insert(5);
// 			tree.insert(6);
// 			print_tree(tree);
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << CYAN << e.what() << END << '\n';
// 		}
// 		try
// 		{
// 			tree.delete_node(tree.find(12));
// 			print_tree(tree);
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << CYAN << e.what() << END << '\n';
// 		}
// 		try
// 		{
// 			tree.delete_node(tree.find(5));
// 			print_tree(tree);
// 			tree.delete_node(tree.find(4));
// 			print_tree(tree);
// 			tree.delete_node(tree.find(4));
// 			print_tree(tree);
// 			tree.delete_node(tree.find(3));
// 			tree.delete_node(tree.find(3));
// 			print_tree(tree);
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << CYAN << e.what() << END << '\n';
// 		}
// 	}
// 	{
// 		std::stringstream buff;
// 		std::ostream err_str(buff.rdbuf());
// 		int node_nbr = -1;
// 		try
// 		{
// 			int	seed = time(NULL);
// 			// srand(1673123452);
// 			srand(seed);
// 			// std::cout << "Seed = " << seed << std::endl;
// 			rbtree tree;
// 			for (int i = 0; i < 50; i++)
// 			{
				
// 				std::cout << "\r insert number " << i << std::flush;
// 				err_str << tree.insert(rand() % 1000)->_value << " ";
// 			}
// 			std::cout << "\r";
// 			print_tree(tree);
// 			// std::cout << buff.str() << std::endl;
// 			for (int i = 0; i < 50; i++)
// 			{
// 				buff.str("");
// 				print_tree(tree, &err_str);
// 				node_nbr = tree[rand() % tree.size()]->_value;
// 				std::cout << "\rdelete " << (i + 1) << " of value " << node_nbr;
// 				tree.delete_node(tree.find(node_nbr));
// 			}
// 			std::cout << std::endl;
// 			print_tree(tree);
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cout << std::endl;
// 			std::cerr << RED << "Error while deleting the node " << node_nbr << ":\n" << END << buff.str() << CYAN << e.what() << END << '\n';
// 		}
// 	}
// }

#include <list>
#include "../include/common.hpp"

// #define T1 int
// #define T2 std::string
// typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;

// static int iter = 0;

// template <typename MAP>
// void	ft_erase(MAP &mp, const T1 param)
// {
// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	mp.erase(param);
// 	printSize(mp);
// }

// int		main_map(void)
// {
// 	TESTED_NAMESPACE::map<T1, T2> mp;


// 	// mp[5] = "Number 1";
// 	// mp[2] = "Number 2";
// 	// mp[1] = "Number 3";
// 	// mp[3] = "Number 4";
// 	// mp[6] = "Number 5";
	
// 	// printSize(mp);
// 	// ft_erase(mp, 2);
// 	mp[42] = "lol";

// 	mp[50] = "mdr";
// 	mp[25] = "funny";

// 	mp[46] = "bunny";
// 	mp[21] = "fizz";
// 	mp[30] = "buzz";
// 	mp[55] = "fuzzy";

// 	mp[18] = "bee";
// 	mp[23] = "coconut";
// 	mp[28] = "diary";
// 	mp[35] = "fiesta";
// 	mp[44] = "hello";
// 	mp[48] = "world";
// 	mp[53] = "this is a test";
// 	mp[80] = "hey";

// 	mp[12] = "no";
// 	mp[20] = "idea";
// 	mp[22] = "123";
// 	mp[24] = "345";
// 	mp[27] = "27";
// 	mp[29] = "29";
// 	mp[33] = "33";
// 	mp[38] = "38";

// 	mp[43] = "1";
// 	mp[45] = "2";
// 	mp[47] = "3";
// 	mp[49] = "4";
// 	mp[51] = "5";
// 	mp[54] = "6";
// 	mp[60] = "7";
// 	mp[90] = "8";

// 	printSize(mp);

// 	ft_erase(mp, 25); // right != NULL; left != NULL
// 	ft_erase(mp, 55); // right != NULL; left != NULL

// 	ft_erase(mp, 24); // right != NULL; left != NULL
// 	ft_erase(mp, 54); // right != NULL; left != NULL

// 	ft_erase(mp, 22); // right == NULL; left == NULL
// 	ft_erase(mp, 51); // right == NULL; left == NULL

// 	ft_erase(mp, 21); // right == NULL; left != NULL
// 	ft_erase(mp, 53); // right != NULL; left == NULL
// 	ft_erase(mp, 20); // right == NULL; left != NULL
// 	ft_erase(mp, 23); // right != NULL; left != NULL
// 	ft_erase(mp, 42); // right != NULL; left != NULL; parent == NULL
// 	ft_erase(mp, 38); // right != NULL; left != NULL; parent == NULL
// 	ft_erase(mp, 35); // right != NULL; left != NULL; parent == NULL
// 	ft_erase(mp, 33); // right != NULL; left != NULL; parent == NULL

// 	return (0);
// }
#define T1 int
#define T2 std::string
typedef _pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	std::cout << "ret: " << mp.erase(param) << std::endl;
	printSize(mp);
}

int		main_map(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 6;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);

	for (int i = 2; i < 4; ++i)
		ft_erase(mp, i);

	ft_erase(mp, mp.begin()->first);
	ft_erase(mp, (--mp.end())->first);

	mp[-1] = "Hello";
	mp[10] = "Hi there";
	mp[10] = "Hi there";
	printSize(mp);

	ft_erase(mp, 0);
	// ft_erase(mp, 1);

	return (0);
}

int main()
{
	// main_vector();
	main_map();
}
