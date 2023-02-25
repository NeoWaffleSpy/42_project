#ifndef RBTREE_HPP
# define RBTREE_HPP

# include "node.hpp"
# include "../stack.hpp"
# include "../vector.hpp"
# include <iostream>

namespace ft
{
	template <	typename T,
				typename AllowDouble = allow_double_class_tag,
				typename Compare = std::less<T>,
				class Alloc = std::allocator<Node<T, Compare, AllowDouble> >,
				typename ft::enable_if<is_double_class_tag<AllowDouble>::valid_class, int>::type = 0>
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
	
		Rbtree(const Compare& comp, const allocator_type& alloc = allocator_type()): _size(0), _root(NULL), _alloc(alloc), _comp(comp), _sentinelle(NULL)
		{
			set_sentinelle();
		}

		Rbtree(const node& n, const Compare& comp, const allocator_type& alloc = allocator_type()): _size(1), _root(node(n)), _alloc(alloc), _comp(comp), _sentinelle(NULL)
		{
			set_sentinelle();
		}

		Rbtree(const Rbtree& r): _size(r._size), _root(NULL), _alloc(r._alloc), _comp(r._comp), _sentinelle(NULL)
		{
			if (_size > 0)
				copy_tree(&r);
			else
				set_sentinelle();
		}
		
		~Rbtree()
		{
			this->clear();
			del_sentinelle();
			while (!_mem_pile.empty())
			{
				_alloc.deallocate(_mem_pile.top(), 1);
				_mem_pile.pop();
			}
		}

		unsigned long	size()		const	{ return _size;							}
		unsigned long	max_size()	const	{ return (allocator_type().max_size());	}
		node*			get_max()			{ return _root->max();					}
		node*			get_min()			{ return _root->min();					}
		node*			find(T value)		{ return _root->find_node(value);		}
		node*			begin()				{ return _root->min();					}
		node*			end()				{ return _root->max();					}
		node*			root()				{ return _root;							}


		void			clear()
		{
			delete_rec(_root);
			_root = NULL;
			_sentinelle = NULL;
			set_sentinelle();
			_size = 0;
		}

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

		void set_sentinelle()
		{
			if (!_sentinelle)
				_sentinelle = make_node(node(value_type(), _comp));
			if (_root == NULL)
			{
				_root = _sentinelle;
				_sentinelle->_parent = NULL;
			}
			else
				get_max()->set_child(_sentinelle, RIGHT);
		}

		void unset_sentinelle()
		{
			if (_root == _sentinelle)
				_root = NULL;
			else
				_sentinelle->_parent->set_child(NULL, RIGHT);
		}

		void del_sentinelle()
		{
			unset_sentinelle();
			if (_sentinelle)
				del_node(_sentinelle);
			_sentinelle = NULL;
		}

		node* lower_bound(T value)
		{
			node* tmp = begin();
			for (; tmp != _sentinelle; tmp = tmp->next())
			{
				// std::cout << "compare " << value.first << " avec " << tmp->_value.first << std::endl;
				if (!_comp(tmp->_value, value))
					break;
				// std::cout << "test " << !_comp(tmp->_value, value) << std::endl;
			}
			return tmp;
		}

		node* upper_bound(T value)
		{
			node* tmp = begin();
			for (; tmp != _sentinelle; tmp = tmp->next())
			{
				if (_comp(value, tmp->_value))
					break;
			}
			return tmp;
		}

		void copy_tree(const Rbtree* src)
		{
			if (_root)
			{
				this->clear();
				_root = NULL;
				del_sentinelle();
				_size = 0;
			}
			if (src->size() <= 0)
				return;
			copy_rec(NULL, src->_root);
			_sentinelle = get_max();
			_size = src->_size;
		}

		void copy_rec(node* parent, node* src)
		{
			node* n;
			if (!src)
				return;
			n = make_node(*src);
			if (parent)
				parent->set_child(n, src->is_right());
			else
				_root = n;
			copy_rec(n, src->_child[LEFT]);
			copy_rec(n, src->_child[RIGHT]);
		}

		node*		insert(T value)
		{
			unset_sentinelle();
			node* n = make_node(node(value, _comp));
			node* ret;
			if (_root == NULL)
			{
				_root = n;
				n->_color = C_BLACK;
				_size++;
				set_sentinelle();
				return _root;
			}
			ret = _root->insert_node(n);
			if (ret != n)
			{
				del_node(n);
				_size++;
				set_sentinelle();
				return ret;
			}
			insertion_fixup(n);
			_size++;
			set_sentinelle();
			return n;
		}

		//===========================================================================
		
