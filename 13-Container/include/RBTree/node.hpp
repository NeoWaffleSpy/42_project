#ifndef NODE_HPP
# define NODE_HPP

# define LEFT 0
# define RIGHT 1

typedef enum	e_color
{
	BLACK,
	RED
}				t_color;

namespace ft
{
	template <typename T>
	class Node
	{
	public:
		typedef T			type;
		typedef Node&		reference;
		typedef const Node&	const_reference;
		typedef Node*		pointer;
		typedef const Node*	const_pointer;

		class InvalidSideException : public std::exception
		{ public: virtual const char *what() const throw(); };

		Node(type value_type = type()) : _color(t_color.RED), _value(NULL) _parent(NULL)
		{
			_child[LEFT] = NULL;
			_child[RIGHT] = NULL;
		}

		void	add_child(Node n)
		{

			child[side] = n;
		}

	private:
		t_color _color;
		type	_value;
		pointer	_parent;
		pointer _child[2];
	};
}


#endif