#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

namespace ft
{
	template < class T, class Alloc = allocator<T> >
	class vector
	{
	public:
		typedef				T									value_type;
		typedef				Alloc								allocator_type;
		typedef typename	allocator_type::reference			reference;
		typedef typename	allocator_type::const_reference		const_reference;
		typedef typename	allocator_type::pointer				pointer;
		typedef typename	allocator_type::const_pointer		const_pointer;
		typedef				void								iterator;
		typedef				void								const_iterator;
		typedef				void								reverse_iterator;
		typedef				void								const_reverse_iterator;
		typedef	typename	void								difference_type;
		typedef typename	allocator_type::size_type			size_type;

		explicit vector (const allocator_type& alloc = allocator_type())
		{}
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		{}
		vector (const vector& x)
		{}
	}
}

#endif