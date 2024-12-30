/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBrain.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:15:33 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/30 10:36:52 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassBrain.hpp"

Brain::Brain() 
{
    std::cout << "Called Brain constructor." << std::endl;
}

Brain::Brain(const Brain &cp) 
{
    std::cout << "A copy of brain constructor called" << std::endl;
    int i = 0;
    while (i < 100) 
    {
        this->ideas[i] = cp.ideas[i];
        i++;
    }
}

Brain &Brain::operator=(const Brain &cp) 
{
    std::cout << "Called brain assignment operator" << std::endl;
    if (this != &cp) {
        int i = 0;
        while (i < 100) {
            this->ideas[i] = cp.ideas[i];
            i++;
        }
    }
    return *this;
}

Brain::~Brain() 
{
    std::cout << "Called brain constructor" << std::endl;
}