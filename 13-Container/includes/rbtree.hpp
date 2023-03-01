#ifndef RBTREE_HPP
# define RBTREE_HPP

# include "node.hpp"
# include "stack.hpp"
# include "vector.hpp"
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
				if (!_comp(tmp->_value, value))
					break;
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

					if (is_black(s->_child[side]) && is_black(s->_child[!side]))
					{
						s->_color = C_RED;
						x = x->_parent;
					}
					else
					{
						if (is_black(s->_child[!side]))
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

					if (is_black(s->_child[side]) && is_black(s->_child[!side]))
					{
						s->_color = C_RED;
						x = x->_parent;
					}
					else
					{
						if (is_black(s->_child[side]))
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

	private:
		unsigned long			_size;
		node*					_root;
		ft::stack<node*>		_mem_pile;
		allocator_type			_alloc;
		Compare					_comp;
		node*					_sentinelle;
	};
}

#endif