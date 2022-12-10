#ifndef NODE_HPP
# define NODE_HPP

# include "../Iterators/utils.hpp"

# define LEFT 0
# define RIGHT 1

typedef enum	e_color
{
	C_BLACK,
	C_RED
}				t_color;

namespace ft
{
	template <typename T, typename Compare, typename AllowDouble = allow_double_class_tag>
	class Node
	{
	public:
		typedef T			value_type;
		typedef Node&		reference;
		typedef const Node&	const_reference;
		typedef Node*		pointer;
		typedef const Node*	const_pointer;

		t_color		_color;
		value_type	_value;
		Node		_parent;
		Node		_child[2];

		class InvalidSideException : public std::exception
		{ public: virtual const char *what() const throw(); };

		Node(value_type value = value_type(), reference parent = NULL) : _color(t_color.C_RED), _value(value), _parent(parent)
		{
			_child[LEFT] = NULL;
			_child[RIGHT] = NULL;
		}

		Node(const_reference n) : _color(n->_color), _value(n->_value), _parent(n->_parent)
		{
			_child[LEFT] = n->_child[LEFT];
			_child[RIGHT] = n->_child[RIGHT];
		}

		~Node()
		{ }

		Node operator=(const_reference n)
		{
			_color = n->_color;
			_value = n->_value;
			_parent = n->_parent;
			_child[LEFT] = n->_child[LEFT];
			_child[RIGHT] = n->_child[RIGHT];
		}

		reference operator[](int n)
		{
			if (n < LEFT || n > RIGHT)
				throw InvalidSideException("Access to invalid child node");
			return _child[n];
		}

		reference set_child(reference n, int side)
		{
			if (side < LEFT || side > RIGHT)
				throw InvalidSideException("Access to invalid child node");
			_child[side] = n;
			n->_parent = this;
		}

		reference max()
		{
			if (_child[RIGHT] == NULL)
				return this;
			return _child[RIGHT]->max();
		}

		reference min()
		{
			if (_child[LEFT] == NULL)
				return this;
			return _child[LEFT]->min();
		}

		reference find_node(T value)
		{
			if (Compare(this->_value, value))
				return (_child[LEFT] ? _child[LEFT]->find_node(value) : NULL);
			if (Compare(value, this->_value))
				return (_child[RIGHT] ? _child[RIGHT]->find_node(value) : NULL);
			return this;
		}

		reference insert_node(reference n)
		{
			if (Compare(this->_value, n->_value))
				return (_child[LEFT] ? _child[LEFT]->insert_node(value) : set_child(n, LEFT));
			if (Compare(n->_value, this->_value))
				return (_child[RIGHT] ? _child[RIGHT]->insert_node(value) : set_child(n, RIGHT));
			if (is_double_class_tag<AllowDouble>::value)
				return (_child[RIGHT] ? _child[RIGHT]->insert_node(value) : set_child(n, RIGHT));
			else
				return NULL;
		}
	};
}


#endif