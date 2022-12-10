#ifndef RBTREE_HPP
# define RBTREE_HPP

# include "node.hpp"
#include <iostream>

namespace ft
{
	template <typename T, typename Compare = std::less<T>, typename AllowDouble = allow_double_class_tag>
	class Rbtree : private Node
	{
	private:
		unsigned long			_size;
	public:
		typedef T				value_type;
		typedef Rbtree&			reference;
		typedef const Rbtree&	const_reference;
		typedef Rbtree*			pointer;
		typedef const Rbtree*	const_pointer;
	
		Rbtree(value_type value = value_type()): Node(value)
		{ }

		Rbtree(const Node& n): Node(n)
		{
			this._parent = this;
		}
		
		~Rbtree(): ~Node()
		{ }

		unsigned long	size()			{ return this->_size;				}
		Node&			get_max()		{ return this->max();				}
		Node&			get_min()		{ return this->min();				}
		Node&			find(T value)	{ return this->find_node(value)		}
	};
	
}


#endif