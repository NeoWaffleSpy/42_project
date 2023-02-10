#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <fstream>
# include <iomanip>
# include <string>
# include "RBTree/rbtree.hpp"
# include "RBTree/node.hpp"
# include "Iterators/bidirectional_iterator.hpp"

# define PRINT 1

namespace ft
{
	template <	class Key,
				class T,
				typename Compare = std::less<Key>,
				class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
	public:
		typedef				Key																	key_type;
		typedef				T																	mapped_type;
		typedef				ft::pair<const key_type, mapped_type>								value_type;
		typedef				Compare																key_compare;
		typedef				Alloc																allocator_type;

		class value_compare {
				friend class map;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
			public:
				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
		};

		typedef 			ft::Node<value_type, value_compare, ft::forbid_double_class_tag>	node;
		typedef typename	allocator_type::reference											reference;
		typedef typename	allocator_type::const_reference										const_reference;
		typedef typename	allocator_type::pointer												pointer;
		typedef typename	allocator_type::const_pointer										const_pointer;
		typedef				ft::bidirectional_iterator<value_type, node>						iterator;
		typedef				ft::bidirectional_iterator<value_type, node>						const_iterator;
		typedef				ft::reverse_iterator<iterator>										reverse_iterator;
		typedef				ft::reverse_iterator<const_iterator>								const_reverse_iterator;
		typedef	typename	ft::iterator_traits<iterator>::difference_type						difference_type;
		typedef typename	allocator_type::size_type											size_type;

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _comp(comp), _tree_alloc(alloc), _rb_tree(_tree_alloc.allocate(1))
		{
			_tree_alloc.construct(_rb_tree, rbtree(value_comp()));
		}

