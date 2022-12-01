#include "../include/vector.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <stdlib.h>
#include <time.h>
#include "../unit_tests/hdrs/vector_utils.hpp"

#define FILE_TO_READ "./Makefile"

		// for (; it != end; it++)
		// 	std::cout << *it;
		// std::cout << std::endl;

void	tests()
{
	typedef	int													T;
	typedef ft::reverse_iterator<ft::random_access_iterator<T> >	ft_rev_it;
	typedef std::reverse_iterator<std::vector<T>::iterator>			std_rev_it;
	std::vector<T> ref;
	for (int i = 0; i < REF_SIZE; i++)
		ref.push_back(rand());
	ft::vector<T>	vec(ref.begin(), ref.end());

	std_rev_it	r_ref_tmp = ++(++(--(++(++ref.rbegin()))));
	ft_rev_it		r_tmp = ++(++(--(++(++vec.rbegin()))));

	r_ref_tmp = ref.rbegin() + REF_SIZE / 2;
	r_tmp = vec.rbegin() + REF_SIZE / 2;

	std::cout << "Std vector " << *r_ref_tmp << std::endl << *ref.rbegin() << std::endl;
	std::cout << "Our vector " << *r_tmp << std::endl << *vec.rbegin() << std::endl;

	r_ref_tmp = r_ref_tmp + 15;
	r_tmp = r_tmp + 15;
	std::cout << "Std vector " << *r_ref_tmp << std::endl;
	std::cout << "Our vector " << *r_tmp << std::endl;
	if (*r_ref_tmp == *r_tmp)
		std::cout << "oui" << std::endl;

	r_ref_tmp = 30 + r_ref_tmp;
	r_tmp = 30 + r_tmp;
	std::cout << "Std vector " << *r_ref_tmp << std::endl;
	std::cout << "Our vector " << *r_tmp << std::endl;
	if (*r_ref_tmp == *r_tmp)
		std::cout << "oui" << std::endl;

	r_ref_tmp = r_ref_tmp - 5;
	r_tmp = r_tmp - 5;
	std::cout << "Std vector " << *r_ref_tmp << std::endl;
	std::cout << "Our vector " << *r_tmp << std::endl;
	if (*r_ref_tmp == *r_tmp)
		std::cout << "oui" << std::endl;

	size_t r_ref_diff = r_ref_tmp - ref.rbegin();
	size_t r_diff = r_tmp - vec.rbegin();
	std::cout << "n1 = " << r_ref_diff << " - n2 = " << r_diff << std::endl;
	if (r_ref_diff == r_diff) // it - it2
		std::cout << "oui" << std::endl;
	else
		std::cout << "non" << std::endl;
}

template <typename T_vector, typename T_iter>
void	exec_test(std::string msg)
{
	typedef std::istream_iterator<char>	is_iterator;
	std::ifstream		file;
	is_iterator			my_it;

	std::cout << msg << std::endl;
	file.open(FILE_TO_READ);
	my_it = is_iterator(file);

	T_vector vec(my_it, is_iterator());
	T_iter it(vec.begin());
	T_iter end(vec.end());

	size_t x = end - it;
	std::cout << msg << " len = " << x << " : " << std::endl;
	it += (x/2);
	std::cout << "split in half : " << it - vec.begin() << std::endl << std::endl;
	file.close();
}

template <typename T_vector, typename T_iter>
void	exec_rev_test(std::string msg)
{
	typedef std::istream_iterator<char>	is_iterator;
	std::ifstream		file;
	is_iterator			my_it;

	std::cout << msg << std::endl;
	file.open(FILE_TO_READ);
	my_it = is_iterator(file);

	T_vector vec(my_it, is_iterator());
	T_iter it(vec.rbegin());
	T_iter end(vec.rend());

	size_t x = end - it;
	std::cout << msg << " len = " << x << " : " << std::endl;

	for (; it != end; it++)
		std::cout << *it;
	std::cout << std::endl;
	
	it += x + 1;
	std::cout << "split in half : " << it - vec.rbegin() << std::endl << std::endl;
	file.close();
}

template <typename t_vec>
void	exec_compare(std::string msg)
{
	typedef std::istream_iterator<char>	is_iterator;
	std::ifstream		file;
	is_iterator			my_it;

	file.open(FILE_TO_READ);
	my_it = is_iterator(file);

	std::cout << msg << std::endl;
	t_vec ref(my_it, is_iterator());
	std::cout << "Pass 1" << std::endl;
	t_vec vec(ref);
	std::cout << "Pass 2" << std::endl;
	if (ref == vec)
		std::cout << "PASS ref == vec" << std::endl;
	if (ref <= vec)
		std::cout << "PASS ref <= vec" << std::endl;
	if (ref >= vec)
		std::cout << "PASS ref >= vec" << std::endl;
	vec.pop_back();
	if (ref != vec)
		std::cout << "PASS ref != vec" << std::endl;
	if (!(ref < vec))
		std::cout << "PASS !(ref < vec)" << std::endl;
	
	file.close();
}

int main()
{
	typedef	char													T;

	// typedef ft::random_access_iterator<T>							ft_it;
	// typedef std::vector<T>::iterator								std_it;
	// typedef ft::reverse_iterator<ft::random_access_iterator<T> >	ft_rev_it;
	// typedef std::reverse_iterator<std::vector<T>::iterator>			std_rev_it;

	// exec_test<ft::vector<T>, ft_it>		("ft::vector");
	// exec_test<std::vector<T>, std_it>	("std::vector");

	// exec_rev_test<ft::vector<T>, ft_rev_it>		("ft::rev_vector");
	// exec_rev_test<std::vector<T>, std_rev_it>	("std::rev_vector");

	exec_compare<ft::vector<T> >					("VECTOR");
	//tests();
	return 0;
}
