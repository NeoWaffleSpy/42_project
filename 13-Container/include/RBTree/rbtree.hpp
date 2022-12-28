#ifndef RBTREE_HPP
# define RBTREE_HPP

# include "node.hpp"
# include "../stack.hpp"
# include <iostream>

namespace ft
{
	template <	typename T,
				typename AllowDouble = allow_double_class_tag,
				typename Compare = std::less<T>,
				class Alloc = std::allocator<Node<T, Compare, AllowDouble> >,
				typename ft::enable_if<is_double_class_tag<AllowDouble>::valid_class, int>::type = 0>

	/*ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type =0
	**ft::enable_if<is_double_class_tag<AllowDouble>::valid_class, true>::type
	*/
	class Rbtree
	{
	public:
		typedef				T									value_type;
		typedef				Alloc								allocator_type;
		typedef 			Rbtree&								reference;
		typedef 			const Rbtree&						const_reference;
		typedef 			Rbtree*								pointer;
		typedef 			const Rbtree*						const_pointer;
		typedef 			Node<T, Compare, AllowDouble>		node;
	
		Rbtree(): _size(0), _root(NULL)
		{ }

		Rbtree(const node& n): _root(node(n)), _size(1)
		{ }
		
		~Rbtree()
		{
			this->clear();
			while (!_mem_pile.empty())
			{
				_alloc.deallocate(_mem_pile.top(), 1);
				_mem_pile.pop();
			}
		}

		unsigned long	size()				{ return _size;						}
		node*			get_max()			{ return _root->max();				}
		node*			get_min()			{ return _root->min();				}
		node*			find(T value)		{ return _root->find_node(value);	}
		node*			begin()				{ return _root->min();				}
		node*			end()				{ return _root->end();				}
		node*			root()				{ return _root;						}
		void			clear()				{ delete_rec(_root);				}
		node*			operator[](int i)
		{
			if (i >= (int)_size)
				throw (std::out_of_range("OutOfRange: rbtree.hpp::operator[" + ft::to_string(i) + "]"));
			node* tmp = begin();
			for (; tmp && i > 0; i--)
				tmp = tmp->next();
			if (i > 0)
				throw (std::out_of_range("OutOfRange: rbtree.hpp::operator[] - Not supposed to happen"));
			return (tmp);
		}

		const node*			insert(T value)
		{
			node* n = make_node(node(value));
			if (_root == NULL)
			{
				_root = n;
				n->_color = C_BLACK;
				return _root;
			}
			if (_root->insert_node(n) == NULL)
			{
				delete n;
				throw std::logic_error("Inserting duplicate key in a forbidden duplicate tree");
			}
			insertion_fixup(n);
			_size++;
			return n;
		}

		void				delete_node(node* n)
		{
			if (!n)
				throw std::out_of_range("Value not mapped within container");
			/* Child node */
			node* c;
			
			std::cout << "Pass 1" << std::endl;
			if (n->_child[LEFT] && n->_child[RIGHT])
			{
			std::cout << "Pass 1.1" << std::endl;
				node* tmp = n->_child[LEFT]->max();
				n->_value = tmp->_value;
				n = tmp;
			}

			std::cout << "Pass 2" << std::endl;
			c = n->_child[LEFT] ? n->_child[LEFT] : n->_child[RIGHT];

			if (!is_black(n))
			{
			std::cout << "Pass 2.1" << std::endl;
				n->_parent->_child[n->is_right()] = NULL;
				del_node(n);
				return;
			}

			std::cout << "Pass 3" << std::endl;
			if (!is_black(c))
			{
			std::cout << "Pass 3.1" << std::endl;
				n->_value = c->_value;
				del_node(c);
				return;
			}

			std::cout << "Pass 4" << std::endl;
			if (!c)
			{
			std::cout << "Pass 4.1" << std::endl;
				/* Sibling node */
				node* s = n->_parent->_child[!n->is_right()];
				node* tmp = n;
				n = n->_parent;

			std::cout << "Pass 5" << std::endl;
				if (s->_color == C_RED)
				{
			std::cout << "Pass 5.1" << std::endl;
					int side = tmp->is_left();
					n->_child[!side] = NULL;
					s->_color = C_BLACK;
					rotate(n, side);
					s = n->_parent->_child[!n->is_right()];
				}

			std::cout << "Pass 6" << std::endl;
				if (is_black(s) && is_black(s->_child[RIGHT]) && is_black(s->_child[LEFT]))
				{
			std::cout << "Pass 6.1" << std::endl;
					s->_color = C_RED;
					del_node(tmp);
					return;
				}

			std::cout << "Pass 7" << std::endl;
				if (n->is_left() && is_black(s->_child[RIGHT]) && !is_black(s->_child[LEFT]))
				{
			std::cout << "Pass 7.1" << std::endl;
					swap_value(s, s->_child[LEFT]);
					s->_child[LEFT]->_color = C_BLACK;
					rotate(s, RIGHT);
				}
			std::cout << "Pass 8" << std::endl;

				if (n->is_right() && !is_black(s->_child[RIGHT]) && is_black(s->_child[LEFT]))
				{
			std::cout << "Pass 8.1" << std::endl;
					swap_value(s, s->_child[RIGHT]);
					s->_child[RIGHT]->_color = C_BLACK;
				}

				if (is_black(s) && !is_black(s->_child[RIGHT]) && !is_black(s->_child[LEFT]))
				{
					rotate(n, tmp->is_left());
					n->_color = C_BLACK;
					n->_parent->_color = C_RED;
					n->_parent->_child[!n->is_right()]->_color = C_BLACK;
				}
				del_node(tmp);
			}
			std::cout << "Pass 9" << std::endl;
		}