		void insertion_fixup(node* z)
		{
			while (z != _root && z->_parent->_color == C_RED)
			{
				int side = z->_parent->is_right();
				node* y = z->_parent->_parent->_child[!side];
				if (y != NULL && y->_color == C_RED)
				{
					z->_parent->_color = C_BLACK;
					y->_color = C_BLACK;
					z->_parent->_parent->_color = C_RED;
					z = z->_parent->_parent;
				}
				else
				{
					if (z == z->_parent->_child[!side])
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

		void	rotate(node* x, int side)
		{
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

		bool	is_black(node* ref)
		{
			if (ref && ref->_color == C_RED)
				return false;
			return true;
		}

		bool	is_red(node* ref)
		{
			return !is_black(ref);
		}

		//===========================================================================

		node*			swap_nodes(node* n, node* o)
		{
			node* tmp_n = make_node(*n);
			node* tmp_o = make_node(*o);
			_size += 2;
			if (!n->_parent) { _root = tmp_o; }
			if (!o->_parent) { _root = tmp_n; }
			tmp_n->copy_setting(o);
			tmp_o->copy_setting(n);
			n->_parent = NULL;
			del_node(n);
			o->_parent = NULL;
			del_node(o);
			return (tmp_n);
		}

		//===========================================================================

		void				delete_node(node* n)
		{
			unset_sentinelle();
			if (!n)
				throw std::out_of_range("Value not mapped within container");
			node *x, *y;

			y = n;
			int y_original_color = y->_color;
			if (n->_child[LEFT] == NULL)
			{
				x = n->_child[RIGHT];
				rbTransplant(n, x);
			}
			else if (n->_child[RIGHT] == NULL)
			{
				x = n->_child[LEFT];
				rbTransplant(n, n->_child[LEFT]);
			}
			else
			{
				y = n->_child[RIGHT]->min();
				y_original_color = y->_color;
				x = y->_child[RIGHT];
				if (y->_parent == n && x)
					x->_parent = y;
				else if (y->_parent != n)
				{
					rbTransplant(y, y->_child[RIGHT]);
					y->_child[RIGHT] = n->_child[RIGHT];
					y->_child[RIGHT]->_parent = y;
				}

				rbTransplant(n, y);
				y->_child[LEFT] = n->_child[LEFT];
				y->_child[LEFT]->_parent = y;
				y->_color = n->_color;
			}
			del_node(n);
			if (y_original_color == C_BLACK)
			{
				deleteFix(x);
			}
			set_sentinelle();
		}

		void deleteFix(node *x)
		{
			int side = LEFT;
			node *s;
			while (x && x != _root && x->_color == C_BLACK)
			{
				if (x->is_left() && get_sibling(x) != NULL)
				{
					s = get_sibling(x);
					if (s->_color == C_RED)
					{
						s->_color = C_BLACK;
						x->_parent->_color = C_RED;
						rotate(x->_parent, !side);
						s = get_sibling(x);
					}

					if (s->_child[side]->_color == C_BLACK && s->_child[!side]->_color == C_BLACK)
					{
						s->_color = C_RED;
						x = x->_parent;
					}
					else
					{
						if (s->_child[!side]->_color == C_BLACK)
						{
							s->_child[side]->_color = C_BLACK;
							s->_color = C_RED;
							rotate(s, side);
							s = get_sibling(x);
						}

						s->_color = x->_parent->_color;
						x->_parent->_color = C_BLACK;
						s->_child[!side]->_color = C_BLACK;
						rotate(x->_parent, !side);
						x = _root;
					}
				}
				else if (get_sibling(x) != NULL)
				{
					s = get_sibling(x);
					if (s->_color == C_RED)
					{
						s->_color = C_BLACK;
						x->_parent->_color = C_RED;
						rotate(x->_parent, side);
						s = get_sibling(x);
					}

					if (s->_child[!side]->_color == C_BLACK && s->_child[!side]->_color == C_BLACK)
					{
						s->_color = C_RED;
						x = x->_parent;
					}
					else
					{
						if (s->_child[side]->_color == C_BLACK)
						{
							s->_child[!side]->_color = C_BLACK;
							s->_color = C_RED;
							rotate(s, !side);
							s = x->_parent->_child[side];
						}

						s->_color = x->_parent->_color;
						x->_parent->_color = C_BLACK;
						s->_child[side]->_color = C_BLACK;
						rotate(x->_parent, side);
						x = _root;
					}
				}
			}
			if (x)
				x->_color = C_BLACK;
		}

		void rbTransplant(node *u, node *v)
		{
			if (u->_parent == NULL)
			{
				_root = v;
				if (v)
					v->_parent = NULL;
			}
			else
				u->_parent->set_child(v, u->is_right());
			u->_parent = NULL;
		}

		//===========================================================================

/*
		void				delete_node(node* n)
		{
			if (!n)
				throw std::out_of_range("Value not mapped within container");
			unset_sentinelle();
			node* c;
			if (n == _root && _size == 1)
			{
				_root = NULL;
				del_node(n);
				_size = 0;
				set_sentinelle();
				return;
			}
			
			if (n->_child[LEFT] && n->_child[RIGHT])
			{
				node* tmp = n->_child[LEFT]->max();
				n = swap_nodes(n, tmp);
			}
			c = n->_child[LEFT] ? n->_child[LEFT] : n->_child[RIGHT];
			if (n->_parent)
			{
				n->_parent->set_child(c, n->is_right());
				n->_parent = NULL;
			}
			else
			{
				c->_parent = NULL;
				_root = c;
			}
			del_node(n);
			set_sentinelle();
		}
*/

		node*					get_sibling(node* n)
		{
			if (n->_parent)
				return (n->_parent->_child[!n->is_right()]);
			return NULL;
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

		void	delete_rec(node* ref)
		{
			if (!ref)
				return;
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
			_size--;
		}
		
		//===========================================================================
		
		template <typename Temp>
		int get_max_depth(Temp ref, int depth = 0)
		{
			int d1 = depth;
			int d2 = depth;
			if (ref->_child[LEFT])
				d1 = get_max_depth(ref->_child[LEFT], depth + 1);
			if (ref->_child[RIGHT])
				d2 = get_max_depth(ref->_child[RIGHT], depth + 1);
			return ((d1 > d2) ? d1 : d2);
		}

		template <typename Temp>
		void print_tree_visual(Temp ref, int depth, std::ostream* os)
		{
			Temp new_stack;
			int space = 1;
			int half;
			int j = 0;

			for (int i = 0; i < depth; i++)
				space = (space * 2) + 1;
			half = (space - 1) / 2;
			for (int i = 0; i < half; i++)
				*os << " ";
			while ((int)ref.size() > j)
			{
				typename Temp::value_type n = ref.at(j);
				if (n == NULL)
				{
					*os << "□";
					new_stack.push_back(NULL);
					new_stack.push_back(NULL);
				}
				else
				{
					if (n->_color == C_RED)
						*os << RED;
					*os << n->_value.first << END;
					new_stack.push_back(n->_child[LEFT] ? n->_child[LEFT] : NULL);
					new_stack.push_back(n->_child[RIGHT] ? n->_child[RIGHT] : NULL);
				}
				j++;
				if ((int)ref.size() > j)
					for (int i = 0; i < space; i++)
						*os << (j%2 ? "-" : " ");
			}
			*os << std::endl;
			if (depth > 0)
				print_tree_visual(new_stack, depth - 1, os);
		}

		void print_tree(std::ostream* os = &(std::cout))
		{
			int senti = 1;
			if (_root == NULL || _root == _sentinelle)
			{
				std::cout << GREEN << "Empty tree" << END << std::endl;
				return;
			}
			if (_sentinelle == get_max())
				unset_sentinelle();
			else
				senti = 0;
			if (true)
			{
				ft::vector<node*>	pile;
				pile.push_back(_root);
				*os << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
				print_tree_visual(pile, get_max_depth(_root), os);
			}
			*os << "~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
			if (senti)
				set_sentinelle();
		}
		
		//===========================================================================

	private:
		unsigned long			_size;
		node*					_root;
		ft::stack<node*>		_mem_pile;
		allocator_type			_alloc;
		Compare					_comp;
		node*					_sentinelle;
	};
}

/*
		void				delete_node(node* n)
		{
			if (!n)
				throw std::out_of_range("Value not mapped within container");
			node* c;

			if (n == _root && _size == 1)
			{
				_root = NULL;
				del_node(n);
				return;
			}
			
			
			if (n->_child[LEFT] && n->_child[RIGHT])
			{
				node* tmp = n->_child[LEFT]->max();
				n->_value = tmp->_value;
				n = tmp;
			}

			c = n->_child[LEFT] ? n->_child[LEFT] : n->_child[RIGHT];

			if (is_red(n))
			{
				n->_parent->_child[n->is_right()] = NULL;
				del_node(n);
				return;
			}

			if (is_red(c))
			{
				n->_value = c->_value;
				del_node(c);
				return;
			}

			if (!c)
			{
				node* s = get_sibling(n);
				node* tmp = n;
				n = n->_parent;

				if (!s)
					throw std::out_of_range("Sibling doesn't exist");
				if (is_red(s))
				{
					s->_color = C_BLACK;
					n->_color = C_RED;
					rotate(n, tmp->is_left());
					s = get_sibling(tmp);
				}

				if (!s)
					throw std::out_of_range("Sibling doesn't exist V2");
				if (is_black(s) && is_black(s->_child[RIGHT]) && is_black(s->_child[LEFT]))
				{
					// s->_color = C_RED;
					// if (is_red(n))
					// 	n->_color = C_BLACK;
					// else
					// {
					// 	get_sibling(n)->_color = C_RED;
					// 	if (is_red(n->_parent))
					// 		n->_parent->_color = C_BLACK;
					// }
					// tmp->_color = C_BLACK;
					color_pushup(tmp);
				}

				if (is_black(s->_child[RIGHT]) && is_red(s->_child[LEFT]))
				{
					// swap_value(s, s->_child[LEFT]);
					// s->_child[LEFT]->_color = C_BLACK;
					// rotate(s->_parent, RIGHT);

					// n->_color = C_BLACK;
					// rotate(s, LEFT);
					// rotate(n, RIGHT);
					if (s->_child[tmp->is_left()])
					{
						rotate(n, LEFT);
						if (is_red(n))
						{
							s->_color = C_RED;
							n->_color = C_BLACK;
						}
						if (!get_sibling(n))
							throw std::out_of_range("Problem with sibling at 7.1");
						get_sibling(n)->_color = C_BLACK;
					}
					else
					{
						s->_child[LEFT]->_color = C_BLACK;
						rotate(s, LEFT);
						rotate(n, RIGHT);
						if (get_sibling(s) && is_red(get_sibling(s)))
						{
							get_sibling(s)->_color = C_BLACK;
							s->_parent->_color = C_RED;
						}
					}
				}

				if (is_red(s->_child[RIGHT]) && is_black(s->_child[LEFT]))
				{
					// swap_value(s, s->_child[RIGHT]);
					// rotate(s, RIGHT);
					if (s->_child[tmp->is_left()])
					{
						rotate(n, RIGHT);
						if (is_red(n))
						{
							s->_color = C_RED;
							n->_color = C_BLACK;
						}
						if (!get_sibling(n))
							throw std::out_of_range("Problem with sibling at 8.1");
						get_sibling(n)->_color = C_BLACK;
					}
					else
					{
						s->_child[RIGHT]->_color = C_BLACK;
						rotate(s, RIGHT);
						rotate(n, LEFT);
						if (get_sibling(s) && is_red(get_sibling(s)))
						{
							get_sibling(s)->_color = C_BLACK;
							s->_parent->_color = C_RED;
						}
					}
				}

				if (is_black(s) && is_red(s->_child[RIGHT]) && is_red(s->_child[LEFT]))
				{
					// bool side = tmp->is_right(); 
					// if (is_red(s->_child[!side]))
					// {
					// 	s->_child[side]->_color = C_BLACK;
					// 	s->_color = C_RED;
					// 	rotate(s, !side);
					// 	s = get_sibling(tmp);
					// 	n = tmp->_parent;
					// }
					// s->_color = n->_color;
					// n->_color = C_BLACK;
					// s->_child[!side]->_color = C_BLACK;
					// rotate(s, side);
					
					rotate(n, tmp->is_left());
					// PAS SUR DE CETTE CONDITION
					if (is_red(n) && is_red(get_sibling(n)))
						n->_parent->_color = C_RED;
					if (get_sibling(n))
						get_sibling(n)->_color = C_BLACK;
					n->_color = C_BLACK;
					
				}
				del_node(tmp);
			}
		}

		void					color_pushup(node* n)
		{
			node* s = NULL;
			if (n == NULL)
				return;
			if (n->_color == C_BLACK)
			{
				s = get_sibling(n);
				if (s)
				{
					if (is_red(s))
					{
						s->_color = C_BLACK;
						n->_parent->_color = C_RED;
						rotate(n->_parent, RIGHT);
						return color_pushup(n);
					}
		// DERNIERE CONDITION A L ARRACHE, A VOIR
					if (is_black(s) && s->_child[n->is_left()] && is_black(s->_child[n->is_left()]) && is_red(s->_child[n->is_right()]))
					{
						rotate(s, !n->is_left());
						s->_color = C_RED;
						s = s->_parent;
						s->_color = C_BLACK;
					}
					if (is_red(s->_child[n->is_left()]))
					{
		// throw std::out_of_range("test");
						s = n->_parent;
						rotate(s, n->is_left());
						if (is_red(s) && is_red(get_sibling(s)))
							s->_parent->_color = C_RED;
						get_sibling(s)->_color = C_BLACK;
						s->_color = C_BLACK;
						return;
					}
					else
						get_sibling(n)->_color = C_RED;
				}
				color_pushup(n->_parent);
			}
			else
				n->_color = C_BLACK;
		}
		*/

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
		// 		x = n->_child[RIGHT];
		// 		if (n == _root)
		// 			_root = x;
		// 		else
		// 			n->_parent->set_child(x, n->is_right());
		// 		delete_rec(n);
		// 	}
		// 	else
		// 	{
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

#endif