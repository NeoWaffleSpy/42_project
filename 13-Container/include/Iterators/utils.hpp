#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>
# include <limits>
# include <sstream>
# include <typeinfo>
# include <iostream>

# define BLACK "\e[1;30m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define MAGENTA "\e[1;35m"
# define CYAN "\e[1;36m"
# define WHITE "\e[1;37m"
# define BLINK_RED "\x1B[5;31m"
# define BLINK_BLUE "\x1B[5;34m"
# define BLINK_CYAN "\x1B[5;36m"
# define END "\e[0m"

/*
** @brief Type of the null pointer constant.
** Permetted implicit conversions to null pointer ,
** similary conversions for all type of contant null pointer.
**
** From : (Take a look)
** https://www.amazon.com/dp/0201924889
*/
static class nullptr_t
{
    public:
        template<class T>
        operator T*() const { return (0); }

        template<class C, class T>
        operator T C::*() const { return (0); }

    private:
        void operator&() const;

} u_nullptr = {};

namespace ft
{

	template< class T > struct remove_cv                { typedef T type; };
	template< class T > struct remove_cv<const T>       { typedef T type; };

    template <typename T>
    std::string to_string(T n)
    {
        std::ostringstream ss;
        ss << n;
        return (ss.str());
    }
    
    /*
    ** Base class for standard binary function objects.
    ** (Doc = http://www.cplusplus.com/reference/functional/binary_function/?kw=binary_function)
    ** It have no operator "()" like functin objects, 
    ** it is up to the class deriving from it to define it.
    ** It just has 3 public data memebers that are typedefs of the
    ** template parameters.
    ** (the operator "()", permet to use a class with the same syntax
    ** as a function call).
    */
    template <class Arg1, class Arg2, class Result>
    struct binary_function
    {
        typedef Arg1 first_argument_type;
        typedef Arg2 second_argument_type;
        typedef Result result_type;
    };
    
    /*
    ** A binary function object class who will return
    ** whether the first arguement compares less than the second.
    ** (using "<" operator).
    */
    template <class T>
    struct less : binary_function<T, T, bool>
    {
        bool operator() (const T& x, const T& y) const { return (x < y); }
    };

    /*
    ** Couple a pair of values, which may be of different types
    ** (T1 and T2)
    */
    template <class T1, class T2>
    struct pair
    {
	public :
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair() : first(), second()
		{}

		template<class U, class V>
		pair (const pair<U, V>& pr) : first(pr.first), second(pr.second)
		{}

		pair (const first_type& a, const second_type& b) : first(a), second(b)
		{}

		pair& operator= (const pair& pr)
		{
			if (*this == pr)
				return (*this);
			this->first = pr.first;
			this->second = pr.second;
			return (*this);
		}
    };

