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

#define TESTED_NAMESPACE ft

template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo

template <typename T>
T	inc(T it, int n)
{
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}

#include <list>
#define T1 int
#define T2 int
#define _pair TESTED_NAMESPACE::pair
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator ft_iterator;
typedef TESTED_NAMESPACE::map<T1, T2>::const_iterator ft_const_iterator;

static int iter = 0;

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename MAP>
void	ft_bound(MAP &mp, const T1 &param)
{
	ft_iterator ite = mp.end(), it[2];
	_pair<ft_iterator, ft_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param);
	it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

template <typename MAP>
void	ft_const_bound(const MAP &mp, const T1 &param)
{
	ft_const_iterator ite = mp.end(), it[2];
	_pair<ft_const_iterator, ft_const_iterator> ft_range;

	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param);
	it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}

int		main_map()
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i + 1, (i + 1) * 3));
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);

	ft_const_bound(mp, -10);
	ft_const_bound(mp, 1);
	ft_const_bound(mp, 5);
	ft_const_bound(mp, 10);
	ft_const_bound(mp, 50);

	printSize(mp);

	mp.lower_bound(3)->second = 404;
	mp.upper_bound(7)->second = 842;
	ft_bound(mp, 5);
	ft_bound(mp, 7);

	printSize(mp);
	return (0);
}

// void main_map()
// {
// 	{
// 		typedef std::map<int, std::string> n_map;
// 		n_map myMap;
// 		myMap.insert(std::make_pair(1, "one"));
// 		myMap.insert(std::make_pair(2, "two"));
// 		myMap.insert(std::make_pair(3, "three"));
// 		for (n_map::iterator it = myMap.begin(); it != myMap.end(); it++)
// 		{
// 			std::cout << it->second << std::endl;
// 		}
// 	}
// 	std::cout << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
// 	{
// 		typedef ft::map<int, std::string> n_map;
// 		n_map myMap;
// 		myMap.insert(ft::make_pair(1, "one"));
// 		myMap.insert(ft::make_pair(2, "two"));
// 		myMap.insert(ft::make_pair(3, "three"));
// 		for (n_map::iterator it = myMap.begin(); it != myMap.end(); it++)
// 		{
// 			std::cout << it->second << std::endl;
// 		}
// 	}
// }

int main()
{
	// main_vector();
	main_map();
}
