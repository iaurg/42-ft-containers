#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "./iterator_traits.hpp"
#include "./reverse_iterator.hpp"
#include <cstddef>

namespace ft
{
    template <typename Iterator>
    class random_access_iterator
        : public iterator<
              typename iterator_traits<Iterator>::iterator_category,
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

        random_access_iterator() : _current() {}

        ~random_access_iterator(){};

        explicit random_access_iterator(iterator_type it) : _current(it) {}

        template <typename Iter>
        random_access_iterator(const random_access_iterator<Iter> &rev_it) : _current(rev_it.base()) {}

        random_access_iterator &operator=(const random_access_iterator &x)
        {
            this->_current = x._current;
            return *this;
        }

        iterator_type base() const { return _current; }

        reference operator*() const { return *_current; }

        pointer operator->() const { return &operator*(); }

        random_access_iterator &operator++()
        {
            ++_current;
            return *this;
        }

        random_access_iterator operator++(int)
        {
            random_access_iterator tmp = *this;
            ++_current;
            return tmp;
        }

        random_access_iterator &operator--()
        {
            --_current;
            return *this;
        }

        random_access_iterator operator--(int)
        {
            random_access_iterator tmp = *this;
            --_current;
            return tmp;
        }

        random_access_iterator operator+(difference_type n) const
        {
            random_access_iterator tmp = *this;
            return tmp += n;
        }

        random_access_iterator operator-(difference_type n) const
        {
            random_access_iterator tmp = *this;
            return tmp -= n;
        }

        random_access_iterator &operator+=(difference_type n)
        {
            _current += n;
            return *this;
        }

        random_access_iterator &operator-=(difference_type n)
        {
            _current -= n;
            return *this;
        }

        reference operator[](difference_type n) const { return *(*this + n); }

        // COMPARISON OPERATORS
        bool operator==(const random_access_iterator &x) const { return _current == x._current; }

        bool operator!=(const random_access_iterator &x) const { return _current != x._current; }

        bool operator<(const random_access_iterator &x) const { return _current < x._current; }

        bool operator<=(const random_access_iterator &x) const { return _current <= x._current; }

        bool operator>(const random_access_iterator &x) const { return _current > x._current; }

        bool operator>=(const random_access_iterator &x) const { return _current >= x._current; }

    private:
        iterator_type _current;
    };

    template <typename Iterator>
    random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator> &x)
    {
        return x + n;
    }

    template <typename Iterator>
    typename random_access_iterator<Iterator>::difference_type operator-(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return lhs.base() - rhs.base();
    }

    template <typename Iterator>
    bool operator==(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <typename Iterator>
    bool operator!=(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return lhs.base() != rhs.base();
    }

    template <typename Iterator>
    bool operator<(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return lhs.base() < rhs.base();
    }

    template <typename Iterator>
    bool operator<=(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return lhs.base() <= rhs.base();
    }

    template <typename Iterator>
    bool operator>(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return lhs.base() > rhs.base();
    }

    template <typename Iterator>
    bool operator>=(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return lhs.base() >= rhs.base();
    }
}
#endif // ********************************************** ITERATOR_HPP end //