    template <class T1, class T2>
    bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }

    template <class T1, class T2>
    bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return (rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
    {
        return !(lhs < rhs);
    }

	template <class InputIterator1, class InputIterator2>
	bool equal( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1 && first2!=last2)
		{
			if (*first1 != *first2)
				return false;
			++first1;
			++first2;
		}
		if (first1 == last1 && first2 == last2)
			return true;
		return false;
	}
    
    /*
    ** @bref Construct a pair object with
    ** "x" and "y".
    **
    ** @param x, y elements. (can have different types).
    ** @return the pair object.
    */
    template <class T1, class T2>
    ft::pair<T1,T2> make_pair(T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    }
    
    /*
    ** @brief The type T is enabled as member type enable_if::type
    ** if Cond is true. Otherwise, enable_if::type is not defined.
    ** Usefull when a particular condition is not met, in this case
    ** the member enable_if::type will ne be defined and attempting
    ** to compile using to should fail. (If this is use in template
    ** of a function, for exemple, like the type is not defined the 
    ** compiler will not compile and use the function).
    **
    ** @template_param Cond A compile-time constant of type bool.
    ** @template_param T A type.
    */
    template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };

    /*
    ** @brief The basic struct of is_integral has
    ** has a boolean ("value") that contain true if the type is from.
    ** the list, otherwise false.
    */
    template <bool is_integral, typename T>
    struct is_integral_res 
    {
        typedef typename ft::remove_cv<T>::type type;
        static const bool value = is_integral;
    };

    /*
    ** @brief default template of the structure is_integral_type.
    ** If the type given in argument is from the list, the structure
    ** will be overide by nexts, in according to it type.
    ** If the type given is argument isn't in the list, 
    ** stocked value will be false. So it's not a integral type.
    */
    template <typename>
    struct is_integral_type : public is_integral_res<false, bool> {};

    template <>
    struct is_integral_type<bool> : public is_integral_res<true, bool> {};

    template <>
    struct is_integral_type<char> : public is_integral_res<true, char> {};

    template <>
    struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

    template <>
    struct is_integral_type<short int> : public is_integral_res<true, short int> {};
    
    template <>
    struct is_integral_type<int> : public is_integral_res<true, int> {};

    template <>
    struct is_integral_type<long int> : public is_integral_res<true, long int> {};

    template <>
    struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

    template <>
    struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};

    template <>
    struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

    template <>
    struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

    template <>
    struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
    
    template <>
    struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

    /*
    ** @brief Give a structure who contain is the
    ** typename given in template is integral or not,
    ** stocked in "value".
    */
    template <typename T>
    struct is_integral : public is_integral_type<typename ft::remove_cv<T>::type> { };

    /*
    ** @brief Empty class to identify the category of an
    ** "random access iterator". This type of iterator is the
    ** most complete iterators. Is particularity is that, it
    ** allow to access elements at an arbitrary offset.
    ** Take a look :
    ** http://www.cplusplus.com/reference/iterator/RandomAccessIterator/
    */
    class random_access_iterator_tag { };

    /*
    ** @brief Empty class to identify the category of an
    ** "bidirectional iterator". Bidirectional can be used to access
    ** the sequence of elements in a range in both directions.
    ** Take a look :
    ** http://www.cplusplus.com/reference/iterator/BidirectionalIterator/
    */
    class bidirectional_iterator_tag { };

    /*
    ** @brief Empty class to identify the category of an
    ** "forward iterator". Forward iterator can be used to 
    ** access the sequence of elements in a range in the direction
    ** that goes (begin to end).
    ** Take a look :
    ** http://www.cplusplus.com/reference/iterator/ForwardIterator/
    */
    class forward_iterator_tag { };

    /*
    ** @brief Empty class to identify the category of an
    ** "input iterator". Input iterator can be used in sequential
    ** input operations, values are read only once and the iterator
    ** is icremented.
    ** Take a look :
    ** http://www.cplusplus.com/reference/iterator/InputIterator/
    */
    class input_iterator_tag { };

    /*
    ** @brief Empty class to identify the category of an
    ** "output iterator". Output iterator can be used in sequential
    ** output operations, values pointed by the iterator is written
    ** a value only once and the iterator is incremented.
    ** Take a look :
    ** http://www.cplusplus.com/reference/iterator/OutputIterator/
    */
    class output_iterator_tag { };

    /*
    ** @brief Validity of an iterator from is tag.
    ** This is the base struct for all is_..._iterator_tag.
    ** A boolean is defined by the template and saved in
    ** structure. Type too.
    */
    template <bool is_valid, typename T>
    struct valid_iterator_tag_res { typedef T type; const static bool value = is_valid; };
    
    /*
    ** @brief Basic to check if the typename given
    ** is an input_iterator. Based on valid_iterator_tag_res.
    ** In this if the typename is not from the possible
    ** input iterator form, validity is set to false.
    */
    template <typename T>
	struct is_input_iterator_tagged									: public valid_iterator_tag_res<false, T> { };

    template <>
    struct is_input_iterator_tagged<ft::random_access_iterator_tag>	: public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };

    template <>
    struct is_input_iterator_tagged<ft::bidirectional_iterator_tag>	: public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

    template <>
    struct is_input_iterator_tagged<ft::forward_iterator_tag>		: public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

    template <>
    struct is_input_iterator_tagged<ft::input_iterator_tag>			: public valid_iterator_tag_res<true, ft::input_iterator_tag> { };

    /*
    ** @brief This will return a structure
    ** that contain a boolean "value" true if the
    ** iterator given is tagged with a ft iterator
    ** tag, otherwise "value" is false.
    */
    template <typename T>
    struct is_ft_iterator_tagged									: public valid_iterator_tag_res<false, T> { };
    
    template <>
    struct is_ft_iterator_tagged<ft::random_access_iterator_tag>	: public valid_iterator_tag_res<true, ft::random_access_iterator_tag> { };
    
    template <>
    struct is_ft_iterator_tagged<std::random_access_iterator_tag>	: public valid_iterator_tag_res<true, std::random_access_iterator_tag> { };

    template <>
    struct is_ft_iterator_tagged<ft::bidirectional_iterator_tag>	: public valid_iterator_tag_res<true, ft::bidirectional_iterator_tag> { };

    template <>
    struct is_ft_iterator_tagged<std::bidirectional_iterator_tag>	: public valid_iterator_tag_res<true, std::bidirectional_iterator_tag> { };

    template <>
    struct is_ft_iterator_tagged<ft::forward_iterator_tag>			: public valid_iterator_tag_res<true, ft::forward_iterator_tag> { };

    template <>
    struct is_ft_iterator_tagged<std::forward_iterator_tag>			: public valid_iterator_tag_res<true, std::forward_iterator_tag> { };

    template <>
    struct is_ft_iterator_tagged<ft::input_iterator_tag>			: public valid_iterator_tag_res<true, ft::input_iterator_tag> { };

    template <>
    struct is_ft_iterator_tagged<std::input_iterator_tag>			: public valid_iterator_tag_res<true, std::input_iterator_tag> { };

    template <>
    struct is_ft_iterator_tagged<ft::output_iterator_tag>			: public valid_iterator_tag_res<true, ft::output_iterator_tag> { };

    template <>
    struct is_ft_iterator_tagged<std::output_iterator_tag>			: public valid_iterator_tag_res<true, std::output_iterator_tag> { };

	/*
	** @brief Custom class that define that
	** the existence of double keys is
	** allowed in the binary tree.
	*/
    class allow_double_class_tag { };

	/*
	** @brief Custom class that define that
	** the existence of double keys is
	** forbidden in the binary tree.
	*/
    class forbid_double_class_tag { };

    template <bool is_valid, bool is_class, typename T>
    struct double_class_tag
	{
		typedef T type;
		const static bool valid_class = is_class;
		const static bool value = is_valid;
	};

    /*
    ** @brief This will return a structure
    ** that contain a boolean "value" false if the
    ** tag forbid the existence of doubles in
	** the binary tree.
    */
    template <typename T>
	struct is_double_class_tag										: public double_class_tag<true, false, T> { };

    template <>
    struct is_double_class_tag<ft::allow_double_class_tag>			: public double_class_tag<true, true, ft::allow_double_class_tag> { };

    template <>
    struct is_double_class_tag<ft::forbid_double_class_tag>			: public double_class_tag<false, true, ft::forbid_double_class_tag> { };

    /*
    ** @Brief Invalid iterator Exception.
    ** Based on std::exception. Called when
    ** the iterator tested does not meet demand.
    */
    template <typename T>
    class InvalidIteratorException : public std::exception
    {
        private:
            std::string _msg;
        
        public :
            InvalidIteratorException () throw() { _msg = "Is invalid iterator tag : " + std::string(typeid(T).name()); }
            InvalidIteratorException (const InvalidIteratorException&) throw() {}
            InvalidIteratorException& operator= (const InvalidIteratorException&) throw() {}
            virtual ~InvalidIteratorException() throw() {}
            virtual const char* what() const throw() { return (_msg.c_str()); }
    };

    /*
    ** @brief Iterator traits class defining properties of
    ** iterators. In this, iterator_traits obtains information
    ** from Iterator class in template argument.
    */
    template <class Iterator> struct iterator_traits
    {
        typedef typename Iterator::difference_type       difference_type;
        typedef typename Iterator::value_type            value_type;
        typedef typename Iterator::pointer               pointer;
        typedef typename Iterator::reference             reference;
        typedef typename Iterator::iterator_category     iterator_category;
    };
    
    /*
    ** @brief Iterator traits class defining properties of
    ** iterators. This create a default operation with an
    ** object (first argument in tempate argument).
    */
    template <class T> struct iterator_traits<T*>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef ft::random_access_iterator_tag  iterator_category;
    };
    
    /*
    ** @brief Iterator traits class defining properties of
    ** iterators. This create a default operation with a
    ** const object (first argument in tempate argument).
    */
    template <class T> class iterator_traits<const T*>
    {
        typedef ptrdiff_t                       difference_type;
        typedef T                               value_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef ft::random_access_iterator_tag  iterator_category;
    };

    /*
    ** @brief Give a difference_type defined in ft::iterator_traits
    ** that's the difference of address in memory
    ** between last and first iterator.
    **
    ** @param first The first iterator.
    ** @param last The last iterator.
    ** @return The difference.
    */
    template<class InputIterator>
    typename ft::iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last)
    {
        typename ft::iterator_traits<InputIterator>::difference_type rtn = 0;
        while (first != last)
        {
            first++;
            rtn++;
        }
        return (rtn);
    }

    /*
    ** @brief Base class for iterator, not really usefull, but type
    ** defined can be use for iterator_traits. An iterator permeted to
    ** take any element range in an object and using a set of operators.
    */
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    class iterator
    {
        public:
            typedef T           value_type;
            typedef Distance    difference_type;
            typedef Pointer     pointer;
            typedef Reference   reference;
            typedef Category    iterator_category;
    };

    template <class T>
    class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
    {  
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer               pointer;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference             reference;
        
        private:
            pointer _elem;
    };

    template <class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator    iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category                       iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type                              value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type                         difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer                                 pointer;
            typedef typename ft::iterator_traits<Iterator>::reference                               reference;
            
            reverse_iterator() : _elem()
            {}

            explicit reverse_iterator (iterator_type it) : _elem(it)
            {}

            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it) : _elem(rev_it.base())
            {}

            virtual ~reverse_iterator() {}

            iterator_type base() const { return (_elem); }
            typename reverse_iterator<Iterator>::difference_type  base2() const { return (_elem); }

            reference operator*() const
            {
                iterator_type tmp = _elem;
                return (*(--tmp));
            }

            reverse_iterator operator+ (difference_type n) const { return (reverse_iterator(_elem - n)); }
            reverse_iterator operator- (difference_type n) const { return (reverse_iterator(_elem + n)); }

            reverse_iterator& operator++()
            {
                --_elem;
                return (*this);
            }

            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }

            reverse_iterator& operator+= (difference_type n)
            {
                _elem -= n;
                return (*this);
            }

            reverse_iterator& operator--()
            {
                ++_elem;
                return (*this);
            }
			
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            }
			
            reverse_iterator& operator-= (difference_type n)
            {
                _elem += n;
                return (*this);
            }
			
            pointer operator->() const { return &(operator*()); }

            reference operator[] (difference_type n) const { return (this->base()[-n - 1]); }

        private:
            iterator_type     _elem;
    };

    template <class Iterator>
    bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() == rhs.base()); }

    template <class Iterator_L, class Iterator_R>
    bool operator== (const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs)
	{ return (lhs.base() == rhs.base()); }

    template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() != rhs.base()); }

    template <class Iterator_L, class Iterator_R>
	bool operator!= (const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs)
	{ return (lhs.base() != rhs.base()); }

    template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() > rhs.base()); }

    template <class Iterator_L, class Iterator_R>
	bool operator< (const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs)
	{ return (lhs.base() > rhs.base()); }

    template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() >= rhs.base()); }

    template <class Iterator_L, class Iterator_R>
	bool operator<= (const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs)
	{ return (lhs.base() >= rhs.base()); }

    template <class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() < rhs.base()); }

    template <class Iterator_L, class Iterator_R>
	bool operator> (const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs)
	{ return (lhs.base() < rhs.base()); }

    template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (lhs.base() <= rhs.base()); }

    template <class Iterator_L, class Iterator_R>
	bool operator>= (const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs)
	{ return (lhs.base() <= rhs.base()); }

    template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{ return (rev_it + n); }

    template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{ return (rhs.base() - lhs.base()); }

    template <class Iterator_L, class Iterator_R>
	typename reverse_iterator<Iterator_L>::difference_type operator- (const reverse_iterator<Iterator_L>& lhs, const reverse_iterator<Iterator_R>& rhs)
	{ return (rhs.base() - lhs.base()); }

    /* Lexicographical comparison */

    /*
    ** @brief Return true if the range [first1, last2) compare
    ** lexicographically lest than the range [first2, last2).
    **
    ** @param first1, last1 the start and the end of the first range.
    ** @param first2, last2 the start and the end of the second range.
    ** @return true if the first range compares lexicographically less
    ** than the second, false otherwise.
    */
    template <class InputIterator1, class InputIterator2>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                        InputIterator2 first2, InputIterator2 last2)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || *first2 < *first1)
					return false;
                else if (*first1 < *first2)
					return true;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }

    /*
    ** @brief Return true if the range [first1, last2) compare
    ** lexicographically lest than the range [first2, last2).
    ** The comparision is effectued by "comp".
    **
    ** @param first1, last1 the start and the end of the first range.
    ** @param first2, last2 the start and the end of the second range.
    ** @param comp the function that will compare.
    ** @return true if the first range compares lexicographically less
    ** than the second, false otherwise.
    */
    template <class InputIterator1, class InputIterator2, class Compare>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                        InputIterator2 first2, InputIterator2 last2,
                                        Compare comp)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || comp(*first2, *first1)) return false;
                else if (comp(*first1, *first2)) return true;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }
	
    template <typename T>
    struct BST_Node
    {
        public :

            /* First template argument, the type of stocked value */
            typedef T   value_type;

            value_type value;
            BST_Node* parent;
            BST_Node* left;
            BST_Node* right;

            /*
            ** @brief Default.
            ** Create a BST_Node with default initisialized value.
            ** Left and right branch pointer to a "u_nullptr" (t_nullptr).
            */
            BST_Node () : value(), parent(u_nullptr), left(u_nullptr), right(u_nullptr)
            {}

            /*
            ** @brief Default.
            ** Create a BST_Node with default initisialized value.
            ** Left and right branch pointer to a "u_nullptr" (t_nullptr).
            */
            BST_Node (BST_Node* parent = u_nullptr, BST_Node* left = u_nullptr, BST_Node* right = u_nullptr) : value(), parent(parent), left(left), right(right)
            {}
            
            /*
            ** @brief Value.
            ** Create a BST_Node with value defined by a copy of "val".
            ** Left and right branch pointer to a "u_nullptr" (t_nullptr).
            **
            ** @param val the value to copy.
            */
            BST_Node (const value_type& val, BST_Node* parent = u_nullptr, BST_Node* left = u_nullptr, BST_Node* right = u_nullptr)
            : value(val), parent(parent), left(left), right(right)
            {}

            /*
            ** @brief Copy.
            ** Create a BST_Node that a copy of "nd".
            ** The value is initalized by a copy of "nd" value.
            ** Left and right branch point to the same than "nb" branches.
            **
            ** @param nd the BST_Node to copy.
            */
            BST_Node (const BST_Node& nd) : value(nd.value), parent(nd.parent), left(nd.left), right(nd.right)
            {}

            virtual ~BST_Node() {}

            /*
            ** @brief Equal operator.
            ** Create a BST_Node that a copy of "nd".
            ** The value is initalized by a copy of "nd" value.
            ** Left and right branch point to the same than "nb" branches.
            **
            ** @param nd the BST_Node to copy.
            ** @return *this.
            */
            BST_Node &operator=(const BST_Node& nd)
            {
                if (nd == *this)
                    return (*this);
                
                this->value = nd.value;
                this->parent = nd.parent;
                this->left = nd.left;
                this->right = nd.right;
                
                return (*this);
            }

            /*
            ** @brief Compare two BST_Node to know
            ** if they contains the same value.
            **
            ** @param nd the BST_Node to compare.
            ** @return true if the value are the same,
            ** otherwise no.
            */
            bool operator==(const BST_Node& nd)
            {
                if (value == nd.value)
                    return (true);
                return (false);
            }
    };

    /* List Node : */
    template <class Data_T>
    struct Doubly_Linked_Node 
    {
        public :

            Doubly_Linked_Node  *prev;
            Doubly_Linked_Node  *next;
            Data_T              data;

            /*
            ** @brief Default:
            ** Create a node with next and prev
            ** value that pointing to u_nullptr.
            ** data is unitialized.
            */
            Doubly_Linked_Node()
            :
                prev(u_nullptr),
                next(u_nullptr)
            {}

            /*
            ** @brief Data init:
            ** Create a node with next and prev
            ** value that pointing to u_nullptr.
            ** data is itialized to "val".
            **
            ** @param val the data of this node.
            */
            Doubly_Linked_Node(const Data_T& val) : prev(u_nullptr), next(u_nullptr), data(val)
            {}

            /*
            ** @brief Init:
            ** Create a node with next and prev
            ** value that pointing to parameters "prev" & "next".
            ** data is itialized to "val".
            **
            ** @param val the data of this node.
            ** @param prev,next the previous and next node. 
            */
            Doubly_Linked_Node(const Data_T& val,
                Doubly_Linked_Node *prev, Doubly_Linked_Node *next)
            :
                prev(prev),
                next(next),
                data(val)
            {}
    };
} /* End of namespace */

# endif