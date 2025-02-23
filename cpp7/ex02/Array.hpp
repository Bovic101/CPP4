/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:52:58 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/23 10:13:03 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array
{
  private:
	T *_member;
	size_t _size;

  public:
	/*Default constructor to creates an empty array*/
	Array()
		: _member(NULL), _size(0)
	{
	}

	/*Constructor with size parameter*/
	Array(size_t n)
		: _size(n)
	{
		_member = new T[_size];
		size_t i = 0;
		while (i < _size)
		{
			_member[i] = T(); // member init by default
			i++;
		}
	}

	/*Copy constructor*/
	Array(const Array &cp)
		: _size(cp._size)
	{
		_member = new T[_size];
		size_t i = 0;
		while (i < _size)
		{
			_member[i] = cp._member[i];
			i++;
		}
	}

	/*Destructor*/
	~Array()
	{
		delete[] _member;
	}

	/*Assignment operator*/ 
	Array &operator=(const Array &cp)
	{
		if (this != &cp)
		{
			delete[] _member;

			_size = cp._size;
			_member = new T[_size];
			size_t i = 0;
			while (i < _size)
			{
				_member[i] = cp._member[i];
				i++;
			}
		}
		return (*this);
	}

	/* accesing the element tru Subscript operator []*/
	T &operator[](size_t i)
	{
		if (i >= _size)
		{
			throw std::out_of_range("Index is out of bounds");
		}
		return (_member[i]);
	}

	/*Exception Hnadling*/
	const T &operator[](size_t i) const
	{
		if (i >= _size)
		{
			throw std::out_of_range("Index is out of bounds");
		}
		return (_member[i]);
	}

	// Function to get size
	size_t size() const
	{
		return (_size);
	}
};

#endif
