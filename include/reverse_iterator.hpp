#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "./iterator_traits.hpp"

namespace ft 
{
    template <class Iterator>
    class reverse_iterator 
    {
        private:
            Iterator    iterator;
        
        public:
            typedef Iterator    iterator_type;
            
            typedef typename ft::iterator_traits<iterator_type>::value_type 		value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type 	difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer 			pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference 			reference;
            typedef typename ft::iterator_traits<iterator_type>::iterator_category 	iterator_category;
        
		// constructor & destructor
        reverse_iterator(void) : iterator(iterator_type()) {}
        reverse_iterator(iterator_type i) : iterator(i) {}
        template <class _Some> // 라이브러리에는 _Some이 아니라 _Up
        reverse_iterator(const reverse_iterator<_Some>& i) : iterator(i.base()) {}
        ~reverse_iterator(void) {}

        // member functions
        template <class _Some>
        reverse_iterator& operator=(const reverse_iterator<_Some>& i) 
        {
            iterator = i.base();
            return *this;
        }
        iterator_type base(void) const 
        { 
            return iterator; 
        }
        reference operator*(void) const 
        {
            iterator_type tmp = iterator;
            return *--tmp;
        }
        reference operator[](difference_type n) const 
        {
            return *(*this + n);
        }
        pointer operator->(void) const 
        { 
            return &operator*(); 
        }
		
        // increment & decrement
        reverse_iterator& operator++(void) 
        {
            --iterator;
            return *this;
        }
        reverse_iterator& operator--(void) 
        {
            ++iterator;
            return *this;
        }
        reverse_iterator operator++(int) 
        {
            reverse_iterator tmp(*this);
            --iterator;
            return tmp;
        }
        reverse_iterator operator--(int) 
        {
            reverse_iterator tmp(*this);
            ++iterator;
            return tmp;
        }

        // arithmetic operators
        reverse_iterator operator+(difference_type n) const 
        {
            return reverse_iterator(iterator - n);
        }
        reverse_iterator operator-(difference_type n) const 
        {
            return reverse_iterator(iterator + n);
        }
        reverse_iterator& operator+=(difference_type n) 
        {
            iterator -= n;
            return *this;
        }
        reverse_iterator& operator-=(difference_type n) 
        {
            iterator += n;
            return *this;
        }
    }; // end of class reverse_iterator

    template <class Iterator>
    reverse_iterator<Iterator> operator+
        (typename reverse_iterator<Iterator>::difference_type n,
         const reverse_iterator<Iterator>& i) 
    {
        return reverse_iterator<Iterator>(i.base() - n);
    }

    template <class Ite1, class Ite2>
    typename reverse_iterator<Ite1>::difference_type operator-
        (const reverse_iterator<Ite1>& x,
         const reverse_iterator<Ite2>& y) 
    {
        return y.base() - x.base();
    }

	// comparison operators
    template <class Ite1, class Ite2>
    bool operator==(const reverse_iterator<Ite1>& x,
                    const reverse_iterator<Ite2>& y) 
    {
        return x.base() == y.base();
    }

    template <class Ite1, class Ite2>
    bool operator!=(const reverse_iterator<Ite1>& x,
                    const reverse_iterator<Ite2>& y) 
    {
        return x.base() != y.base();
    }

    template <class Ite1, class Ite2>
    bool operator<(const reverse_iterator<Ite1>& x,
                   const reverse_iterator<Ite2>& y) 
    {
        return x.base() > y.base();
    }

    template <class Ite1, class Ite2>
    bool operator<=(const reverse_iterator<Ite1>& x,
                    const reverse_iterator<Ite2>& y) 
    {
        return x.base() >= y.base();
    }

    template <class Ite1, class Ite2>
    bool operator>(const reverse_iterator<Ite1>& x,
                   const reverse_iterator<Ite2>& y) 
    {
        return x.base() < y.base();
    }

    template <class Ite1, class Ite2>
    bool operator>=(const reverse_iterator<Ite1>& x,
                    const reverse_iterator<Ite2>& y) 
    {
        return x.base() <= y.base();
    }
}  // end of namespace ft

#endif