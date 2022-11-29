#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <cstddef>
#include "./iterator_traits.hpp"

namespace ft
{
    template <typename Iterator>
    class reverse_iterator
        : public iterator<typename iterator_traits<Iterator>::iterator_category,
                          typename iterator_traits<Iterator>::value_type,
                          typename iterator_traits<Iterator>::difference_type,
                          typename iterator_traits<Iterator>::pointer,
                          typename iterator_traits<Iterator>::reference>
    {
    public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::value_type value_type;
        typedef typename iterator_traits<Iterator>::pointer pointer;
        typedef typename iterator_traits<Iterator>::reference reference;
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;

        reverse_iterator() : _current() {}

        ~reverse_iterator(){};

        explicit reverse_iterator(iterator_type it) : _current(it) {}

        template <typename Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) : _current(rev_it.base()) {}

        reverse_iterator &operator=(const reverse_iterator &x)
        {
            this->_current = x._current;
            return *this;
        }

        iterator_type base() const { return _current; }

        reference operator*() const
        {
            iterator_type tmp = _current;
            return *--tmp;
        }

        pointer operator->() const { return &(operator*()); }

        reverse_iterator &operator++()
        {
            --_current;
            return *this;
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            --_current;
            return tmp;
        }

        reverse_iterator &operator--()
        {
            ++_current;
            return *this;
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            ++_current;
            return tmp;
        }

        reverse_iterator operator+(difference_type n) const { return reverse_iterator(_current - n); }

        reverse_iterator &operator+=(difference_type n)
        {
            _current -= n;
            return *this;
        }

        reverse_iterator operator-(difference_type n) const { return reverse_iterator(_current + n); }

        reverse_iterator &operator-=(difference_type n)
        {
            _current += n;
            return *this;
        }

        reference operator[](difference_type n) const { return *(*this + n); }

    private:
        iterator_type _current;
    };

    template <typename Iterator>
    bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <typename Iterator>
    bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() != rhs.base();
    }

    template <typename Iterator>
    bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() > rhs.base();
    }

    template <typename Iterator>
    bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() >= rhs.base();
    }

    template <typename Iterator>
    bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() < rhs.base();
    }

    template <typename Iterator>
    bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() <= rhs.base();
    }

    template <typename Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
    {
        return reverse_iterator<Iterator>(rev_it.base() - n);
    }

    template <typename Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return rhs.base() - lhs.base();
    }
}
#endif // ********************************************** REVERSE_ITERATOR_HPP end //