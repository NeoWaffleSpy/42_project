#include "include/vector.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <stdlib.h>
#include <time.h>

int main()
{
	typedef std::istream_iterator<char>	is_iterator;
	std::ifstream		file;
	is_iterator			my_it;

	file.open("./Makefile");
	my_it = is_iterator(file);
	ft::vector<char>	vec(my_it, is_iterator());
	std::vector<char>	vec2(my_it, is_iterator());

	ft::reverse_iterator<ft::random_access_iterator<char> > it = vec.rbegin();
	ft::reverse_iterator<ft::random_access_iterator<char> > end = vec.rend();
	std::reverse_iterator<std::vector<char>::iterator> it2 = vec2.rbegin();
	std::reverse_iterator<std::vector<char>::iterator> end2 = vec2.rend();
	size_t x = end - it;
	size_t x2 = end2 - it2;
	std::cout << "ft::vector = " << x << "bases :" << it.base2() << " " << end.base2() << std::endl;
	std::cout << "std::vector = " << x2 << std::endl;
	// std::cout << "vector len = " << x << " : ";
	// for (; it != end; it++)
	// 	std::cout << *it;
	// std::cout << std::endl;
	file.close();
	file.open("./Makefile");
	my_it = is_iterator(file);
	std::cout << "is equal : " << ft::equal(my_it, is_iterator(), vec.begin(), vec.end()) << std::endl;
	file.close();
	return 0;
}
