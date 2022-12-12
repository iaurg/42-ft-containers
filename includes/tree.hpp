#ifndef TREE_HPP
#define TREE_HPP

#include <functional>
#include <memory>
#include <cstddef>
#include "tree_iterator.hpp"
#include "pair.hpp"
#include "tree_node.hpp"

namespace ft
{
    template <class T, class Compare = std::less<T>, class Node = TREE_Node<T>,
              class Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    class tree
    {
    public:
        typedef tree self;
        typedef self &self_ref;
        typedef T value_type;
        typedef Node node_type;
        typedef Node *node_pointer;
        typedef Node &node_ref;
        typedef Alloc allocator_type;
        typedef Node_Alloc node_allocator_type;
        typedef ft::tree_iterator<Node, node_type> iterator;
        typedef ft::tree_const_iterator<Node, node_type> const_iterator;
        typedef size_t size_type;

    private:
        node_pointer _root;
        node_pointer _end;
        size_type _size;
        Compare _comp;
        allocator_type _alloc;
        node_allocator_type _node_alloc;

    public:
        /**
         * @brief Construct a new empty tree object
         *
         */
        tree() : _root(NULL), _end(NULL), _size(0), _comp(), _alloc(), _node_alloc()
        {
            _end = _node_alloc.allocate(1);
            _node_alloc.construct(_end, node_type());
            _end->parent = _end;
            _end->left = _end;
            _end->right = _end;
        }

        /**
         * @brief Destroy the tree object
         *
         */
        ~tree()
        {
            _node_alloc.destroy(_end);
            _node_alloc.deallocate(_end, 1);
        }

        /**
         * @brief Insert a new node into the tree
         *
         * @param val
         * @return ft::pair<iterator, bool>
         */
        ft::pair<iterator, bool> insert(const value_type &val)
        {
            node_pointer new_node = _node_alloc.allocate(1);
            _node_alloc.construct(new_node, node_type(val));
            new_node->parent = _end;
            new_node->left = _end;
            new_node->right = _end;
            if (_root == NULL)
            {
                _root = new_node;
                _size++;
                return ft::make_pair<iterator, bool>(iterator(new_node), true);
            }
            node_pointer tmp = _root;
            while (tmp != _end)
            {
                if (_comp(val, tmp->data))
                {
                    if (tmp->left == _end)
                    {
                        tmp->left = new_node;
                        new_node->parent = tmp;
                        _size++;
                        return ft::make_pair<iterator, bool>(iterator(new_node), true);
                    }
                    tmp = tmp->left;
                }
                else if (_comp(tmp->data, val))
                {
                    if (tmp->right == _end)
                    {
                        tmp->right = new_node;
                        new_node->parent = tmp;
                        _size++;
                        return ft::make_pair<iterator, bool>(iterator(new_node), true);
                    }
                    tmp = tmp->right;
                }
                else
                {
                    _node_alloc.destroy(new_node);
                    _node_alloc.deallocate(new_node, 1);
                    return ft::make_pair<iterator, bool>(iterator(tmp), false);
                }
            }
            return ft::make_pair<iterator, bool>(iterator(new_node), true);
        }

        /**
         * @brief Remove a node by key
         *
         * @param node_ptr
         * @param key
         *
         */
        void remove(node_pointer node_ptr, const value_type &key)
        {
            if (node_ptr == _end)
                return;
            if (_comp(key, node_ptr->data))
                remove(node_ptr->left, key);
            else if (_comp(node_ptr->data, key))
                remove(node_ptr->right, key);
            else
            {
                if (node_ptr->left == _end)
                {
                    if (node_ptr->parent->left == node_ptr)
                        node_ptr->parent->left = node_ptr->right;
                    else
                        node_ptr->parent->right = node_ptr->right;
                    node_ptr->right->parent = node_ptr->parent;
                    _node_alloc.destroy(node_ptr);
                    _node_alloc.deallocate(node_ptr, 1);
                    _size--;
                }
                else if (node_ptr->right == _end)
                {
                    if (node_ptr->parent->left == node_ptr)
                        node_ptr->parent->left = node_ptr->left;
                    else
                        node_ptr->parent->right = node_ptr->left;
                    node_ptr->left->parent = node_ptr->parent;
                    _node_alloc.destroy(node_ptr);
                    _node_alloc.deallocate(node_ptr, 1);
                    _size--;
                }
                else
                {
                    node_pointer tmp = node_ptr->right;
                    while (tmp->left != _end)
                        tmp = tmp->left;
                    node_ptr->data = tmp->data;
                    remove(tmp, tmp->data);
                }
            }
        }

        /**
         * @brief Get highest node
         *
         * @param node_ptr
         * @return node_pointer
         */
        node_pointer highest(node_pointer node_ptr)
        {
            if (node_ptr == _end)
                return _end;
            while (node_ptr->right != _end)
                node_ptr = node_ptr->right;
            return node_ptr;
        }

        /**
         * @brief Get lowest node
         *
         * @param node_ptr
         * @return node_pointer
         */
        node_pointer lowest(node_pointer node_ptr)
        {
            if (node_ptr == _end)
                return _end;
            while (node_ptr->left != _end)
                node_ptr = node_ptr->left;
            return node_ptr;
        }

        /**
         * @brief Search for a node by key
         *
         * @param key
         * @return node_pointer
         */
        node_pointer search(const value_type &key)
        {
            node_pointer tmp = _root;
            while (tmp != _end)
            {
                if (_comp(key, tmp->data))
                    tmp = tmp->left;
                else if (_comp(tmp->data, key))
                    tmp = tmp->right;
                else
                    return tmp;
            }
            return _end;
        }

        /**
         * @brief Max size of the tree
         *
         */
        size_type max_size() const
        {
            return _node_alloc.max_size();
        }
    };
} // namespace ft
#endif // ********************************************** TREE_HPP end //