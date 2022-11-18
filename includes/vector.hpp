#ifndef VECTOR_HPP
# define VECTOR_HPP

// LIBS ========================================================================
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

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

        protected:
        // ATTRIBUTES =================================================================
            pointer _data;
            size_type _size;
            size_type _capacity;
            allocator_type _alloc;


        // CONSTRUCTORS ==========================================================

        /**
         * @brief Default Construct a new vector object
         * 
         * @param alloc 
         */
        explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
            _size = 0;
            _capacity = 0;
            _data = NULL;
        }

        /**
         * @brief Fill Construct a new vector object
         * 
         * @param n 
         * @param val 
         * @param alloc 
         */
        explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
            _size = n;
            _capacity = n;
            _data = _alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(_data + i, val);
        }

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
        vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) : _alloc(alloc) {
            _size = 0;
            _capacity = 0;
            _data = NULL;
            assign(first, last);
        }

        /**
         * @brief Copy Construct a new vector object
         * 
         * @param x 
         */
        vector(const vector& x) {
            _size = 0;
            _capacity = 0;
            _data = NULL;
            *this = x;
        }

        // DESTRUCTOR =============================================================

        /**
         * @brief Destroy the vector object
         * 
         */
        ~vector() {
            clear();
            _alloc.deallocate(_data, _capacity);
        }
    };
} // namespace ft

#endif // ********************************************** VECTOR_HPP end //