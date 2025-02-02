#include <iostream>
#include <stdexcept>
using namespace std;
#include "IntVector.h"

IntVector::IntVector(unsigned capacity, int value)
{
    _capacity = capacity;
    _size = capacity;
    _data = new int[capacity];
    for (unsigned int i = 0; i < capacity; ++i)
	{
		_data[i] = value;
	}
}

IntVector::~IntVector()
{
    delete[] _data;
}

unsigned IntVector::size() const
{
    return _size;
}

unsigned IntVector::capacity() const
{
    return _capacity;
}

bool IntVector::empty() const
{
    return (_size == 0);
}

const int & IntVector::at(unsigned index) const
{
    if (index < _size)
    {
        return _data[index];
    }
    throw out_of_range("IntVector::at_range_check");
}

const int & IntVector::front() const
{
    return _data[0];
}

const int & IntVector::back() const
{
    return _data[_size -1];
}

int & IntVector::at(unsigned index)
{
    if (index < _size)
    {
        return _data[index];
    }
    throw out_of_range("IntVector::at_range_check");
}

void IntVector::insert(unsigned index, int value)
{
    if (index > _size)
    {
        throw out_of_range("IntVector::insert_range_check");
    }
    ++ _size;
    if (_size > _capacity)
    {
        expand();
    }
    for (unsigned int i = index + 1; i < _size; ++i)
    {
        _data[i] = _data[i-1];
    }
    _data[index] = value;
}

void IntVector::erase(unsigned index)
{
    if (index >= _size)
    {
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned int i = index; i < _size-1; ++i)
    {
        _data[i] = _data[i+1];
    }
    --_size;
}

int & IntVector::front()
{
    return _data[0];
}

int & IntVector::back()
{
    return _data[_size -1];
}

void IntVector::assign(unsigned n, int value)
{
    if (n > _capacity)
    {
        if (_capacity >= (n - _capacity)) 
        {
            expand();
        }
        else
        {
            expand(n - _capacity);
        }
    }
    _size = n;
    for (unsigned int i = 0;i < _size; ++i)
    {
        _data[i] = value;
    }
}

void IntVector::push_back(int value)
{
    ++ _size;
	if (_size > _capacity)
	{
		expand();
	}
	_data[_size - 1] = value;
}

void IntVector::pop_back()
{
    --_size;
}

void IntVector::clear()
{
    _size = 0;
}

void IntVector::resize(unsigned n, int value)
{
	if (n < _size)
    {
        _size = n;
    }
    else
    {
        if (n > _capacity)
        {
            if (_capacity >= (n - _capacity)) 
            {
                expand();
            }
            else
            {
                expand(n - _capacity);
            }
	    }
        for (unsigned int i = _size;i < n;++i)
        {
            _data[i] = value;
        }
        _size = n;
    }
}

void IntVector::reserve(unsigned n)
{
    if (n > _capacity)
	{
		expand(n - _capacity);
	}
}

void IntVector::expand()
{
    if (_capacity == 0)
    {
        _capacity = 1;
    }
    else
    {
        _capacity *= 2;
    }
    int* hold = new int[_capacity];
    for (unsigned int i = 0; i < _size;++i)
    {
        hold[i] = _data[i];
    }
    delete _data;
    _data = hold;
}

void IntVector::expand(unsigned amount)
{
    _capacity += amount;
    int* hold = new int[_capacity];
    for (unsigned int i = 0; i < _size;++i)
    {
        hold[i] = _data[i];
    }
    delete _data;
    _data = hold;
}