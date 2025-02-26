/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:53:47 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/26 09:35:13 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default constructor
Span::Span()
	: _maxLen(0)
{
}

// Parameterized constructor
Span::Span(unsigned int N)
	: _maxLen(N)
{
}

// Copy constructor
Span::Span(const Span &cp)
	: _maxLen(cp._maxLen), _value(cp._value)
{
}

// Assignment operator
Span &Span::operator=(const Span &cp)
{
	if (this != &cp)
	{
		_maxLen = cp._maxLen;
		_value = cp._value;
	}
	return (*this);
}

// Destructor
Span::~Span()
{
}

// Add number to Span
void Span::addNumber(int n)
{
	if (_value.size() >= _maxLen)
	{
		throw CustomException1();
	}
	_value.push_back(n);
}

// Find the shortest span
int Span::shortestSpan()
{
	int	minSpan;
	int	n;

	if (_value.size() < 2)
	{
		throw CustomException2();
	}
	std::vector<int> sorted = _value;
	std::sort(sorted.begin(), sorted.end());
	minSpan = std::numeric_limits<int>::max();
	std::vector<int>::iterator iterate = sorted.begin();
	std::vector<int>::iterator nextIterate = iterate;
	++nextIterate;
	while (nextIterate != sorted.end())
	{
		n = *nextIterate - *iterate;
		if (n < minSpan)
		{
			minSpan = n;
		}
		++iterate;
		++nextIterate;
	}
	return (minSpan);
}

// Find the longest span
int Span::longestSpan()
{
	if (_value.size() < 2)
	{
		throw CustomException2();
	}

	int minValue = *std::min_element(_value.begin(), _value.end());
	int maxValue = *std::max_element(_value.begin(), _value.end());

	return (maxValue - minValue);
}