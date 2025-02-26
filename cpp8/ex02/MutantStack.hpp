/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:18:00 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/26 14:54:36 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <stack>

/*MutantStack class inherit from std::stack to support all stack operations*/
template <typename T>
class MutantStack : public std::stack<T>
{
  public:
	MutantStack();                         // Default constructor
	MutantStack(const MutantStack<T> &cp); // Copy constructor
	MutantStack<T> &operator=(const MutantStack<T> &cp);
	~MutantStack();

	/*Expose the iterators to the container_type (underlying container in std::stack)*/
	typedef typename std::stack<T>::container_type::iterator custom_iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_custom_iterator;

	/* Declaration of iterator functions */
	custom_iterator start();
	custom_iterator end();
};

/*Constructor return iterator to the underlying container (container_type)*/
template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &cp) // Copy constructor
	: std::stack<T>(cp)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &cp) // Assignment operator	
{
	if (this != &cp)
	{
		std::stack<T>::operator=(cp);
	}
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() // Destructor
{
}

/*Function to make MutantStack iterable using the defined iterator functions*/
template <typename T>
typename MutantStack<T>::custom_iterator MutantStack<T>::start()
{
	return (std::stack<T>::c.start());
}

template <typename T>
typename MutantStack<T>::custom_iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

#endif