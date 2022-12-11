#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>
#include "tree.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "pair.hpp"
namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
    {
        // TREE NODE ===========================================================

    private:
        typedef ft::tree<std::pair<const Key, T>, Compare, Alloc> _tree;
        typedef typename _tree::iterator _tree_iterator;
        typedef typename _tree::const_iterator _tree_const_iterator;
        typedef ft::reverse_iterator<_tree_iterator> reverse_iterator;
        typedef ft::reverse_iterator<_tree_const_iterator> const_reverse_iterator;
        typedef typename ft::iterator_traits<_tree_iterator>::difference_type difference_type;

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
        typedef typename allocator_type::size_type size_type;
        // typedef typename allocator_type::difference_type difference_type;

        // MEMBER CLASSES ======================================================

        class value_compare : public std::binary_function<value_type, value_type, bool>
        {
            friend class map<Key, T, Compare, Alloc>;

        protected:
            Compare comp;
            explicit value_compare(Compare c) : comp(c) {}

        public:
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };

    public:
        // MEMBER FUNCTIONS ====================================================

        /**
         * @brief Constructs a map container object, initializing its contents depending on the constructor version used:
         *
         */
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());

        /**
         * @brief Constructs a map container object, initializing its contents depending on the constructor version used:
         *
         */
        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());

        /**
         * @brief Constructs a map container object, initializing its contents depending on the constructor version used:
         *
         */
        map(const map &x);

        /**
         * @brief Destroys the map container object.
         *
         */
        ~map();

        /**
         * @brief Assigns new contents to the map container, replacing its current contents, and modifying its size accordingly.
         *
         */
        map &operator=(const map &x);

        // ITERATORS ===========================================================

        /**
         * @brief Returns an iterator referring to the first element in the map container.
         *
         */
        _tree_iterator begin();

        /**
         * @brief Returns an iterator referring to the past-the-end element in the map container.
         *
         */
        _tree_iterator end();

        /**
         * @brief Returns a _tree_const_iterator referring to the first element in the map container.
         *
         */
        _tree_const_iterator begin() const;

        /**
         * @brief Returns a _tree_const_iterator referring to the past-the-end element in the map container.
         *
         */
        _tree_const_iterator end() const;

        /**
         * @brief Returns a reverse_iterator pointing to the last element in the map container.
         *
         */
        reverse_iterator rbegin();

        /**
         * @brief Returns a reverse_iterator pointing to the theoretical element preceding the first element in the map container.
         *
         */
        reverse_iterator rend();

        /**
         * @brief Returns a const_reverse_iterator pointing to the last element in the map container.
         *
         */
        const_reverse_iterator rbegin() const;

        /**
         * @brief Returns a const_reverse_iterator pointing to the theoretical element preceding the first element in the map container.
         *
         */
        const_reverse_iterator rend() const;

        // CAPACITY ============================================================

        /**
         * @brief Returns whether the map container is empty.
         *
         */
        bool empty() const;

        /**
         * @brief Returns the number of elements in the map container.
         *
         */
        size_type size() const;

        /**
         * @brief Returns the maximum number of elements that the map container can hold.
         *
         */
        size_type max_size() const;

        // ELEMENT ACCESS ======================================================

        /**
         * @brief Accesses the specified element with bounds checking.  If k matches the
         * key of an element in the container, the function returns a reference to its
         * mapped value.
         *
         */
        mapped_type &operator[](const key_type &k);

        // MODIFIERS ===========================================================

        /**
         * @brief Inserts an element into the map container, if the container doesn't already contain an element with an equivalent key.
         *
         */
        ft::pair<_tree_iterator, bool> insert(const value_type &val);

        /**
         * @brief Inserts an element into the map container, if the container doesn't already contain an element with an equivalent key.
         *
         */
        _tree_iterator insert(_tree_iterator position, const value_type &val);

        /**
         * @brief Inserts elements from range [first,last) into the map.
         *
         */
        template <class InputIterator>
        void insert(InputIterator first, InputIterator last);

        /**
         * @brief Erases an element from the map container.
         *
         */
        void erase(_tree_iterator position);

        /**
         * @brief Erases an element from the map container.
         *
         */
        size_type erase(const key_type &k);

        /**
         * @brief Erases elements from the map container.
         *
         */
        void erase(_tree_iterator first, _tree_iterator last);

        /**
         * @brief Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
         *
         */
        void swap(map &x);

        /**
         * @brief Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
         *
         */
        void clear();

        // OBSERVERS ===========================================================

        /**
         * @brief Returns a copy of the comparison object used by the container to compare keys.
         *
         */
        key_compare key_comp() const;

        /**
         * @brief  Returns a comparison object that can be used to compare two elements to get
         * whether the key of the first one goes before the second.
         *
         */
        value_compare value_comp() const;

        // OPERATIONS ==========================================================

        /**
         * @brief Searches the container for an element with a key equivalent to k and returns
         * an iterator to it if found, otherwise it returns an iterator to map::end.
         *
         */
        _tree_iterator find(const key_type &k);

        /**
         * @brief Searches the container for an element with a key equivalent to k and returns
         * an iterator to it if found, otherwise it returns an iterator to map::end.
         *
         */
        _tree_const_iterator find(const key_type &k) const;

        /**
         * @brief Searches the container for elements with a key equivalent to k and returns
         * the number of matches.
         *
         */
        size_type count(const key_type &k) const;

        /**
         * @brief Returns an iterator pointing to the first element in the container whose key
         * is not considered to go before k (i.e., either it is equivalent or goes after).
         *
         */
        _tree_iterator lower_bound(const key_type &k);

        /**
         * @brief Returns an iterator pointing to the first element in the container whose key
         * is not considered to go before k (i.e., either it is equivalent or goes after).
         *
         */
        _tree_const_iterator lower_bound(const key_type &k) const;

        /**
         * @brief Returns an iterator pointing to the first element in the container whose key
         * is considered to go after k.
         *
         */
        _tree_iterator upper_bound(const key_type &k);

        /**
         * @brief Returns an iterator pointing to the first element in the container whose key
         * is considered to go after k.
         *
         */
        _tree_const_iterator upper_bound(const key_type &k) const;

        /**
         * @brief Returns the bounds of a range that includes all the elements in the container
         * which have a key equivalent to k.
         *
         */
        ft::pair<_tree_const_iterator, _tree_const_iterator> equal_range(const key_type &k) const;

        /**
         * @brief Returns the bounds of a range that includes all the elements in the container
         * which have a key equivalent to k.
         *
         */
        ft::pair<_tree_iterator, _tree_iterator> equal_range(const key_type &k);

        // ALLOCATOR ===========================================================

        /**
         * @brief Returns a copy of the allocator object associated with the map.
         *
         */
        allocator_type get_allocator() const;
    };
}

#include "map.tpp"

#endif // ********************************************** MAP_HPP end //