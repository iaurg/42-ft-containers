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
        iterator begin();

        /**
         * @brief Returns an iterator referring to the past-the-end element in the map container.
         *
         */
        iterator end();

        /**
         * @brief Returns a const_iterator referring to the first element in the map container.
         *
         */
        const_iterator begin() const;

        /**
         * @brief Returns a const_iterator referring to the past-the-end element in the map container.
         *
         */
        const_iterator end() const;

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
        // TODO IMPLEMENT FT::PAIR
        std::pair<iterator, bool> insert(const value_type &val);

        /**
         * @brief Inserts an element into the map container, if the container doesn't already contain an element with an equivalent key.
         *
         */
        iterator insert(iterator position, const value_type &val);

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
        void erase(iterator position);

        /**
         * @brief Erases an element from the map container.
         *
         */
        size_type erase(const key_type &k);

        /**
         * @brief Erases elements from the map container.
         *
         */
        void erase(iterator first, iterator last);

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
        iterator find(const key_type &k);

        /**
         * @brief Searches the container for an element with a key equivalent to k and returns
         * an iterator to it if found, otherwise it returns an iterator to map::end.
         *
         */
        const_iterator find(const key_type &k) const;

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
        iterator lower_bound(const key_type &k);

        /**
         * @brief Returns an iterator pointing to the first element in the container whose key
         * is not considered to go before k (i.e., either it is equivalent or goes after).
         *
         */
        const_iterator lower_bound(const key_type &k) const;

        /**
         * @brief Returns an iterator pointing to the first element in the container whose key
         * is considered to go after k.
         *
         */
        iterator upper_bound(const key_type &k);

        /**
         * @brief Returns an iterator pointing to the first element in the container whose key
         * is considered to go after k.
         *
         */
        const_iterator upper_bound(const key_type &k) const;

        /**
         * @brief Returns the bounds of a range that includes all the elements in the container
         * which have a key equivalent to k.
         *
         */
        // TODO IMPLEMENT FT::PAIR
        std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const;

        /**
         * @brief Returns the bounds of a range that includes all the elements in the container
         * which have a key equivalent to k.
         *
         */
        // TODO IMPLEMENT FT::PAIR
        std::pair<iterator, iterator> equal_range(const key_type &k);

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