		void					swap_value(node* n1, node* n2)
		{
			T tmp = n1->_value;
			n1->_value = n2->_value;
			n2->_value = tmp;
		}

		// int					delete_node(node* n)
		// {
		// 	if (!n)
		// 		throw std::out_of_range("Value not mapped within container");
		// 	std::cout << "Deleting node " << n->_value << std::endl;
		// 	t_color origin = n->_color;
		// 	node* y = NULL;
		// 	node* x = NULL;
		// 	if (!n->_child[LEFT])
		// 	{
		// 		std::cout << "Pass dans left" << std::endl;
		// 		x = n->_child[RIGHT];
		// 		if (n == _root)
		// 			_root = x;
		// 		else
		// 			n->_parent->set_child(x, n->is_right());
		// 		delete_rec(n);
		// 	}
		// 	else
		// 	{
		// 		std::cout << "Pass dans right" << std::endl;
		// 		y = n->_child[LEFT]->max();
		// 		std::cout << "y = " << y->_value << std::endl;
		// 		x = y->_child[LEFT];
		// 		origin = C_BLACK;
		// 		if (x)
		// 			origin = x->_color;
		// 		if (x)
		// 			std::cout << "x = " << x->_value << std::endl;
		// 		if (n != y->_parent)
		// 			y->_parent->set_child(x, RIGHT);
		// 		else
		// 			y->_parent->set_child(x, LEFT);
		// 		if (x)
		// 			x->_color = C_BLACK;
		// 		y->_child[LEFT] = NULL;
		// 		n->_value = y->_value;
		// 		delete_rec(y);
		// 	}
		// 	if (origin == C_BLACK)
		// 		remove_fixup(x);
		// 	_size--;
		// 	return (1);
		// }

		// void remove_fixup(node* x) {
		// 	int side = RIGHT;
		// 	while(x && x != _root && x->_color == C_BLACK)
		// 	{
		// 		if(x->is_left() && x->_parent->_child[side])
		// 		{
		// 			node* w = x->_parent->_child[side];
		// 			if(w->_color == C_RED)
		// 			{
		// 				w->_color = C_BLACK;
		// 				x->_parent->_color = C_RED;
		// 				rotate(x->_parent, !side);
		// 				w = x->_parent->_child[side];
		// 			}
		// 			if(w->_child[!side]->_color == C_BLACK && w->_child[side]->_color == C_BLACK)
		// 			{
		// 				w->_color = C_RED;
		// 				x = x->_parent;
		// 			}
		// 			else
		// 			{
		// 				if(w->_child[side]->_color == C_BLACK)
		// 				{
		// 					w->_child[!side]->_color = C_BLACK;
		// 					w->_color = C_RED;
		// 					rotate(w, side);
		// 					w = x->_parent->_child[side];
		// 				}
		// 				w->_color = x->_parent->_color;
		// 				x->_parent->_color = C_BLACK;
		// 				w->_child[side]->_color = C_BLACK;
		// 				rotate(x->_parent, !side);
		// 				x = _root;
		// 			}
		// 		}
		// 		else if (x->_parent->_child[!side])
		// 		{
		// 			node* w = x->_parent->_child[!side];
		// 			if(w->_color == C_RED)
		// 			{
		// 				w->_color = C_BLACK;
		// 				x->_parent->_color = C_RED;
		// 				rotate(x->_parent, side);
		// 				w = x->_parent->_child[!side];
		// 			}
		// 			if(w->_child[side]->_color == C_BLACK && w->_child[!side]->_color == C_BLACK)
		// 			{
		// 				w->_color = C_RED;
		// 				x = x->_parent;
		// 			}
		// 			else
		// 			{
		// 				if(w->_child[!side]->_color == C_BLACK)
		// 				{
		// 					w->_child[side]->_color = C_BLACK;
		// 					w->_color = C_RED;
		// 					rotate(w, !side);
		// 					w = x->_parent->_child[!side];
		// 				}
		// 				w->_color = x->_parent->_color;
		// 				x->_parent->_color = C_BLACK;
		// 				w->_child[!side]->_color = C_BLACK;
		// 				rotate(x->_parent, side);
		// 				x = _root;
		// 			}
		// 		}
		// 	}
		// 	if (x)
		// 		x->_color = C_BLACK;
		// }

