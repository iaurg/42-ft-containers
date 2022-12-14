#ifndef VECTOR_HPP
#define VECTOR_HPP

// LIBS ========================================================================
#include <memory>
#include <cstddef>
#include "./utils.hpp"
#include "./iterator.hpp"
#include "./algorithm.hpp"

namespace ft
{
    // CLASS =======================================================================
    template <typename T, typename Alloc = std::allocator<T> >
    class vector
    {
    public:
        // TYPEDEFS ==================================================================

        /**
         * @brief The first template parameter (T)
         */
        typedef T value_type;

        /**
         * @brief The second template parameter (Alloc) is the allocator type.
         * The default allocator is std::allocator<T>, which provides the same
         * guarantees as the default allocator of the standard library.
         */
        typedef Alloc allocator_type;

        /**
         * @brief The allocator_type::reference is an alias of T&.
         *
         */
        typedef typename allocator_type::reference reference;

        /**
         * @brief The allocator_type::const_reference is an alias of const T&.
         *
         */
        typedef typename allocator_type::const_reference const_reference;

        /**
         * @brief The allocator_type::pointer is an alias of T*.
         *
         */
        typedef typename allocator_type::pointer pointer;

        /**
         * @brief The allocator_type::const_pointer is an alias of const T*.
         *
         */
        typedef typename allocator_type::const_pointer const_pointer;

        /**
         * @brief The allocator_type::difference_type is an alias of ptrdiff_t.
         * a signed integral type that can be used to identify distance between two pointers.
         */
        typedef typename allocator_type::difference_type difference_type;

        /**
         * @brief The allocator_type::size_type is an alias of size_t.
         * an unsigned integral type that can represent any non-negative value of difference_type.
         */
        typedef typename allocator_type::size_type size_type;

        // ITERATORS =================================================================

        typedef ft::random_access_iterator<pointer> iterator;
        typedef ft::random_access_iterator<const_pointer> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    protected:
        // ATTRIBUTES =================================================================
        pointer _data;
        size_type _size;
        size_type _capacity;
        allocator_type _alloc;

        // CONSTRUCTORS ==========================================================
    public:
        /**
         * @brief Constructs an empty container, with no elements.
         *
         * @param alloc
         */
        explicit vector(const allocator_type &alloc = allocator_type());

        /**
         * @brief Constructs a container with n elements. Each element is a copy of val.
         *
         * @param n
         * @param val
         * @param alloc
         */
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type());

