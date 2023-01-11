#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <iomanip>
# include <string>

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
		typedef				std::BidirectionalIterator<value_type>				iterator;
		typedef				std::BidirectionalIterator<const value_type>		const_iterator;
		typedef				ft::reverse_iterator<iterator>						reverse_iterator;
		typedef				ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef	typename	ft::iterator_traits<iterator>::difference_type		difference_type;
		typedef typename	allocator_type::size_type							size_type;
		
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
		
		void clear() {
			_rb_tree->clear();
		}

		key_compare key_comp() const {
			return (_comp);
		}

		value_compare value_comp() const {
			return (value_compare(_comp));
		}

	private:
		typedef	ft::Rbtree<value_type, ft::forbid_double_class_tag, value_compare, Alloc>		rbtree;
		typedef typename allocator_type::template rebind<tree_type>::other					tree_allocator_type;

		key_compare			_comp;
		tree_allocator_type _tree_alloc;
		rbtree				_rb_tree;
	}
}

#endif