#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft
{
    /**
     * @brief  Compares the elements in the range [first1,last1) with those in the
     * range beginning at first2, and returns true if all of the elements in both
     * ranges match.
     *
     * @param  first1  An input iterator.
     * @param  last1   An input iterator.
     * @param  first2  An input iterator.
     */
    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    /**
     * @brief  Compares the elements in the range [first1,last1) with those in the
     * range beginning at first2, and returns true if all of the elements in both
     * ranges match.
     *
     * @param  first1  An input iterator.
     * @param  last1   An input iterator.
     * @param  first2  An input iterator.
     * @param  pred    A binary predicate.
     */
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if (!pred(*first1, *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    /**
     * @brief  Returns true if the range [first1,last1) compares lexicographically less than the range [first2,last2).
     *
     * @param  first1  An input iterator.
     * @param  last1   An input iterator.
     * @param  first2  An input iterator.
     * @param  last2   An input iterator.
     */
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    /**
     * @brief  Returns true if the range [first1,last1) compares lexicographically less than the range [first2,last2).
     *
     * @param  first1  An input iterator.
     * @param  last1   An input iterator.
     * @param  first2  An input iterator.
     * @param  last2   An input iterator.
     * @param  comp    A binary predicate.
     */
    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || comp(*first2, *first1))
                return false;
            else if (comp(*first1, *first2))
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }
}

#endif // ********************************************** ALGORITHM_HPP end //