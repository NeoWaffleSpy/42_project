#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
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
		typedef				T													value_type;
		typedef				Alloc												allocator_type;
		typedef typename	allocator_type::reference							reference;
		typedef typename	allocator_type::const_reference						const_reference;
		typedef typename	allocator_type::pointer								pointer;
		typedef typename	allocator_type::const_pointer						const_pointer;
		typedef				ft::random_access_iterator<value_type>				iterator;
		typedef				ft::random_access_iterator<const value_type>		const_iterator;
		typedef				ft::reverse_iterator<iterator>						reverse_iterator;
		typedef				ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef	typename	ft::iterator_traits<iterator>::difference_type		difference_type;
		typedef typename	allocator_type::size_type							size_type;

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
		{
			/* A faire apres les iterators*/
		}

		vector (const vector& x)
		{
			this->insert(this->begin(), x.begin(), x.end());
		}

		~vector()
		{
			this->clear();
			_alloc.deallocate(_start, this->capacity());
		}

		vector &operator=(const vector& x)
		{
			if (x == *this)
				return (*this);
			this->clear();
			this->insert(this->end(), x.begin(), x.end());
			return (*this);
		}

		/* ITERATORS */

		iterator				begin()								{ return (_start);								}
		const_iterator			begin()						const	{ return (_start);								}
		iterator				end()								{ return (_end);								}
		const_iterator			end()						const	{ return (_end);								}
		reverse_iterator		rbegin()							{ return (reverse_iterator(this->end()));		}
		const_reverse_iterator	rbegin()					const	{ return (reverse_iterator(this->end()));		}
		reverse_iterator		rend()								{ return (reverse_iterator(this->begin()));		}
		const_reverse_iterator	rend()						const	{ return (reverse_iterator(this->begin()));		}

		/* CAPACITY */

		size_type				size(void)					const	{ return (this->_end - this->_start);			}
		size_type				max_size(void)				const	{ return (allocator_type().max_size());			}
		size_type				capacity (void)				const	{ return (this->_end_capacity - this->_start);	}
		bool					empty (void)				const	{ return (size() == 0 ? true : false);			}
		void					resize (size_type n, value_type val = value_type())
		{
			if (n > this->max_size())
				throw (std::length_error("vector::resize"));
			else if (n < this->size())
			{
				while (this->size() > n)
				{
					--_end;
					_alloc.destroy(_end);
				}
			}
			else
				this->insert(this->end(), n - this->size(), val);
		}
		void					reserve (size_type n)
		{
			if (n > this->max_size())
				throw (std::length_error("vector::reserve"));
			else if (n > this->capacity())
			{
				pointer prev_start = _start;
				pointer prev_end = _end;
				size_type prev_size = this->size();
				size_type prev_capacity = this->capacity();
				
				_start = _alloc.allocate( n );
				_end_capacity = _start + n;
				_end = _start;
				while (prev_start != prev_end)
				{
					_alloc.construct(_end, *prev_start);
					_end++;
					prev_start++;
				}
				_alloc.deallocate(prev_start - prev_size, prev_capacity);
			}
		}

		/* ELEMENT ACCESS */

		reference				operator[] (size_type n)			{ return (*(_start + n));						}
		const_reference			operator[] (size_type n)	const	{ return (*(_start + n));						}
		reference				at (size_type n)
		{
			checkRange(n);
			return ((*this)[n]);
		}
		const_reference			at (size_type n)			const
		{
			checkRange(n);
			return ((*this)[n]);
		}
		reference				front ()							{ return (*_start);								}
		const_reference			front ()					const	{ return (*_start);								}
		reference				back ()								{ return (*(_end - 1));							}
		const_reference			back ()						const	{ return (*(_end - 1));							}

		/* MODIFIER */

		void assign( size_type count, const T& value )
		{
			this->clear();
			if (n == 0)
				return ;
			if (size_type(_end_capacity - _start) >= n)
				for (; n; n--)
					_alloc.construct(_end++ , val);
				// while (n)
				// {
				// 	_alloc.construct(_end++ , val);
				// 	n--;
				// }
			else
			{
				_alloc.deallocate(_start, this->capacity());
				_start = _alloc.allocate( n );
				_end = _start;
				_end_capacity = _start + n;
				for (; n; n--)
					_alloc.construct(_end++ , val);
			}
		}

		template< class InputIt >
		void assign( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr)
		{
			bool is_valid;
			if (!(is_valid = ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category>::value))
				throw (ft::InvalidIteratorException<typename ft::is_ft_iterator_tagged<typename ft::iterator_traits<InputIterator>::iterator_category >::type>());
			this->clear();
			size_type dist = ft::distance(first, last);
			if (size_type(_end_capacity - _start) >= dist)
			{
				for(; &(*first) != &(*last); first++, _end++)
					_alloc.construct(_end, *first);
			}
			else
			{
				pointer new_start = pointer();
				pointer new_end = pointer();
				pointer new_end_capacity = pointer();
				new_start = _alloc.allocate(dist);
				new_end = new_start;
				new_end_capacity = new_start + dist;
				for(; &(*first) != &(*last); first++, new_end++)
					_alloc.construct(new_end, *first);
				
				_alloc.deallocate(_start, this->capacity());
				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
		}

		void push_back (const value_type& val)
		{                
			if (_end == _end_capacity)
				this->reserve((this->size() > 0) ? (int)(this->size() * 2) : 1);
			_alloc.construct(_end, val);
			_end++;
		}

		void pop_back()
		{
			_alloc.destroy(&this->back());
			_end--;
		}

		iterator insert (iterator position, const value_type& val)
		{
			size_type pos_len = &(*position) - _start;
			if (size_type(_end_capacity - _end) >= this->size() + 1)
			{
				for (size_type i = 0; i < pos_len; i++)
					_alloc.construct(_end - i, *(_end - i - 1));
				_end++;
				_alloc.construct(&(*position), val);
			}
			else
			{
				pointer new_start = pointer();
				pointer new_end = pointer();
				pointer new_end_capacity = pointer();
				int next_capacity = (this->size() * 2 > 0) ? this->size() * 2 : 1; 
				new_start = _alloc.allocate( next_capacity );
				new_end = new_start + this->size() + 1;
				new_end_capacity = new_start + next_capacity;
				for (size_type i = 0; i < pos_len; i++)
					_alloc.construct(new_start + i, *(_start + i));
				_alloc.construct(new_start + pos_len, val);
				for (size_type j = 0; j < this->size() - pos_len; j++)
					_alloc.construct(new_end - j - 1, *(_end - j - 1));
				for (size_type l = 0; l < this->size(); l++)
					_alloc.destroy(_start + l);
				if (_start)
					_alloc.deallocate(_start, this->capacity());
				
				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
			return (iterator(_start + pos_len));
		}

		void insert (iterator position, size_type n, const value_type& val)
		{
			if (n == 0)
				return ;
			if (n > this->max_size())
				throw (std::length_error("vector::insert (fill)"));
			size_type pos_len = &(*position) - _start;
			if (size_type(_end_capacity - _end) >= n)
			{
				for (size_type i = 0; i < this->size() - pos_len; i++)
					_alloc.construct(_end - i + (n - 1), *(_end - i - 1));
				_end += n;
				while (n)
				{
					_alloc.construct(&(*position) + (n - 1), val);
					n--;
				}
			}
			else
			{
				pointer new_start = pointer();
				pointer new_end = pointer();
				pointer new_end_capacity = pointer();
				
				int next_capacity = (this->capacity() > 0) ? (int)(this->size() * 2) : 1;
				new_start = _alloc.allocate(next_capacity);
				new_end_capacity = new_start + next_capacity;
				if (size_type(new_end_capacity - new_start) < this->size() + n)
				{
					if (new_start)
						_alloc.deallocate(new_start, new_start - new_end_capacity);
					next_capacity = this->size() + n;
					new_start = _alloc.allocate(next_capacity);
					new_end = new_start + this->size() + n;
					new_end_capacity = new_start + next_capacity;
				}
				new_end = new_start + this->size() + n;
				for (int i = 0; i < (&(*position) - _start); i++)
					_alloc.construct(new_start + i, *(_start + i));
				for (size_type k = 0; k < n; k++)
					_alloc.construct(new_start + pos_len + k, val);
				for (size_type j = 0; j < (this->size() - pos_len); j++)
					_alloc.construct(new_end - j - 1, *(_end - j - 1));
				for (size_type u = 0; u < this->size(); u++)
					_alloc.destroy(_start + u);
				_alloc.deallocate(_start, this->capacity());
				_start = new_start;
				_end = new_end;
				_end_capacity = new_end_capacity;
			}
		}


	};
}

#endif