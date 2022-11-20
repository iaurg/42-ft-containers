#ifndef VECTOR_TPP
#define VECTOR_TPP

# include <memory>
# include <stdexcept>
#include "vector.hpp"

namespace ft {

// CONSTRUCTORS =================================================================

template<typename T, typename Alloc>
vector<T, Alloc>::vector(const allocator_type &alloc)
{
    this->_alloc = alloc;
    this->_size = 0;
    this->_capacity = 0;
    this->_data = NULL;
};

template<typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc)
{
    this->_alloc = alloc;
    this->_size = n;
    this->_capacity = n;
    this->_data = this->_alloc.allocate(n);
    for (size_type i = 0; i < n; i++)
        this->_alloc.construct(this->_data + i, val);
};

template<typename T, typename Alloc>
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

template<typename T, typename Alloc>
vector<T, Alloc>::~vector()
{
    for (size_type i = 0; i < this->_size; i++)
        this->_alloc.destroy(this->_data + i);
    this->_alloc.deallocate(this->_data, this->_capacity);
};

// ASSIGNATION OPERATOR ========================================================

template<typename T, typename Alloc>
vector<T, Alloc> &vector<T, Alloc>::operator=(const vector &x)
{
    if (this == &x)
        return (*this);
    for (size_type i = 0; i < this->_size; i++)
        this->_alloc.destroy(this->_data + i);
    this->_alloc.deallocate(this->_data, this->_capacity);
    this->_alloc = x._alloc;
    this->_size = x._size;
    this->_capacity = x._capacity;
    this->_data = this->_alloc.allocate(x._size);
    for (size_type i = 0; i < x._size; i++)
        this->_alloc.construct(this->_data + i, x._data[i]);
    return (*this);
};

// MODIFIERS ====================================================================

template<typename T, typename Alloc>
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

template<typename T, typename Alloc>
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

template<typename T, typename Alloc>
void vector<T, Alloc>::size(size_type n)
{
    if (n > this->_capacity)
        this->reserve(n);
    if (n > this->_size)
    {
        for (size_type i = this->_size; i < n; i++)
            this->_alloc.construct(this->_data + i, value_type());
    }
    else
    {
        for (size_type i = n; i < this->_size; i++)
            this->_alloc.destroy(this->_data + i);
    }
    this->_size = n;
};

// ACCESSORS ====================================================================
template<typename T, typename Alloc>
typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](size_type n)
{
    return (this->_data[n]);
};

}

#endif // ********************************************** VECTOR_TPP end //