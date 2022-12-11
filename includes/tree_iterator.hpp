#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template <typename T, class Compare>
    class tree_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
    {
    public:
        typedef typename T::value_type value_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer pointer;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type difference_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;
    };
}
#endif // ********************************************** TREE_ITERATOR_HPP end //