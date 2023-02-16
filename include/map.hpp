#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <memory>
# include "./pair.hpp"
# include "./rbtree.hpp"
# include "./random_access_iterator.hpp"
# include "./reverse_iterator.hpp"
# include "./compare.hpp"

namespace ft 
{
	template <typename Key, typename T, class Compare = std::less<Key>,
				class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map 
	{
		public:
			typedef Key						key_type;
			typedef T 						mapped_type;
			typedef ft::pair<const Key, T>	value_type;
			typedef Compare 				key_compare;

			typedef Allocator									allocator_type;
			typedef typename allocator_type::pointer         	pointer;
			typedef typename allocator_type::const_pointer   	const_pointer;
			typedef typename allocator_type::reference       	reference;
			typedef typename allocator_type::const_reference 	const_reference;
			typedef typename allocator_type::size_type       	size_type;
			typedef typename allocator_type::difference_type 	difference_type;

			class value_compare 
				: public std::binary_function<value_type, value_type, bool>
			{
				protected:
					key_compare	_comp;

				public:
					// constructor & destructor
					value_compare(key_compare kc) : _comp(kc) {}
					~value_compare(void) {}

					// operator
					bool operator()(const value_type& x, const value_type& y) const
					{
						return _comp(x.first, y.first);
					}
					bool operator()(const value_type& x, const key_type& y) const 
					{
						return _comp(x.first, y);
					}
					bool operator()(const key_type& x, const value_type& y) const 
					{
						return _comp(x, y.first);
					}
			}; // end of class value_compare

			typedef typename ft::rbtree<value_type, key_type, value_compare, allocator_type>::iterator 			iterator;
			typedef typename ft::rbtree<value_type, key_type, value_compare, allocator_type>::const_iterator 	const_iterator;
			
			typedef ft::reverse_iterator<iterator> 			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> 	const_reverse_iterator;

		private:
			key_compare		_key_comp;
			value_compare	_val_comp;
			ft::rbtree<value_type, key_type, value_compare, allocator_type>	_tree;

