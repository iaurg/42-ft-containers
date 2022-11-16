#ifndef VECTOR_HPP
# define VECTOR_HPP

// LIBS ========================================================================
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

namespace ft {
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
    
} // namespace ft

#endif // ********************************************** VECTOR_HPP end //