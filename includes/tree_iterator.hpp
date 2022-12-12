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

        T *_node;
        T *_root;
        Compare _compare;

        tree_iterator() : _node(NULL), _root(NULL), _compare() {}

        tree_iterator(T *node, T *root, Compare compare) : _node(node), _root(root), _compare(compare) {}

        tree_iterator(const tree_iterator &other) : _node(other._node), _root(other._root), _compare(other._compare) {}

        tree_iterator &operator=(const tree_iterator &other)
        {
            if (this != &other)
            {
                _node = other._node;
                _root = other._root;
                _compare = other._compare;
            }
            return *this;
        }

        ~tree_iterator() {}

        bool operator==(const tree_iterator &other) const
        {
            return (_node == other._node && _root == other._root && _compare == other._compare);
        }

        bool operator!=(const tree_iterator &other) const
        {
            return (_node != other._node || _root != other._root || _compare != other._compare);
        }

        reference operator*() const
        {
            return _node->value;
        }

        pointer operator->() const
        {
            return &(_node->value);
        }

        tree_iterator &operator++()
        {
            if (_node->right)
            {
                _node = _node->right;
                while (_node->left)
                    _node = _node->left;
            }
            else
            {
                T *parent = _node->parent;
                while (parent && _node == parent->right)
                {
                    _node = parent;
                    parent = parent->parent;
                }
                _node = parent;
            }
            return *this;
        }

        tree_iterator operator++(int)
        {
            tree_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        tree_iterator &operator--()
        {
            if (_node == NULL)
            {
                _node = _root;
                while (_node->right)
                    _node = _node->right;
            }
            else if (_node->left)
            {
                _node = _node->left;
                while (_node->right)
                    _node = _node->right;
            }
            else
            {
                T *parent = _node->parent;
                while (parent && _node == parent->left)
                {
                    _node = parent;
                    parent = parent->parent;
                }
                _node = parent;
            }
            return *this;
        }

        tree_iterator operator--(int)
        {
            tree_iterator tmp(*this);
            --(*this);
            return tmp;
        }
    };

    template <typename T, class Compare>
    class tree_const_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
    {
    public:
        typedef typename T::value_type value_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer pointer;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference reference;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type difference_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category iterator_category;

        T *_node;
        T *_root;
        Compare _compare;

        tree_const_iterator() : _node(NULL), _root(NULL), _compare() {}

        tree_const_iterator(T *node, T *root, Compare compare) : _node(node), _root(root), _compare(compare) {}

        tree_const_iterator(const tree_const_iterator &other) : _node(other._node), _root(other._root), _compare(other._compare) {}

        tree_const_iterator(const tree_iterator<T, Compare> &other) : _node(other._node), _root(other._root), _compare(other._compare) {}

        tree_const_iterator &operator=(const tree_const_iterator &other)
        {
            if (this != &other)
            {
                _node = other._node;
                _root = other._root;
                _compare = other._compare;
            }
            return *this;
        }

        ~tree_const_iterator() {}

        bool operator==(const tree_const_iterator &other) const
        {
            return (_node == other._node && _root == other._root && _compare == other._compare);
        }

        bool operator!=(const tree_const_iterator &other) const
        {
            return (_node != other._node || _root != other._root || _compare != other._compare);
        }

        reference operator*() const
        {
            return _node->value;
        }

        pointer operator->() const
        {
            return &(_node->value);
        }

        tree_const_iterator &operator++()
        {
            if (_node->right)
            {
                _node = _node->right;
                while (_node->left)
                    _node = _node->left;
            }
            else
            {
                T *parent = _node->parent;
                while (parent && _node == parent->right)
                {
                    _node = parent;
                    parent = parent->parent;
                }
                _node = parent;
            }
            return *this;
        }

        tree_const_iterator operator++(int)
        {
            tree_const_iterator tmp(*this);
            ++(*this);
            return tmp;
        }

        tree_const_iterator &operator--()
        {
            if (_node == NULL)
            {
                _node = _root;
                while (_node->right)
                    _node = _node->right;
            }
            else if (_node->left)
            {
                _node = _node->left;
                while (_node->right)
                    _node = _node->right;
            }
            else
            {
                T *parent = _node->parent;
                while (parent && _node == parent->left)
                {
                    _node = parent;
                    parent = parent->parent;
                }
                _node = parent;
            }
            return *this;
        }

        tree_const_iterator operator--(int)
        {
            tree_const_iterator tmp(*this);
            --(*this);
            return tmp;
        }
    };
} // namespace ft
#endif // ********************************************** TREE_ITERATOR_HPP end //