		// void insertion_fixup(node* z) {
		// 	while(z != _root && z->_parent->_color == C_RED) {
		// 		if(z->_parent == z->_parent->_parent->_child[LEFT]) { //z._parent is the left child
		// 			node* y = z->_parent->_parent->_child[RIGHT]; //uncle of z
		// 			if(y != NULL && y->_color == C_RED) { //case 1
		// 				z->_parent->_color = C_BLACK;
		// 				y->_color = C_BLACK;
		// 				z->_parent->_parent->_color = C_RED;
		// 				z = z->_parent->_parent;
		// 			}
		// 			else { //case2 or case3
		// 				if(z == z->_parent->_child[RIGHT]) { //case2
		// 					z = z->_parent; //marked z._parent as new z
		// 					left_rotate(z);
		// 				}
		// 			//case3
		// 				z->_parent->_color = C_BLACK; //made _parent black
		// 				z->_parent->_parent->_color = C_RED; //made _parent red
		// 				right_rotate(z->_parent->_parent);
		// 			}
		// 		}
		// 		else { //z._parent is the right child
		// 			node* y = z->_parent->_parent->_child[LEFT]; //uncle of z
		// 			if(y != NULL && y->_color == C_RED) {
		// 				z->_parent->_color = C_BLACK;
		// 				y->_color = C_BLACK;
		// 				z->_parent->_parent->_color = C_RED;
		// 				z = z->_parent->_parent;
		// 			}
		// 			else {
		// 				if(z == z->_parent->_child[LEFT]) {
		// 					z = z->_parent; //marked z._parent as new z
		// 					right_rotate(z);
		// 				}
		// 				z->_parent->_color = C_BLACK; //made _parent black
		// 				z->_parent->_parent->_color = C_RED; //made _parent red
		// 				left_rotate(z->_parent->_parent);
		// 			}
		// 		}
		// 	}
		// 	_root->_color = C_BLACK;
		// }

		// void	left_rotate(node* x) {
		// 	node* y = x->_child[RIGHT];
		//  	x->set_child(y->_child[LEFT], RIGHT);
		// 	if (!x->_parent)
		// 	{
		// 		_root = y;
		// 		y->_parent = NULL;
		// 	}
		// 	else
		// 		x->_parent->set_child(y, x->is_right());
		// 	y->set_child(x, LEFT);
		// }

		// void	right_rotate(node* x) {
		// 	node* y = x->_child[LEFT];
		//  	x->set_child(y->_child[RIGHT], LEFT);
		// 	if (!x->_parent)
		// 	{
		// 		_root = y;
		// 		y->_parent = NULL;
		// 	}
		// 	else
		// 		x->_parent->set_child(y, x->is_right());
		// 	y->set_child(x, RIGHT);
		// }

		void insertion_fixup(node* z) {
			while(z != _root && z->_parent->_color == C_RED)
			{
				int side = !z->_parent->is_left();
				node* y = z->_parent->_parent->_child[!side];
				if(y != NULL && y->_color == C_RED)
				{
					z->_parent->_color = C_BLACK;
					y->_color = C_BLACK;
					z->_parent->_parent->_color = C_RED;
					z = z->_parent->_parent;
				}
				else
				{
					if(z == z->_parent->_child[!side])
					{
						z = z->_parent;
						rotate(z, !side);
					}
					z->_parent->_color = C_BLACK;
					z->_parent->_parent->_color = C_RED;
					rotate(z->_parent->_parent, side);
				}
			}
			_root->_color = C_BLACK;
		}

		void	rotate(node* x, int side) {
			node* y = x->_child[side];
			x->set_child(y->_child[!side], side);
			if (!x->_parent)
			{
				_root = y;
				y->_parent = NULL;
			}
			else
				x->_parent->set_child(y, x->is_right());
			y->set_child(x, !side);
		}
		
		node*	make_node(const node& ref)
		{
			node* new_node;
			if (!_mem_pile.empty())
			{
				new_node = _mem_pile.top();
				_mem_pile.pop();
			}
			else
				new_node = _alloc.allocate(1);
			_alloc.construct(new_node, ref);
			return new_node;
		}

		bool	is_black(node* ref)
		{
			if (ref && ref->_color == C_RED)
				return false;
			return true;
		}

		void	delete_rec(node* ref)
		{
			if (ref->_child[LEFT])
				delete_rec(ref->_child[LEFT]);
			if (ref->_child[RIGHT])
				delete_rec(ref->_child[RIGHT]);
			del_node(ref);
		}

		void	del_node(node* ref)
		{
			_alloc.destroy(ref);
			_mem_pile.push(ref);
		}

	private:
		unsigned long			_size;
		node*					_root;
		ft::stack<node*>		_mem_pile;
		allocator_type			_alloc;
	};
	
}


#endif