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
		pointer		_parent;
		pointer		_child[2];
		Compare		_comp;

		Node(value_type value = value_type(), Compare comp = Compare(), t_color color = C_RED) : _color(color), _value(value), _parent(NULL), _comp(comp)
		{
			_child[LEFT] = NULL;
			_child[RIGHT] = NULL;
		}

		Node(const_reference n): _color(n._color), _value(n._value), _parent(n._parent), _comp(n._comp)
		{
			_child[LEFT] = n._child[LEFT];
			_child[RIGHT] = n._child[RIGHT];
		}

		~Node()
		{
			if (_parent && is_left())
				_parent->_child[LEFT] = NULL;
			if (_parent && is_right())
				_parent->_child[RIGHT] = NULL;
		}

		Node operator=(const_reference n)
		{
			_color = n->_color;
			_value = n->_value;
			_parent = n->_parent;
			_child[LEFT] = n->_child[LEFT];
			_child[RIGHT] = n->_child[RIGHT];
		}

		pointer set_child(pointer n, int side)
		{
			if (side < LEFT || side > RIGHT)
				throw std::out_of_range("Access to invalid child node");
			_child[side] = n;
			if (n)
				n->_parent = this;
			return n;
		}

		bool is_right()
		{
			if (this->_parent && (this == this->_parent->_child[RIGHT]))
				return true;
			return false;
		}

		bool is_left()
		{
			if (this->_parent && (this == this->_parent->_child[LEFT]))
				return true;
			return false;
		}

		pointer next()
		{
			Node* tmp;
			if (_child[RIGHT] != NULL)
				return _child[RIGHT]->min();
			if (is_left())
				return _parent;
			tmp = this;
			while (tmp != NULL && tmp->is_right())
				tmp = tmp->_parent;
			if (tmp == NULL)
				return NULL;
			return tmp->_parent;
		}

		pointer prev()
		{
			Node* tmp;
			if (_child[LEFT] != NULL)
				return _child[LEFT]->max();
			if (is_right())
				return _parent;
			tmp = this;
			while (tmp != NULL && tmp->is_left())
				tmp = tmp->_parent;
			if (tmp == NULL)
				return NULL;
			return tmp->_parent;
		}

		pointer max()
		{
			if (_child[RIGHT] == NULL)
				return this;
			return _child[RIGHT]->max();
		}

		pointer min()
		{
			if (_child[LEFT] == NULL)
				return this;
			return _child[LEFT]->min();
		}

		pointer find_node(T value)
		{
			if (_comp(value, this->_value))
				return (_child[LEFT] ? _child[LEFT]->find_node(value) : NULL);
			if (_comp(this->_value, value))
				return (_child[RIGHT] ? _child[RIGHT]->find_node(value) : NULL);
			return this;
		}

		pointer insert_node(pointer n)
		{
			if (_comp(this->_value, n->_value))
				return (_child[RIGHT] ? _child[RIGHT]->insert_node(n) : set_child(n, RIGHT));
			if (_comp(n->_value, this->_value))
				return (_child[LEFT] ? _child[LEFT]->insert_node(n) : set_child(n, LEFT));
			if (is_double_class_tag<AllowDouble>::value)
				return (_child[RIGHT] ? _child[RIGHT]->insert_node(n) : set_child(n, RIGHT));
			this->_value = n->_value;
			n->_value = NULL;
			return this;
		}
	};
}


#endif