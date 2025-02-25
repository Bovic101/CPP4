/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:54:27 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/25 15:16:13 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception> //use to handle custom execption

class CustomException: public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return("The element can not be foun in the container");
    }
};
template <typename T>
typename T::iterator easyfind(T& container, int arg) 
{
    typename T::iterator iterate = container.begin();
    
    while (iterate != container.end()) 
	{
        if (*iterate == arg)
            return iterate;
        ++iterate;
    }
    throw CustomException();
}

#endif