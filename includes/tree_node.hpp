#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

/**
 * @brief Struct for node of tree
 *
 * @tparam T
 */
template <typename T>
struct TREE_Node
{
public:
    typedef T value_type;
    value_type value;
    TREE_Node *left;
    TREE_Node *right;
    TREE_Node *parent;

    TREE_Node() : value(), left(NULL), right(NULL), parent(NULL) {}

    TREE_Node(const value_type &val) : value(val), left(NULL), right(NULL), parent(NULL) {}

    TREE_Node(const value_type &val, TREE_Node *left, TREE_Node *right, TREE_Node *parent) : value(val), left(left), right(right), parent(parent) {}

    TREE_Node(const TREE_Node &other) : value(other.value), left(other.left), right(other.right), parent(other.parent) {}

    TREE_Node &operator=(const TREE_Node &other)
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

    ~TREE_Node() {}

    bool operator==(const TREE_Node &other) const
    {
        return (value == other.value && left == other.left && right == other.right && parent == other.parent);
    }
};

#endif // ********************************************** TREE_NODE_HPP end //