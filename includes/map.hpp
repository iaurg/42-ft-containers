#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
    {
    public:
        // MEMBER TYPES ========================================================
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::size_type size_type;
    };
}

#include "map.tpp"

#endif // ********************************************** MAP_HPP end //