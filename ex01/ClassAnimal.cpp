/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:33:57 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/30 11:14:11 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAnimal.hpp"

Animal::Animal() : cp("Unknown Animal") 
{
    std::cout << "Called constructor for Animal\n";
}

Animal::~Animal() 
{
    std::cout << "Called destructor for Animal\n";
}

void Animal::makeSound() const 
{
    std::cout << "Animal is making a sound\n";
}

std::string Animal::getCp() const 
{
    return cp;
}
