#ifndef TREE_HPP
#define TREE_HPP

#include "tree_iterator.hpp"
#include "pair.hpp"

/**
 * @brief Struct for node of binary search tree
 *
 * @tparam T
 */
template <typename T>
struct BST_Node
{
public:
    typedef T value_type;
    value_type value;
    BST_Node *left;
    BST_Node *right;
    BST_Node *parent;

    BST_Node() : value(), left(NULL), right(NULL), parent(NULL) {}

    BST_Node(const value_type &val) : value(val), left(NULL), right(NULL), parent(NULL) {}

    BST_Node(const value_type &val, BST_Node *left, BST_Node *right, BST_Node *parent) : value(val), left(left), right(right), parent(parent) {}

    BST_Node(const BST_Node &other) : value(other.value), left(other.left), right(other.right), parent(other.parent) {}

    BST_Node &operator=(const BST_Node &other)
    {
        if (this != &other)
        {
            value = other.value;
            left = other.left;
            right = other.right;
            parent = other.parent;
        }
        return *this;
    }

    ~BST_Node() {}

    bool operator==(const BST_Node &other) const
    {
        return (value == other.value && left == other.left && right == other.right && parent == other.parent);
    }
};

namespace ft
{
    template <class T, class Compare = std::less<T>, class Node = BST_Node<T>,
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
        typedef ft::tree_iterator<value_type, node_type> iterator;
        // typedef ft::tree_const_iterator<value_type, node_type, node_pointer, node_ref> const_iterator;
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
         * @brief Create node with value and insert it into tree
         *
         */
        ft::pair<iterator, bool> insert(const value_type &val)
        {
            node_pointer new_node = _node_alloc.allocate(1);
            _node_alloc.construct(new_node, node_type(val));
            if (_root == NULL)
            {
                _root = new_node;
                _end = new_node;
                _size++;
                return ft::make_pair(iterator(new_node), true);
            }
            node_pointer current = _root;
            while (current != NULL)
            {
                if (_comp(val, current->value))
                {
                    if (current->left == NULL)
                    {
                        current->left = new_node;
                        new_node->parent = current;
                        _size++;
                        return ft::make_pair(iterator(new_node), true);
                    }
                    current = current->left;
                }
                else if (_comp(current->value, val))
                {
                    if (current->right == NULL)
                    {
                        current->right = new_node;
                        new_node->parent = current;
                        _size++;
                        return ft::make_pair(iterator(new_node), true);
                    }
                    current = current->right;
                }
                else
                {
                    _node_alloc.destroy(new_node);
                    _node_alloc.deallocate(new_node, 1);
                    return ft::make_pair(iterator(current), false);
                }
            }
            return ft::make_pair(iterator(new_node), true);
        }
    };
}
#endif // ********************************************** TREE_HPP end //