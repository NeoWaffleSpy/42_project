#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "RBTree/rbtree.hpp"
# include "RBTree/node.hpp"
# include "Iterators/bidirectional_iterator.hpp"

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
				value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
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
		typedef				ft::bidirectional_iterator<node>									iterator;
		typedef				ft::bidirectional_iterator<const node>								const_iterator;
		typedef				ft::reverse_iterator<iterator>										reverse_iterator;
		typedef				ft::reverse_iterator<const_iterator>								const_reverse_iterator;
		typedef	typename	ft::iterator_traits<iterator>::difference_type						difference_type;
		typedef typename	allocator_type::size_type											size_type;

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _comp(comp), _tree_alloc(alloc), _rb_tree(_tree_alloc.allocate(1))
		{
			std::cout << "Create map 1" << std::endl;
			_tree_alloc.construct(_rb_tree, rbtree(value_comp()));
		}

		template <class InputIterator>
		map (	InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _comp(comp), _tree_alloc(alloc), _rb_tree(_tree_alloc.allocate(1))
		{
			std::cout << "Create map 2" << std::endl;
			_tree_alloc.construct(_rb_tree, rbtree(value_comp()));
			for (; first != last; first++)
				_rb_tree->insert(*first);
		}

		map (const map& from): _comp(from._comp), _tree_alloc(from._tree_alloc), _rb_tree(_tree_alloc.allocate(1))
		{
			std::cout << "Create map 3" << std::endl;
			_tree_alloc.construct(_rb_tree, *from._rb_tree);
		}

		~map()
		{
			_tree_alloc.destroy(_rb_tree);
			_tree_alloc.deallocate(_rb_tree, 1);
			std::cout << "Destroy map" << std::endl;
		}

		map& operator= (const map& rhs)
		{
			if (this == &rhs)
				return (*this);
			_tree_alloc.construct(_rb_tree, *rhs._rb_tree);
			_comp = rhs._comp;
			return (*this);
		}

		mapped_type& operator[] (const key_type& k) {
			return (_rb_tree->insert(ft::make_pair<key_type, mapped_type>(k, mapped_type()))).second;
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
			_rb_tree->delete_node(*position);
		}

		size_type erase (const key_type& k) {
			return (_rb_tree->delete_node(ft::make_pair<key_type, mapped_type>(k, mapped_type())));
		}

		void erase (iterator first, iterator last) {
			iterator next = first;
			for (; first != last; first = next) {
				++next;
				_rb_tree->delete_node(*first);
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
		
		void					clear()					{ _rb_tree->clear();				}
		bool					empty()			const	{ return (_rb_tree->empty());		}
		unsigned long			size()			const	{ return (_rb_tree->size());		}
		unsigned long			max_size()		const	{ return (_rb_tree->max_size());	}
		key_compare				key_comp()		const	{ return (_comp);					}
		value_compare			value_comp()	const	{ return (value_compare(_comp));	}
		allocator_type			get_allocator() const	{ return (_tree_alloc);				}

		iterator				begin()					{ return (iterator(_rb_tree->begin()));				}
		iterator				end()					{ return (iterator(_rb_tree->end()));				}
		const_iterator			begin()			const	{ return (const_iterator(_rb_tree->begin()));			}
		const_iterator			end()			const	{ return (const_iterator(_rb_tree->end()));			}
		reverse_iterator		rbegin()				{ return (reverse_iterator(_rb_tree->end()));		}
		reverse_iterator		rend()					{ return (reverse_iterator(_rb_tree->begin()));		}
		const_reverse_iterator	rbegin()		const	{ return (const_reverse_iterator(_rb_tree->end()));	}
		const_reverse_iterator	rend()			const	{ return (const_reverse_iterator(_rb_tree->begin()));	}
		
		size_type		count		(const key_type& k) const	{ return (_rb_tree->find(ft::make_pair<key_type, mapped_type>(k, mapped_type())) ? 1 : 0);										}
		iterator		find		(const key_type& k)			{ return (iterator(_rb_tree->find(ft::make_pair<key_type, mapped_type>(k, mapped_type()))));				}
		const_iterator	find		(const key_type& k)	const	{ return (const_iterator(_rb_tree->find(ft::make_pair<key_type, mapped_type>(k, mapped_type()))));			}
		iterator		lower_bound (const key_type& k)			{ return (iterator(_rb_tree->lower_bound(ft::make_pair<key_type, mapped_type>(k, mapped_type()))));			}
		const_iterator	lower_bound (const key_type& k)	const	{ return (const_iterator(_rb_tree->lower_bound(ft::make_pair<key_type, mapped_type>(k, mapped_type()))));	}
		iterator		upper_bound (const key_type& k)			{ return (iterator(_rb_tree->upper_bound(ft::make_pair<key_type, mapped_type>(k, mapped_type()))));			}
		const_iterator	upper_bound (const key_type& k)	const	{ return (const_iterator(_rb_tree->upper_bound(ft::make_pair<key_type, mapped_type>(k, mapped_type()))));	}

		ft::pair<iterator,iterator>				equal_range (const key_type& k)			{ return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));				}
		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k)	const	{ return ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)); }

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
}

#endif