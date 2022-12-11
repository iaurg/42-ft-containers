#ifndef PAIR_HPP
#define PAIR_HPP

/*
 * This class couples together a pair of values, which may be
 * of different types (T1 and T2). The individual values can
 * be accessed through its public members first and second.
 */

namespace ft
{
    template <typename T1, typename T2>
    struct pair
    {
    public:
        /**
         * @brief The first template parameter (T1).
         *
         */
        typedef T1 first_type;

        /**
         * @brief The second template parameter (T2).
         *
         */
        typedef T2 second_type;

        /**
         * @brief The first value in the pair
         *
         */
        T1 first;

        /**
         * @brief The second value in the pair
         *
         */
        T2 second;

        /**
         * @brief Constructs a pair object with its elements value-initialized.
         *
         */
        pair(void);

        /**
         * @brief Construct a new pair object.
         * The object is initialized with the contents of the pr pair object.
         * The corresponding member of pr is passed to the constructor of each of its members.
         *
         * @tparam U The first template parameter of pr
         * @tparam V The second template parameter of pr
         * @param pr The pair object to copy
         */
        template <class U, class V>
        pair(const pair<U, V> &pr);

        /**
         * @brief Construct a new pair object.
         *  Member first is constructed with a and member second with b.
         *
         * @param a The first value in the pair
         * @param b The second value in the pair
         */
        pair(const T1 &a, const T2 &b);

        /**
         * @brief Destroy the pair object
         *
         */
        ~pair(void);

        /**
         * @brief Assigns pr as the new content for the pair object.
         * Member first is assigned pr.first, and member second is assigned pr.second.
         *
         * @param pr
         * @return pair<T1, T2>&
         */
        pair<T1, T2> &operator=(pair<T1, T2> const &pr);
    };

    template <class T1, class T2>
    inline bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

    template <class T1, class T2>
    inline bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

    template <class T1, class T2>
    inline bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

    template <class T1, class T2>
    inline bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

    template <class T1, class T2>
    inline bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

    template <class T1, class T2>
    inline bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs);

    /**
     * @brief  Constructs a pair object with its first element set to x and its second element set to y.
     *
     * @tparam T1 The first template parameter of the pair
     * @tparam T2 The second template parameter of the pair
     * @param x The first value in the pair
     * @param y The second value in the pair
     * @return ft::pair<T1, T2>
     */
    template <class T1, class T2>
    inline ft::pair<T1, T2> make_pair(T1 x, T2 y);
}

#include "pair.tpp"

#endif // ********************************************** PAIR_HPP end //
