#ifndef VECTOR_TPP
#define VECTOR_TPP

#include <memory>
#include <stdexcept>
#include "vector.hpp"

namespace ft
{
    // CONSTRUCTORS =================================================================

    template <typename T, typename Alloc>
    vector<T, Alloc>::vector(const allocator_type &alloc)
    {
        this->_alloc = alloc;
        this->_size = 0;
        this->_capacity = 0;
        this->_data = NULL;
    };

    template <typename T, typename Alloc>
    vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc)
    {
        this->_alloc = alloc;
        this->_size = n;
        this->_capacity = n;
        this->_data = this->_alloc.allocate(n);
        for (size_type i = 0; i < n; i++)
            this->_alloc.construct(this->_data + i, val);
    };

    template <typename T, typename Alloc>
    vector<T, Alloc>::vector(const vector &x)
    {
        this->_alloc = x._alloc;
        this->_size = x._size;
        this->_capacity = x._capacity;
        this->_data = this->_alloc.allocate(x._size);
        for (size_type i = 0; i < x._size; i++)
            this->_alloc.construct(this->_data + i, x._data[i]);
    };

    // DESTRUCTOR ==================================================================

    template <typename T, typename Alloc>
    vector<T, Alloc>::~vector()
    {
        for (size_type i = 0; i < this->_size; i++)
            this->_alloc.destroy(this->_data + i);
        this->_alloc.deallocate(this->_data, this->_capacity);
    };

    // OPERATORS ========================================================

    template <typename T, typename Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        for (size_t i = 0; i < lhs.size(); i++)
            if (lhs[i] != rhs[i])
                return false;
        return true;
    };

    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        // TODO IMPLEMENT MY OWN LEXICOGRAPHICAL COMPARISON
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return rhs < lhs;
    }

    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs < rhs);
    }

    // MODIFIERS ====================================================================

    template <typename T, typename Alloc>
    void vector<T, Alloc>::push_back(const value_type &val)
    {
        if (this->_size == this->_capacity)
        {
            if (this->_capacity == 0)
                this->_capacity = 1;
            else
                this->_capacity *= 2;
            pointer tmp = this->_alloc.allocate(this->_capacity);
            for (size_type i = 0; i < this->_size; i++)
            {
                this->_alloc.construct(tmp + i, this->_data[i]);
                this->_alloc.destroy(this->_data + i);
            }
            this->_alloc.deallocate(this->_data, this->_size);
            this->_data = tmp;
        }
        this->_alloc.construct(this->_data + this->_size, val);
        this->_size++;
    };

    // CAPACITY ===============================================================

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
    {
        return (this->_size);
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
    {
        return (this->_alloc.max_size());
    };

    template <typename T, typename Alloc>
    void vector<T, Alloc>::resize(size_type n, value_type val)
    {
        if (n > this->_size)
        {
            if (n > this->_capacity)
            {
                this->_capacity = n;
                pointer tmp = this->_alloc.allocate(this->_capacity);
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->_alloc.construct(tmp + i, this->_data[i]);
                    this->_alloc.destroy(this->_data + i);
                }
                this->_alloc.deallocate(this->_data, this->_size);
                this->_data = tmp;
            }
            for (size_type i = this->_size; i < n; i++)
                this->_alloc.construct(this->_data + i, val);
        }
        else
        {
            for (size_type i = n; i < this->_size; i++)
                this->_alloc.destroy(this->_data + i);
        }
        this->_size = n;
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
    {
        return (this->_capacity);
    };

    template <typename T, typename Alloc>
    bool vector<T, Alloc>::empty(void) const
    {
        return (this->_size == 0);
    };

    template <typename T, typename Alloc>
    void vector<T, Alloc>::reserve(size_type n)
    {
        if (n > this->_capacity)
        {
            pointer tmp = this->_alloc.allocate(n);
            for (size_type i = 0; i < this->_size; i++)
            {
                this->_alloc.construct(tmp + i, this->_data[i]);
                this->_alloc.destroy(this->_data + i);
            }
            this->_alloc.deallocate(this->_data, this->_size);
            this->_data = tmp;
            this->_capacity = n;
        }
    };

    template <typename T, typename Alloc>
    void vector<T, Alloc>::shrink_to_fit()
    {
        if (this->_size < this->_capacity)
        {
            pointer tmp = this->_alloc.allocate(this->_size);
            for (size_type i = 0; i < this->_size; i++)
            {
                this->_alloc.construct(tmp + i, this->_data[i]);
                this->_alloc.destroy(this->_data + i);
            }
            this->_alloc.deallocate(this->_data, this->_capacity);
            this->_data = tmp;
            this->_capacity = this->_size;
        }
    };

    // ACCESSORS ====================================================================
    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](size_type n)
    {
        return (this->_data[n]);
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[](size_type n) const
    {
        return (this->_data[n]);
    };

    // ITERATORS ====================================================================

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
    {
        return (iterator(this->_data));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
    {
        return (const_iterator(this->_data));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
    {
        return (iterator(this->_data + this->_size));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
    {
        return (const_iterator(this->_data + this->_size));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
    {
        return (reverse_iterator(this->end()));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
    {
        return (const_reverse_iterator(this->end()));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
    {
        return (reverse_iterator(this->begin()));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
    {
        return (const_reverse_iterator(this->begin()));
    };
}

#endif // ********************************************** VECTOR_TPP end //