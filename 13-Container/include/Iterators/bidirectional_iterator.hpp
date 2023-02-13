#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <cstddef>
# include "utils.hpp"
# include "../RBTree/rbtree.hpp"

namespace ft {

	template <typename T, typename Node_Type, bool constness = false> /* PAIR */
	class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef bidirectional_iterator	it;
			typedef T						value_type;
			typedef	typename is_const<T, constness>::type*		pointer;
			typedef	typename is_const<T, constness>::type&		reference;
			typedef Node_Type*				node;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;

			bidirectional_iterator(): _elem(NULL) {};
			bidirectional_iterator(const node src): _elem(src) {};
			bidirectional_iterator(const bidirectional_iterator<T, Node_Type, true>& src): _elem(src.get_node()) {};
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


// namespace ft {

// 	template <typename T, bool constness = false>
// 	class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
// 	{
// 		public:
// 			typedef bidirectional_iterator			it;
// 			typedef typename is_const<typename T::value_type, constness>::type*					pt_pair;
// 			typedef typename is_const<typename T::value_type, constness>::type&					ref_pair;
// 			// typedef Node<value_type>				node_type;
// 			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
// 			// typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
// 			typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
// 			// typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer               pointer;
// 			// typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference             reference;
// 			typedef	typename is_const<T, constness>::type		value_type;
// 			typedef	typename is_const<T, constness>::type*		pointer;
// 			typedef	typename is_const<T, constness>::type&		reference;
// 			// typedef typename ft::conditional<ft::is_const<T>::value, const Node<typename remove_cv<value_type>::type >* , Node<value_type>* >::type pair_node_pointer;
// 			// typedef typename ft::conditional<ft::is_pair<typename remove_const<value_type>::type >::value, pair_node_pointer, node_type*>::type		node_pointer;

// 			bidirectional_iterator(): _elem(NULL) {};
// 			bidirectional_iterator(const pointer src): _elem(src) {};
// 			bidirectional_iterator(const bidirectional_iterator< typename remove_cv<T>::type>& src): _elem(src.get_node()) {};
// 			it&	operator=(const it& rhs) {
// 				if (this == &rhs)
// 					return (*this);
// 				_elem = rhs._elem;
// 					return (*this);
// 			};
// 			~bidirectional_iterator() {};

// 			pointer		get_node()					const	{ return (_elem);				}
// 			bool		operator==(const it& rhs)	const	{ return (_elem == rhs._elem);	}
// 			bool		operator!=(const it& rhs)	const	{ return (_elem != rhs._elem);	}
// 			pt_pair		operator->()				const	{ return &(_elem->_value);		}
// 			ref_pair	operator*()					const	{ return (_elem->_value);		}

// 			it&	operator++()	{ _elem = _elem->next(); return (*this);				}
// 			it&	operator--()	{ _elem = _elem->prev(); return (*this);				}
// 			it	operator++(int)	{ it tmp = *this; _elem = _elem->next(); return (tmp);	}
// 			it	operator--(int)	{ it tmp = *this; _elem = _elem->prev(); return (tmp);	}

//         private:
//             pointer _elem;
// 	};
// }

#endif