		template <class InputIterator>
		map (	InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _comp(comp), _tree_alloc(alloc), _rb_tree(_tree_alloc.allocate(1))
		{
			_tree_alloc.construct(_rb_tree, rbtree(value_comp()));
			for (; first != last; first++)
				_rb_tree->insert(*first);
		}

		map (const map& from): _comp(from._comp), _tree_alloc(from._tree_alloc), _rb_tree(_tree_alloc.allocate(1))
		{
			_tree_alloc.construct(_rb_tree, *from._rb_tree);
		}

		~map()
		{
			_tree_alloc.destroy(_rb_tree);
			_tree_alloc.deallocate(_rb_tree, 1);
		}

		map& operator= (const map& rhs)
		{
			if (this == &rhs)
				return (*this);
			if (_rb_tree)
				_tree_alloc.destroy(_rb_tree);
			_tree_alloc.construct(_rb_tree, *rhs._rb_tree);
			_comp = rhs._comp;
			return (*this);
		}

		mapped_type& operator[] (const key_type& k)
		{
			node* n = _rb_tree->find(ft::make_pair<key_type, mapped_type>(k, mapped_type()));
			if (n == NULL)
				return (_rb_tree->insert(ft::make_pair<key_type, mapped_type>(k, mapped_type())))->_value.second;
			return n->_value.second;
		}

		ft::pair<iterator,bool> insert(const value_type& val)
		{
			unsigned long last_size = size();
			node* ptr = _rb_tree->insert(val);
			ft::pair<iterator, bool> result = ft::make_pair<iterator, bool>(iterator(ptr), true);

			if (size() == last_size)
				result.second = false;

			return (result);
		}
		
		iterator insert(iterator pos, const value_type& val)
		{
			(void)pos;
			return (insert(val).first);
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			for (; first != last; first++)
				_rb_tree->insert(*first);
		}

		void erase (iterator position)
		{
			_rb_tree->delete_node(position.get_node());
		}

		/*

		size_type erase (const key_type& k) {
			if (!_rb_tree->find(ft::make_pair(k, mapped_type())))
				return 0;
			_rb_tree->delete_node(_rb_tree->find(ft::make_pair(k, mapped_type())));
			return 1;
		}*/

		size_type erase (const key_type& k) {
			if (!_rb_tree->find(ft::make_pair(k, mapped_type())))
				return 0;
			_rb_tree->delete_node(_rb_tree->insert(ft::make_pair<key_type, mapped_type>(k, mapped_type())));
			return 1;
		}

		void erase (iterator first, iterator last) {
			iterator next = first;
			for (; first != last; first = next) {
				++next;
				_rb_tree->delete_node(first.get_node());
			}
		}
		
		void swap (map& x) {
			key_compare		_comp_temp = _comp;
			allocator_type	_tree_alloc_temp = _tree_alloc;
			rbtree*		_rb_tree_temp = _rb_tree;

			_comp = x._comp;
			_tree_alloc = x._tree_alloc;
			_rb_tree = x._rb_tree;

			x._comp = _comp_temp;
			x._tree_alloc = _tree_alloc_temp;
			x._rb_tree = _rb_tree_temp;
		}
		
		void					clear()					{ _rb_tree->clear();					}
		bool					empty()			const	{ return (_rb_tree->size() ? 0 : 1);	}
		unsigned long			size()			const	{ return (_rb_tree->size());			}
		unsigned long			max_size()		const	{ return (_rb_tree->max_size());		}
		key_compare				key_comp()		const	{ return (_comp);						}
		value_compare			value_comp()	const	{ return (value_compare(_comp));		}
		allocator_type			get_allocator() const	{ return (_tree_alloc);					}

		iterator				begin()					{ return (iterator(_rb_tree->begin()));				}
		iterator				end()					{ return (iterator(_rb_tree->end()));				}
		const_iterator			begin()			const	{ return (const_iterator(_rb_tree->begin()));			}
		const_iterator			end()			const	{ return (const_iterator(_rb_tree->end()));			}
		reverse_iterator		rbegin()				{ return (reverse_iterator(_rb_tree->end()));		}
		reverse_iterator		rend()					{ return (reverse_iterator(_rb_tree->begin()));		}
		const_reverse_iterator	rbegin()		const	{ return (const_reverse_iterator(_rb_tree->end()));	}
		const_reverse_iterator	rend()			const	{ return (const_reverse_iterator(_rb_tree->begin()));	}
		
		size_type		count		(const key_type& k) const	{ return (_rb_tree->find(ft::make_pair<key_type, mapped_type>(k, mapped_type())) ? 1 : 0);					}
		iterator		find		(const key_type& k)			{ return (		iterator(_rb_tree->find(ft::make_pair<key_type, mapped_type>(k, mapped_type()))));			}
		const_iterator	find		(const key_type& k)	const	{ return (const_iterator(_rb_tree->find(ft::make_pair<key_type, mapped_type>(k, mapped_type()))));			}
		iterator		lower_bound (const key_type& k)			{ return (		iterator(_rb_tree->lower_bound(ft::make_pair<key_type, mapped_type>(k, mapped_type()))));	}
		const_iterator	lower_bound (const key_type& k)	const	{ return (const_iterator(_rb_tree->lower_bound(ft::make_pair<key_type, mapped_type>(k, mapped_type()))));	}
		iterator		upper_bound (const key_type& k)			{ return (		iterator(_rb_tree->upper_bound(ft::make_pair<key_type, mapped_type>(k, mapped_type()))));	}
		const_iterator	upper_bound (const key_type& k)	const	{ return (const_iterator(_rb_tree->upper_bound(ft::make_pair<key_type, mapped_type>(k, mapped_type()))));	}

		ft::pair<iterator,iterator>				equal_range (const key_type& k)			{ return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));				}
		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k)	const	{ return ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)); }

		void	dump(std::string const& filename)
		{
			std::ofstream	ofs(filename.c_str());

			if (!ofs.is_open())
				return ;

			ofs << "graph g {\n";
			ofs << "\tnode [shape=plaintext, fontcolor=white, height=.1];\n\n";
			// ofs << "\t" << _sentinelStart->dump(false);
			// ofs << "\t" << _sentinelEnd->dump(false);
			dumpTree(ofs, _rb_tree->_root);
			ofs << "}";

			ofs.close();
		}

		void	dumpTree(std::ofstream &ofs, node *n)
		{
			ofs << "\t" << n->dump(true);

			// if (n->left && n->left != _sentinelStart)
				dumpTree(ofs, n->left);
			// if (n->right && n->right != _sentinelStart)
				dumpTree(ofs, n->right);
		}

		void	print_tree_advanced() const
		{
			const_iterator	it = begin();

			std::cout << "Tree :";
			if (it != end())
			{
				for (; it != end(); it++)
				{
					std::cout << " " << *it << ": " << it.get_node() << std::endl
					<< "parent: " << it.get_node()->_parent << std::endl
					<< "left: " << it.get_node()->_child[LEFT] << std::endl
					<< "right: " << it.get_node()->_child[RIGHT] << std::endl;
				}
			}
			else
				std::cout << "Tree is empty";
			std::cout << std::endl;

			const_reverse_iterator	c_rit = rbegin();
			std::cout << "Tree :";
			if (c_rit != rend())
				for (; c_rit != rend(); c_rit++)
					std::cout << " " << *c_rit;
			else
				std::cout << "Tree is empty";
			std::cout << std::endl;
		}

		void	print_tree() const
		{
			const_iterator	it = begin();

			std::cout << "Tree :";
			if (it != end())
				for (; it != end(); it++)
					std::cout << " " << *it << ": " << it.get_node();
			else
				std::cout << "Tree is empty";
			std::cout << std::endl;

			const_reverse_iterator	c_rit = rbegin();
			std::cout << "Tree :";
			if (c_rit != rend())
				for (; c_rit != rend(); c_rit++)
					std::cout << " " << *c_rit;
			else
				std::cout << "Tree is empty";
			std::cout << std::endl;
		}
		
	private:
		typedef	ft::Rbtree<value_type, ft::forbid_double_class_tag, value_compare>	rbtree;
		typedef typename allocator_type::template rebind<rbtree>::other				tree_allocator_type;

		key_compare			_comp;
		tree_allocator_type _tree_alloc;
		rbtree*				_rb_tree;
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return !(operator==(lhs, rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return !(operator<(rhs, lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return (operator<(rhs, lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
		return !(operator<(lhs, rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) {
		x.swap(y);
	}
	
	template<typename Key, typename T, typename Compare, typename Alloc>
	std::ostream	&operator<<(std::ostream &os, ft::map<Key, T, Compare, Alloc> const& map)
	{
		if (map.empty() && PRINT)
			return (os << "Empty map");
		else if(map.empty())
			return (os);

		for (typename ft::map<Key, T, Compare, Alloc>::const_iterator it = map.begin(), it1 = ++map.begin();
			it != map.end(); it++)
		{
			os << *(it);
			if (it1 != map.end())
			{
				os << " ";
				it1++;
			}
		}
		return (os);
	}
}

#endif