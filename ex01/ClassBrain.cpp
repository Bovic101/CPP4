/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBrain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:15:33 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/30 11:16:17 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassBrain.hpp"
#include <iostream>

Brain::Brain() 
{
    std::cout << "Called Brain constructor.\n";
}

Brain::Brain(const Brain& cp) 
{
    std::cout << "A copy of Brain constructor called\n";
    for (int i = 0; i < 100; ++i) 
    {
        ideas[i] = cp.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& cp) 
{
    std::cout << "Called Brain assignment operator\n";
    if (this != &cp) 
    {
        for (int i = 0; i < 100; ++i) 
        {
            ideas[i] = cp.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() 
{
    std::cout << "Called Brain destructor\n";
}
