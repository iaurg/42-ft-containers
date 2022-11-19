#ifndef UTILS_HPP
# define UTILS_HPP

# include <uchar.h>

namespace ft {
    // enable_if ====================================================================
    /*
    * This metafunction is a convenient way to leverage SFINAE prior to C++20's concepts, in particular for conditionally 
    * removing functions from the candidate set based on type traits, allowing separate function overloads or specializations 
    * based on those different type traits.
    */
    
    /**
     * @brief enable_if is a metafunction that returns its second argument if its first argument is true, and does nothing otherwise.
     * 
     * @tparam B 
     * @tparam T 
     */
    template<bool B, class T = void>
    struct enable_if {};

    /**
     * @brief This is the primary template of the enable_if metafunction. It is defined such that enable_if is a type only if B is true.
     * 
     * @tparam T 
     */
    template<class T>
    struct enable_if<true, T> {
        typedef T type;
    };

    // is_integral ==================================================================
    /*
    * Checks whether T is an integral type. Provides the member constant value which is equal to true, if T is the type bool, 
    * char, char8_t (since C++20), char16_t, char32_t, wchar_t, short, int, long, long long, or any implementation-defined 
    * extended integer types, including any signed, unsigned, and cv-qualified variants. Otherwise, value is equal to false. 
    */

    /**
    * @brief is_integral is a type trait that is derived from true_type if T is an integral type, and false_type otherwise.
    * 
    * @tparam T 
    */
    template<typename T>
    struct is_integral { static const bool value = false; };

    /**
     * @brief This is the primary template of the is_integral metafunction. It is defined such that is_integral is a type only if T is an integral type.
     * 
     * @tparam
     */
    template<>
    struct is_integral<bool> { static const bool value = true; };

    template<>
    struct is_integral<char> { static const bool value = true; };

    template<>
    struct is_integral<signed char> { static const bool value = true; };

    template<>
    struct is_integral<unsigned char> { static const bool value = true; };

    template<>
    struct is_integral<wchar_t> { static const bool value = true; };

    template<>
    struct is_integral<char16_t> { static const bool value = true; };

    template<>
    struct is_integral<char32_t> { static const bool value = true; };

    template<>
    struct is_integral<short> { static const bool value = true; };

    template<>
    struct is_integral<unsigned short> { static const bool value = true; };

    template<>
    struct is_integral<int> { static const bool value = true; };

    template<>
    struct is_integral<unsigned int> { static const bool value = true; };

    template<>
    struct is_integral<long> { static const bool value = true; };

    template<>
    struct is_integral<unsigned long> { static const bool value = true; };

    template<>
    struct is_integral<long long> { static const bool value = true; };

    template<>
    struct is_integral<unsigned long long> { static const bool value = true; };

} // namespace ft

#endif // ********************************************** VECTOR_HPP end //