#include "../include/vector.hpp"
#include "../include/RBTree/rbtree.hpp"
#include <vector>
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

template <typename T>
int get_max_depth(T ref, int depth = 0)
{
	int d1 = depth;
	int d2 = depth;
	if (ref->_child[LEFT])
		d1 = get_max_depth(ref->_child[LEFT], depth + 1);
	if (ref->_child[RIGHT])
		d2 = get_max_depth(ref->_child[RIGHT], depth + 1);
	return ((d1 > d2) ? d1 : d2);
}

template <typename T>
void print_tree_visual(T ref, int depth)
{
	T new_stack;
	int space = 1;
	int half;
	int j = 0;

	for (int i = 0; i < depth; i++)
		space = (space * 2) + 1;
	half = (space - 1) / 2;
	for (int i = 0; i < half; i++)
		std::cout << " ";
	while ((int)ref.size() > j)
	{
		typename T::value_type n = ref.at(j);
		if (n == NULL)
		{
			std::cout << "#";
			new_stack.push_back(NULL);
			new_stack.push_back(NULL);
		}
		else
		{
			if (n->_color == C_RED)
				std::cout << RED;
			std::cout << n->_value << END;
			new_stack.push_back(n->_child[LEFT] ? n->_child[LEFT] : NULL);
			new_stack.push_back(n->_child[RIGHT] ? n->_child[RIGHT] : NULL);
		}
		j++;
		if ((int)ref.size() > j)
			for (int i = 0; i < space; i++)
				std::cout << (j%2 ? "-" : " ");
	}
	std::cout << std::endl;
	if (depth > 0)
		print_tree_visual(new_stack, depth - 1);
}

template <typename T>
void print_tree(T& rbtree)
{
	typedef typename T::node*	ref;
	{
		ft::vector<ref>	pile;
		pile.push_back(rbtree.root());
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
		print_tree_visual(pile, get_max_depth(rbtree.root()));
		std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	}
	ref n = rbtree.begin();
	while (n)
	{
		std::cout << MAGENTA << n->_value << " ";
		n = n->next();
	}
	std::cout << END << std::endl;
}

void main_map()
{
	typedef ft::Rbtree<int, ft::allow_double_class_tag>		rbtree;
	// typedef ft::Rbtree<int, ft::forbid_double_class_tag>		rbtree;

	{
		rbtree tree;
		try
		{
			tree.insert(4);
			tree.insert(3);
			tree.insert(2);
			tree.insert(1);
			tree.insert(5);
			tree.insert(6);
			print_tree(tree);
		}
		catch(const std::exception& e)
		{
			std::cerr << CYAN << e.what() << END << '\n';
		}
		try
		{
			tree.insert(1);
			tree.insert(2);
			tree.insert(3);
			tree.insert(4);
			tree.insert(5);
			tree.insert(6);
			print_tree(tree);
		}
		catch(const std::exception& e)
		{
			std::cerr << CYAN << e.what() << END << '\n';
		}
		try
		{
			tree.delete_node(tree.find(5));
			print_tree(tree);
		}
		catch(const std::exception& e)
		{
			std::cerr << CYAN << e.what() << END << '\n';
		}
	}
	// {
	// 	rbtree tree;
	// 	tree.insert(0);
	// 	tree.insert(4);
	// 	tree.insert(3);
	// 	tree.insert(1);
	// 	tree.insert(8);
	// 	tree.insert(5);
	// 	tree.insert(6);
	// 	tree.insert(5);
	// 	tree.insert(5);
	// 	tree.insert(8);
	// 	print_tree(tree);
	// }
	// {
	// 	srand(time(NULL));
	// 	rbtree tree;
	// 	for (int i = 0; i < 50; i++)
	// 	{
	// 		tree.insert(rand() % 10);
	// 	}
	// 	print_tree(tree);
	// }
}

int main()
{
	// main_vector();
	main_map();
}
