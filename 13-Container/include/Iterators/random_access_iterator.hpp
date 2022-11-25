#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

/* TRY REPLACE ALL `difference_type` WITH `long` */

namespace ft
{

	/*
	** @brief Random-access iterators allow to access elements at an
	** arbitrary offset position relative to the element they point
	** to. This is the most complete iterators. All pointer types
	** are also valid random-access-iterators.
	*/
	template <typename T>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
	private:
		pointer _elem;

	public:
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
		typedef T *pointer;
		typedef T &reference;

		random_access_iterator(void) : _elem(u_nullptr) {}
		random_access_iterator(pointer elem) : _elem(elem) {}
		random_access_iterator(const random_access_iterator &op) : _elem(op._elem) {}
		virtual ~random_access_iterator() {}

		pointer					base()							const	{ return (this->_elem);			}
		reference				operator*(void)					const	{ return (*_elem);				}
		pointer					operator->(void)						{ return &(this->operator*());	}
		random_access_iterator	operator+(difference_type n)	const	{ return (_elem + n);			}
		random_access_iterator	operator-(difference_type n)	const	{ return (_elem - n);			}
		reference				operator[](difference_type n)			{ return (*(operator+(n)));		}

		random_access_iterator	&operator=(const random_access_iterator &op)
		{
			if (this == &op)
				return (*this);
			this->_elem = op._elem;
			return (*this);
		}
		random_access_iterator	&operator++(void)
		{
			_elem++;
			return (*this);
		}
		random_access_iterator	operator++(int)
		{
			random_access_iterator rtn(*this);
			operator++();
			return (rtn);
		}
		random_access_iterator	&operator--(void)
		{
			_elem--;
			return (*this);
		}
		random_access_iterator	operator--(int)
		{
			random_access_iterator rtn(*this);
			operator--();
			return (rtn);
		}
		random_access_iterator	&operator+=(difference_type n)
		{
			_elem += n;
			return (*this);
		}
		random_access_iterator	&operator-=(difference_type n)
		{
			_elem -= n;
			return (*this);
		}

		operator random_access_iterator<const T>() const
		{
			return (random_access_iterator<const T>(this->_elem));
		}
	};

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator==(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename T_L, typename T_R>
	typename ft::random_access_iterator<T_L>::difference_type
	operator==(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator!=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename T_L, typename T_R>
	typename ft::random_access_iterator<T_L>::difference_type
	operator!=(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator<(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename T_L, typename T_R>
	typename ft::random_access_iterator<T_L>::difference_type
	operator<(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator>(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename T_L, typename T_R>
	typename ft::random_access_iterator<T_L>::difference_type
	operator>(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator<=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename T_L, typename T_R>
	typename ft::random_access_iterator<T_L>::difference_type
	operator<=(const ft::random_access_iterator<T_L> lhs,  const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator>=(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename T_L, typename T_R>
	typename ft::random_access_iterator<T_L>::difference_type
	operator>=(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator-(const ft::random_access_iterator<T> lhs, const ft::random_access_iterator<T> rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template <typename T_L, typename T_R>
	typename ft::random_access_iterator<T_L>::difference_type
	operator-(const ft::random_access_iterator<T_L> lhs, const ft::random_access_iterator<T_R> rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template <typename T>
	ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type n, typename ft::random_access_iterator<T> &rai)
	{
		return (&(*rai) + n);
	}
}

#endif