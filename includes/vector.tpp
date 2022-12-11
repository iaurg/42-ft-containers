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
        _alloc = alloc;
        _size = 0;
        _capacity = 0;
        _data = NULL;
    };

    template <typename T, typename Alloc>
    vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc)
    {
        _alloc = alloc;
        _size = n;
        _capacity = n;
        _data = _alloc.allocate(n);
        for (size_type i = 0; i < n; i++)
            _alloc.construct(_data + i, val);
    };

    template <typename T, typename Alloc>
    vector<T, Alloc>::vector(const vector &x)
    {
        _alloc = x._alloc;
        _size = x._size;
        _capacity = x._capacity;
        _data = _alloc.allocate(x._size);
        for (size_type i = 0; i < x._size; i++)
            _alloc.construct(_data + i, x._data[i]);
    };

    // DESTRUCTOR ==================================================================

    template <typename T, typename Alloc>
    vector<T, Alloc>::~vector()
    {
        clear();
        _alloc.deallocate(_data, _capacity);
    };

    // NON MEMBER OVERLOADS =======================================================
    template <typename T, class Alloc>
    vector<T, Alloc> &vector<T, Alloc>::operator=(const vector &x)
    {
        if (this != &x)
        {
            clear();
            _alloc.deallocate(_data, _capacity);
            _alloc = x._alloc;
            _size = x._size;
            _capacity = x._capacity;
            _data = _alloc.allocate(x._size);
            for (size_type i = 0; i < x._size; i++)
                _alloc.construct(_data + i, x._data[i]);
        }
        return (*this);
    };

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
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
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

    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
        x.swap(y);
    }

    // MODIFIERS ====================================================================

    template <typename T, typename Alloc>
    void vector<T, Alloc>::push_back(const value_type &val)
    {
        if (_size == _capacity)
            reserve(_capacity == 0 ? 1 : _capacity * 2);
        _alloc.construct(_data + _size, val);
        _size++;
    };

    template <typename T, typename Alloc>
    void vector<T, Alloc>::pop_back()
    {
        if (_size == 0)
            throw std::out_of_range("vector");
        _alloc.destroy(_data + _size - 1);
        _size--;
    };

    template <typename T, typename Alloc>
    void vector<T, Alloc>::clear()
    {
        for (size_type i = 0; i < _size; i++)
            _alloc.destroy(_data + i);
        _size = 0;
    };

    template <typename T, typename Alloc>
    void vector<T, Alloc>::assign(size_type n, const value_type &val)
    {
        clear();
        reserve(n);
        for (size_type i = 0; i < n; i++)
            push_back(val);
    };

    template <typename T, typename Alloc>
    template <typename InputIterator>
    void vector<T, Alloc>::assign(InputIterator first, InputIterator last)
    {
        clear();
        reserve(last - first);
        for (InputIterator it = first; it != last; it++)
            push_back(*it);
    };

    template <typename T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator position, const value_type &val)
    {
        size_type pos = position - begin();

        if (_size == _capacity)
            reserve(_capacity + 1);
        for (size_type i = _size; i > pos; i--)
            _alloc.construct(_data + i, _data[i - 1]);
        _alloc.construct(_data + pos, val);
        _size++;
        return begin() + pos;
    };

    template <typename T, typename Alloc>
    void vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val)
    {
        size_type pos = position - begin();
        reserve(_size + n);
        for (size_type i = _size; i > pos; i--)
            _data[i + n - 1] = _data[i - 1];
        for (size_type i = 0; i < n; i++)
            _data[pos + i] = val;
        _size += n;
    };

    template <typename T, typename Alloc>
    template <typename InputIterator>
    void vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
    {
        size_type pos = position - begin();
        size_type n = last - first;
        reserve(_size + n);
        for (size_type i = _size; i > pos; i--)
            _data[i + n - 1] = _data[i - 1];
        for (size_type i = 0; i < n; i++)
            _data[pos + i] = *first++;
        _size += n;
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
    {
        size_type pos = position - begin();
        for (size_type i = pos; i < _size - 1; i++)
            _data[i] = _data[i + 1];
        _alloc.destroy(_data + _size - 1);
        _size--;
        return begin() + pos;
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last)
    {
        size_type pos = first - begin();
        size_type n = last - first;
        for (size_type i = pos; i < _size - n; i++)
            _data[i] = _data[i + n];
        for (size_type i = 0; i < n; i++)
            _alloc.destroy(_data + _size - i - 1);
        _size -= n;
        return begin() + pos;
    };

    template <typename T, typename Alloc>
    void vector<T, Alloc>::swap(vector &x)
    {
        pointer tmp_data = _data;
        size_type tmp_size = _size;
        size_type tmp_capacity = _capacity;
        allocator_type tmp_alloc = _alloc;

        _data = x._data;
        _size = x._size;
        _capacity = x._capacity;
        _alloc = x._alloc;

        x._data = tmp_data;
        x._size = tmp_size;
        x._capacity = tmp_capacity;
        x._alloc = tmp_alloc;
    };

    // ALLOCATOR ====================================================================

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const
    {
        return _alloc;
    };

    // CAPACITY ===============================================================

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
    {
        return (_size);
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
    {
        return (_alloc.max_size());
    };

    template <typename T, typename Alloc>
    void vector<T, Alloc>::resize(size_type n, value_type val)
    {
        if (n > _size)
        {
            if (n > _capacity)
            {
                _capacity = n;
                pointer tmp = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                {
                    _alloc.construct(tmp + i, _data[i]);
                    _alloc.destroy(_data + i);
                }
                _alloc.deallocate(_data, _size);
                _data = tmp;
            }
            for (size_type i = _size; i < n; i++)
                _alloc.construct(_data + i, val);
        }
        else
        {
            for (size_type i = n; i < _size; i++)
                _alloc.destroy(_data + i);
        }
        _size = n;
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
    {
        return (_capacity);
    };

    template <typename T, typename Alloc>
    bool vector<T, Alloc>::empty(void) const
    {
        return (_size == 0);
    };

    template <typename T, typename Alloc>
    void vector<T, Alloc>::reserve(size_type n)
    {
        if (n > _capacity)
        {
            pointer tmp = _alloc.allocate(n);
            if (tmp == NULL)
                throw std::bad_alloc();
            for (size_type i = 0; i < _size; i++)
                _alloc.construct(tmp + i, _data[i]);
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(_data + i);
            _alloc.deallocate(_data, _capacity);
            _data = tmp;
            _capacity = n;
        }
    };

    // ACCESSORS ====================================================================
    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::operator[](size_type n)
    {
        return (_data[n]);
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[](size_type n) const
    {
        return (_data[n]);
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n)
    {
        if (n >= _size)
            throw std::out_of_range("vector::at");
        return (_data[n]);
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::at(size_type n) const
    {
        if (n >= _size)
            throw std::out_of_range("vector::at");
        return (_data[n]);
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::front()
    {
        return (_data[0]);
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
    {
        return (_data[0]);
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::back()
    {
        return (_data[_size - 1]);
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
    {
        return (_data[_size - 1]);
    };

    // ITERATORS ====================================================================

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
    {
        return (iterator(_data));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
    {
        return (const_iterator(_data));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
    {
        return (iterator(_data + _size));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
    {
        return (const_iterator(_data + _size));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
    {
        return (reverse_iterator(end()));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rbegin() const
    {
        return (const_reverse_iterator(end()));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
    {
        return (reverse_iterator(begin()));
    };

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const
    {
        return (const_reverse_iterator(begin()));
    };
}

#endif // ********************************************** VECTOR_TPP end //