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
    };
}

#include "map.tpp"

#endif // ********************************************** MAP_HPP end //