		public:
			// OCCF: constructor, destructor, assignment
			map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _key_comp(comp), _val_comp(comp), _tree(_val_comp, alloc) {}
			template <class iIter>
			map(iIter first, iIter last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _key_comp(comp), _val_comp(comp), _tree(_val_comp, alloc)
			{
				insert(first, last);
			}
			map(const map& ref)
				: _key_comp(ref._key_comp), _val_comp(ref._val_comp), _tree(ref._tree) {}
			~map(void) {}

			map&	operator=(const map& ref)
			{
				if (this != &ref)
				{
					_key_comp = ref._key_comp;
					_val_comp = ref._val_comp;
					_tree = ref._tree;
				}
				return *this;
			}

			// iterators (const & non-const)
			iterator				begin(void)			{ return _tree.begin(); };
			iterator				end(void) 			{ return _tree.end(); };
			const_iterator			begin(void) const	{ return _tree.begin(); };
			const_iterator			end(void) const		{ return _tree.end(); };
			reverse_iterator		rbegin(void)		{ return reverse_iterator(end()); };
			reverse_iterator		rend(void)			{ return reverse_iterator(begin()); };
			const_reverse_iterator	rbegin(void) const	{ return reverse_iterator(end()); };
			const_reverse_iterator	rend(void) const	{ return reverse_iterator(begin()); };

			// size
			size_type	size(void) const		{ return _tree.size(); }
			size_type	max_size(void) const	{ return _tree.max_size(); }
			bool 		empty(void) const		{ return _tree.empty(); }

			// accessor
			mapped_type&		operator[](const key_type& key)
			{
				ft::pair<iterator, bool> p = insert(ft::make_pair(key, mapped_type()));
				return p.first->second;
			}
			mapped_type&		at(const key_type& key)
			{
				iterator	it = find(key);
				
				if (it == end())
					throw std::out_of_range("Error: ft::map: Out of Range");
				return it->second;
			}
			const mapped_type&	at(const key_type& key) const
			{
				iterator	it = find(key);
				
				if (it == end())
					throw std::out_of_range("Error: ft::map: Out of Range");
				return it->second;
			}

			// modifiers: insert, earse, swap, clear
			ft::pair<iterator, bool>	insert(const value_type& val)
			{
				return _tree.insert(val);
			}
			iterator	insert(iterator pos, const value_type& val)
			{
				return _tree.insert(pos, val);
			}
			template <class iIter>
			void		insert(iIter first, iIter last)
			{
				_tree.insert(first, last);
			}
			void		erase(iterator pos)
			{
				_tree.erase(pos);
			}
			void		erase(iterator first, iterator last)
			{
				_tree.erase(first, last);
			}
			size_type	erase(const key_type& key)
			{
				return _tree.erase(key);
			}
			void		swap(map& m)
			{
				_tree.swap(m._tree);
			}
			void		clear(void)
			{
				_tree.clear();
			}

			// compare: key_compare, value_compare
			key_compare		key_comp(void) const	{ return _key_comp; }
			value_compare 	value_comp(void) const	{ return _val_comp; }

			// functions : find, count, bound, equal_range
			iterator		find(const key_type& key) 
			{
				return _tree.find(key);
			}
			const_iterator	find(const key_type& key) const 
			{
				return _tree.find(key);
			}
			size_type		count(const key_type& key) const 
			{
				return !(find(key) == end());
			}
			iterator		lower_bound(const key_type& key) 
			{
				return _tree.lower_bound(key);
			}
			const_iterator	lower_bound(const key_type& key) const 
			{
				return _tree.lower_bound(key);
			}
			iterator 		upper_bound(const key_type& key) 
			{
				return _tree.upper_bound(key);
			}
			const_iterator	upper_bound(const key_type& key) const 
			{
				return _tree.upper_bound(key);
			}
			ft::pair<iterator, iterator>				equal_range(const key_type& key) 
			{
				return _tree.equal_range(key);
			}
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type& key) const 
			{
				return _tree.equal_range(key);
			}

			// allocator
			allocator_type	get_allocator(void) const	{ return _tree.get_allocator(); }
	}; // end of class map

	// comparison operator: ==, !=, <, <=, >, >=
	template <typename Key, typename T, class Compare, class Allocator>
	bool operator==(const ft::map<Key, T, Compare, Allocator>& x,
					const ft::map<Key, T, Compare, Allocator>& y) 
	{
		return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
	}

	template <typename Key, typename T, class Compare, class Allocator>
	bool operator!=(const ft::map<Key, T, Compare, Allocator>& x,
					const ft::map<Key, T, Compare, Allocator>& y) 
	{
		return !(x == y);
	}

	template <typename Key, typename T, class Compare, class Allocator>
	bool operator<(const ft::map<Key, T, Compare, Allocator>& x,
				const ft::map<Key, T, Compare, Allocator>& y) 
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <typename Key, typename T, class Compare, class Allocator>
	bool operator<=(const ft::map<Key, T, Compare, Allocator>& x,
					const ft::map<Key, T, Compare, Allocator>& y) 
	{
		return !(y < x);
	}

	template <typename Key, typename T, class Compare, class Allocator>
	bool operator>(const ft::map<Key, T, Compare, Allocator>& x,
				const ft::map<Key, T, Compare, Allocator>& y) 
	{
		return y < x;
	}

	template <typename Key, typename T, class Compare, class Allocator>
	bool operator>=(const ft::map<Key, T, Compare, Allocator>& x,
					const ft::map<Key, T, Compare, Allocator>& y) 
	{
		return !(x < y);
	}

	// swap
	template <typename Key, typename T, class Compare, class Allocator>
	void swap(ft::map<Key, T, Compare, Allocator>& x,
			ft::map<Key, T, Compare, Allocator>& y) 
	{
		x.swap(y);
	}
} // end of namespace ft

#endif