#ifndef PAIR_TPP
#define PAIR_TPP

#include "pair.hpp"

namespace ft
{
    template <typename T1, typename T2>
    pair<T1, T2>::pair(void) : first(), second() {}

    template <typename T1, typename T2>
    pair<T1, T2>::pair(const T1 &a, const T2 &b) : first(a), second(b) {}

    template <typename T1, typename T2>
    template <class U, class V>
    pair<T1, T2>::pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

    template <typename T1, typename T2>
    pair<T1, T2>::~pair(void) {}

    template <typename T1, typename T2>
    pair<T1, T2> &pair<T1, T2>::operator=(pair<T1, T2> const &pr)
    {
        if (this != &pr)
        {
            this->first = pr.first;
            this->second = pr.second;
        }
        return (*this);
    }

    template <class T1, class T2>
    inline bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    inline bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T1, class T2>
    inline bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }

    template <class T1, class T2>
    inline bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T1, class T2>
    inline bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (rhs < lhs);
    }

    template <class T1, class T2>
    inline bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T1, class T2>
    inline ft::pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (ft::pair<T1, T2>(x, y));
    }
}

#endif // ********************************************** PAIR_TPP end //
