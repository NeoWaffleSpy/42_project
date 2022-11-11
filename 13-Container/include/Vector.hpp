#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

namespace ft
{
	template < class T, class Alloc = allocator<T> >
	class vector
	{
    private:
    	allocator_type  _alloc;
    	pointer         _start;
    	pointer         _end;
    	pointer         _end_capacity;

    	void checkRange(const size_type& n) const
    	{
            if (n >= this->size())
            	throw (std::out_of_range("vector::checkRange: n (which is " + ft::to_string(n) + ") >= this->size() (which is " + ft::to_string(this->size()) + ")"));
    	}

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

		explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _start(u_nullptr), _end(u_nullptr), _end_capacity(u_nullptr)
		{}

		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _start(u_nullptr), _end(u_nullptr), _end_capacity(u_nullptr)
        {
        	_start = _alloc.allocate( n );
        	_end_capacity = _start + n;
        	_end = _start;
        	while (n--)
        	{
        		_alloc.construct(_end, val);
        		_end++;
        	}
        }
        
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr)
		{}

		vector (const vector& x)
		{}
	}
}

#endif