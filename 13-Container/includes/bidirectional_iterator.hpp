#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <cstddef>
# include "utils.hpp"
# include "rbtree.hpp"

namespace ft {

	template <typename T, typename Node_Type, bool constness = false> /* PAIR */
	class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef bidirectional_iterator	it;
			typedef T						value_type;
			typedef	typename get_const<T, constness>::type*		pointer;
			typedef	typename get_const<T, constness>::type&		reference;
			typedef Node_Type*				node;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;

			bidirectional_iterator(): _elem(NULL) {};
			bidirectional_iterator(const node src): _elem(src) {};
			bidirectional_iterator(const bidirectional_iterator<T, Node_Type, false>& src): _elem(src.get_node()) {};
			it&	operator=(const it& rhs) {
				if (this == &rhs)
					return (*this);
				_elem = rhs._elem;
					return (*this);
			};

			~bidirectional_iterator() {};

			node		get_node()					const	{ return (_elem);				}
			bool		operator==(const it& rhs)	const	{ return (_elem == rhs._elem);	}
			bool		operator!=(const it& rhs)	const	{ return (_elem != rhs._elem);	}
			pointer		operator->()				const	{ return &(_elem->_value);		}
			reference	operator*()					const	{ return (_elem->_value);		}

			it&	operator++()	{ _elem = _elem->next(); return (*this);				}
			it&	operator--()	{ _elem = _elem->prev(); return (*this);				}
			it	operator++(int)	{ it tmp = *this; _elem = _elem->next(); return (tmp);	}
			it	operator--(int)	{ it tmp = *this; _elem = _elem->prev(); return (tmp);	}

        private:
            node _elem;
	};
}

#endif
