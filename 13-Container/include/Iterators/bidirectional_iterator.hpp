#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <cstddef>
# include "utils.hpp"
# include "../RBTree/rbtree.hpp"

namespace ft {

	template <typename T>
	class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef bidirectional_iterator			it;
			typedef typename T::value_type*					pt_pair;
			typedef typename T::value_type&					ref_pair;
			// typedef Node<value_type>				node_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer               pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference             reference;
			// typedef typename ft::conditional<ft::is_const<T>::value, const Node<typename remove_cv<value_type>::type >* , Node<value_type>* >::type pair_node_pointer;
			// typedef typename ft::conditional<ft::is_pair<typename remove_const<value_type>::type >::value, pair_node_pointer, node_type*>::type		node_pointer;

			bidirectional_iterator(): _elem(NULL) {};
			bidirectional_iterator(const pointer src): _elem(src) {};
			bidirectional_iterator(const bidirectional_iterator< typename remove_cv<T>::type>& src): _elem(src._elem) {};
			it&	operator=(const it& rhs) {
				if (this == &rhs)
					return (*this);
				_elem = rhs._elem;
					return (*this);
			};
			~bidirectional_iterator() {};

			bool		operator==(const it& rhs)	const { return (_elem == rhs._elem);	};
			bool		operator!=(const it& rhs)	const { return (_elem != rhs._elem);	};
			pt_pair		operator->()				const { return &(_elem->_value);		};
			ref_pair	operator*()					const { return (_elem->_value);			};

			it&	operator++() { _elem = _elem->next(); return (*this);};
			it&	operator--() { _elem = _elem->previous(); return (*this); };
			it	operator++(int) { it tmp = *this; _elem = _elem->next(); return (tmp);};
			it	operator--(int) { it tmp = *this; _elem = _elem->previous(); return (tmp); };

        private:
            pointer _elem;
	};
}

#endif