        /**
         * @brief Constructs a container with as many elements as the range [first,last),
         * with each element constructed from its corresponding element in that range,
         * in the same order.
         *
         * @param first
         * @param last
         * @param alloc
         *
         * @tparam InputIterator if InputIterator is an integral type, the container
         * is initialized with first copies of last converted to value_type.
         */
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());

        /**
         * @brief Constructs a container with a copy of each of the elements in x, in the same order.
         *
         * @param x
         */
        vector(const vector &x);

        // DESTRUCTOR =============================================================

        /**
         * @brief Destroys the container object.
         *
         */
        ~vector();

        // OPERATORS =============================================================

        /**
         * @brief  Assigns new contents to the container, replacing its current contents,
         * and modifying its size accordingly.
         *
         */
        vector &operator=(const vector &x);

        // ITERATORS =============================================================

        /**
         * @brief Returns an iterator pointing to the first element in the vector.
         *
         * @return iterator
         */
        iterator begin();

        /**
         * @brief Returns a const_iterator pointing to the first element in the vector.
         *
         * @return const_iterator
         */
        const_iterator begin() const;

        /**
         * @brief Returns an iterator referring to the past-the-end element in the vector container.
         *
         * @return iterator
         */
        iterator end();

        /**
         * @brief Returns a const_iterator referring to the past-the-end element in the vector container.
         *
         * @return const_iterator
         */
        const_iterator end() const;

        /**
         * @brief Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).
         *
         * @return reverse_iterator
         */
        reverse_iterator rbegin();

        /**
         * @brief Returns a const_reverse_iterator pointing to the last element in the vector (i.e., its reverse beginning).
         *
         * @return const_reverse_iterator
         */
        const_reverse_iterator rbegin() const;

        /**
         * @brief Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
         * (which is considered its reverse end).
         *
         * @return reverse_iterator
         */
        reverse_iterator rend();

        /**
         * @brief Returns a const_reverse_iterator pointing to the theoretical element preceding the first element in the
         * vector (which is considered its reverse end).
         *
         * @return const_reverse_iterator
         */
        const_reverse_iterator rend() const;

        // CAPACITY ===============================================================

        /**
         * @brief Returns the number of elements in the vector.
         *
         */
        size_type size() const;

        /**
         * @brief Returns the maximum number of elements that the vector can hold.
         *
         */
        size_type max_size() const;

        /**
         * @brief Resizes the container so that it contains n elements.
         *
         */
        void resize(size_type n, value_type val = value_type());

        /**
         * @brief Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
         *
         */
        size_type capacity() const;

        /**
         * @brief Returns whether the vector is empty (i.e. whether its size is 0).
         */
        bool empty(void) const;

        /**
         * @brief  Requests that the vector capacity be at least enough to contain n elements.
         *
         * @param n
         */
        void reserve(size_type n);

        // ELEMENT ACCESS =============================================================

        /**
         * @brief Returns a reference to the element at position n in the vector container.
         *
         * @param n
         * @return reference
         */
        reference operator[](size_type n);

        /**
         * @brief Returns a reference to the element at position n in the vector container.
         *
         * @param n
         * @return const_reference
         */
        const_reference operator[](size_type n) const;

        /**
         * @brief Returns a reference to the element at position n in the vector.
         *
         * @param n
         * @return reference
         */
        reference at(size_type n);

        /**
         * @brief Returns a reference to the element at position n in the vector.
         *
         * @param n
         * @return const_reference
         */
        const_reference at(size_type n) const;

        /**
         * @brief Returns a reference to the first element in the vector.
         *
         * @return reference
         */
        reference front();

        /**
         * @brief Returns a reference to the first element in the vector.
         *
         * @return const_reference
         */
        const_reference front() const;

        /**
         * @brief Returns a reference to the last element in the vector.
         *
         * @return reference
         */
        reference back();

        /**
         * @brief Returns a reference to the last element in the vector.
         *
         * @return const_reference
         */
        const_reference back() const;

        // MODIFIERS =============================================================

        /**
         * @brief Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
         *
         * @tparam InputIterator
         * @param first
         * @param last
         */
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last);

        /**
         * @brief Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
         *
         * @param n
         * @param val
         */
        void assign(size_type n, const value_type &val);

        /**
         * @brief Adds a new element at the end of the vector, after its current last element.
         * The content of val is copied (or moved) to the new element.
         *
         * @param val
         */
        void push_back(const value_type &val);

        /**
         * @brief Removes the last element in the vector, effectively reducing the container size by one.
         *
         */
        void pop_back();

        /**
         * @brief The vector is extended by inserting new elements before the element at the specified position,
         * effectively increasing the container size by the number of elements inserted.
         *
         * @param position
         * @param val
         * @return iterator
         */
        iterator insert(iterator position, const value_type &val);

        /**
         * @brief The vector is extended by inserting new elements before the element at the specified position,
         * effectively increasing the container size by the number of elements inserted.
         *
         * @param position
         * @param n
         * @param val
         * @return iterator
         */
        void insert(iterator position, size_type n, const value_type &val);

        /**
         * @brief The vector is extended by inserting new elements before the element at the specified position,
         * effectively increasing the container size by the number of elements inserted.
         *
         * @tparam InputIterator
         * @param position
         * @param first
         * @param last
         * @return iterator
         */
        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last);

        /**
         * @brief Removes from the vector either a single element (position) or a range of elements ([first,last)).
         *
         * @param position
         * @return iterator
         */
        iterator erase(iterator position);

        /**
         * @brief Removes from the vector either a single element (position) or a range of elements ([first,last)).
         *
         * @param first
         * @param last
         * @return iterator
         */
        iterator erase(iterator first, iterator last);

        /**
         * @brief Exchanges the content of the container by the content of x, which is another vector object of the same type.
         * Sizes may differ.
         *
         * @param x
         */
        void swap(vector &x);

        /**
         * @brief Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
         *
         */
        void clear();

        // ALLOCATOR =============================================================
        /**
         * @brief Returns a copy of the allocator object associated with the vector.
         *
         * @return allocator_type
         */
        allocator_type get_allocator() const;
    };

    // NON MEMBER OVERLOADS ======================================================

    /**
     * @brief Check if lhs is equal to rhs
     *
     */
    template <typename T, typename Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

    /**
     * @brief Check if lhs is different from rhs
     *
     */
    template <typename T, typename Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

    /**
     * @brief Check if lhs is less than rhs
     *
     */
    template <typename T, typename Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

    /**
     * @brief Check if lhs is less than or equal to rhs
     *
     */
    template <typename T, typename Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

    /**
     * @brief Check if lhs is greater than rhs
     *
     */
    template <typename T, typename Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

    /**
     * @brief Check if lhs is greater than or equal to rhs
     *
     */
    template <typename T, typename Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs);

    /**
     * @brief  The contents of container x are exchanged with those of y.
     * Both container objects must be of the same type (same template parameters),
     * although sizes may differ.
     *
     */
    template <typename T, typename Alloc>
    void swap(vector<T, Alloc> &X, vector<T, Alloc> &Y);

} // namespace ft

#include "vector.tpp"

#endif // ********************************************** VECTOR_HPP end //