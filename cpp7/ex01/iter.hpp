/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:07:05 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/23 09:19:38 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
/*Iter template function is designed to apply a function to each element of an array despite the type of element,
	iterate ove array and perform operation on each element*/
template <typename U> 
void iter(U *array, size_t len, void(*all)(U &))
{
    size_t i = 0;
    //apply function to every elements in the array
    while (i < len)
    {
        all(array[i]);
        i++;
    }
}

#endif
