#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "RBTree/rbtree.hpp"
# include "RBTree/node.hpp"

namespace ft
{
	template <	class Key,
				class T,
				typename Compare = std::less<T>,
				class Alloc = std::allocator<T> >
	class map
	{
	public:
		typedef				Key													key_type;
		typedef				T													mapped_type;
		typedef				ft::pair<const key_type, mapped_type>				value_type;
		typedef				Compare												key_compare;
		typedef				Alloc												allocator_type;
		typedef typename	allocator_type::reference							reference;
		typedef typename	allocator_type::const_reference						const_reference;
		typedef typename	allocator_type::pointer								pointer;
		typedef typename	allocator_type::const_pointer						const_pointer;
		typedef				ft::BidirectionalIterator<value_type>				iterator;
		typedef				ft::BidirectionalIterator<const value_type>			const_iterator;
		typedef				ft::reverse_iterator<iterator>						reverse_iterator;
		typedef				ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef	typename	ft::iterator_traits<iterator>::difference_type		difference_type;
		typedef typename	allocator_type::size_type							size_type;
		typedef 			ft::Node<T, Compare, ft::forbid_double_class_tag>	node;
		
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

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _comp(comp), _tree_alloc(alloc), _rb_tree(_tree_alloc.allocate(1))
		{
			_tree_alloc.construct(_rb_tree, rbtree(value_comp(), alloc));
		}

		template <class InputIterator>
		map (	InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _comp(comp), _tree_alloc(alloc), _rb_tree(_tree_alloc.allocate(1))
		{
			_tree_alloc.construct(_rb_tree, rbtree(value_comp(), alloc));
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
			_tree_alloc.construct(_rb_tree, *rhs._rb_tree);
			_comp = rhs._comp;
			return (*this);
		}

		mapped_type& operator[] (const key_type& k) {
			return (_rb_tree->insert(ft::make_pair<Key, T>(k, mapped_type()))).second;
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
			\\ TODO
		}
		
		void clear() {
			_rb_tree->clear();
		}

		bool empty() const {
			return (_rb_tree->empty());
		}

		unsigned long size() const {
			return (_rb_tree->size());
		}

		unsigned long max_size() const {
			return (_rb_tree->max_size());
		}

		key_compare key_comp() const {
			return (_comp);
		}

		value_compare value_comp() const {
			return (value_compare(_comp));
		}

		iterator	begin() {
			return (iterator(_rb_tree->min()));
		}
		iterator	end() {
			return (iterator(_rb_tree->max()));
		}
		const_iterator	begin() const {
			return (const_iterator(_rb_tree->min()));
		}
		const_iterator	end() const {
			return (const_iterator(_rb_tree->max()));
		}
		reverse_iterator rbegin() {
			return (reverse_iterator(_rb_tree->max()));
		};
		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(_rb_tree->max()));
		};
		reverse_iterator rend() {
			return (reverse_iterator(_rb_tree->min()));
		};
		const_reverse_iterator rend() const {
			return (const_reverse_iterator(_rb_tree->min()));
		};

	private:
		typedef	ft::Rbtree<value_type, ft::forbid_double_class_tag, value_compare, Alloc>		rbtree;
		typedef typename allocator_type::template rebind<tree_type>::other					tree_allocator_type;

		key_compare			_comp;
		tree_allocator_type _tree_alloc;
		rbtree				_rb_tree;
	}
}

#endif