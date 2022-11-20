#ifndef VECTOR_HPP
# define VECTOR_HPP

// LIBS ========================================================================
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "./utils.hpp"

namespace ft {
    // CLASS =======================================================================
    template<typename T, typename Alloc = std::allocator<T> >
    class vector {
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
        
        /*
        typedef typename const_reverse_iterator<value_type>::type const_reverse_iterator;
        typedef typename reverse_iterator<value_type>::type reverse_iterator;
        typedef typename const_iterator<value_type>::type const_iterator;
        typedef typename iterator<value_type>::type iterator;
        */               

        protected:
        // ATTRIBUTES =================================================================
            pointer _data;
            size_type _size;
            size_type _capacity;
            allocator_type _alloc;


        // CONSTRUCTORS ==========================================================
        public:
        /**
         * @brief Default Construct a new vector object
         * 
         * @param alloc 
         */
        explicit vector(const allocator_type& alloc = allocator_type());

        /**
         * @brief Fill Construct a new vector object
         * 
         * @param n 
         * @param val
         * @param alloc
         */
        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

        /**
         * @brief Range Construct a new vector object
         * 
         * @param first 
         * @param last 
         * @param alloc 
         * 
         * @tparam InputIterator if InputIterator is an integral type, the container
         * is initialized with first copies of last converted to value_type.
         */
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

        /**
         * @brief Copy Construct a new vector object
         * 
         * @param x 
         */
        vector(const vector& x);

        // DESTRUCTOR =============================================================

        /**
         * @brief Destroy the vector object
         * 
         */
        ~vector();

        // OPERATORS =============================================================
        
        /**
         * @brief Copy assignment operator
         * 
         * @param x 
         * @return vector& 
         */
        vector& operator=(const vector& x);

        // ACCESSORS =============================================================

        /**
         * @brief Returns a reference to the element at position n in the vector container.
         * 
         * @param n 
         * @return reference 
         */
        reference operator[](size_type n);

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
        void assign(size_type n, const value_type& val);        

        /**
         * @brief Adds a new element at the end of the vector, after its current last element.
         * The content of val is copied (or moved) to the new element.
         * 
         * @param val 
         */
        void push_back(const value_type& val);

        /**
         * @brief Removes the last element in the vector, effectively reducing the container size by one.
         * 
         */
        void pop_back();

       /**
        * @brief The vector is extended by inserting new elements before the element at the specified position,
        * 
        * @param n 
        */
        void reserve(size_type n);

        /**
         * @brief Return the number of elements that the vector has
         * 
         * @param n 
         */
        void size(size_type n);


    };
} // namespace ft

#include "vector.tpp"

#endif // ********************************************** VECTOR_HPP end //