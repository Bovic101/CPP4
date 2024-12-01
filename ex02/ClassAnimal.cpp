/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:33:57 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/01 21:34:57 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAnimal.hpp"

// Define the constructor
AAnimal::AAnimal() : cp("Unknown Animal") 
{
    std::cout << "Called constructor for AAnimal\n";
}

// Define the destructor
AAnimal::~AAnimal() 
{
    std::cout << "Called destructor for AAnimal\n";
}

// Define the getCp function
std::string AAnimal::getCp() const 
{
    return cp;
}

