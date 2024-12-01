/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:33:57 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/01 21:04:58 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAnimal.hpp"

AAnimal::AAnimal() : cp("Unknown Animal") 
{
    std::cout << "Called constructor for Animal\n";
}

AAnimal::~AAnimal() 
{
    std::cout << "Called destructor for Animal\n";
}

void AAnimal::makeSound() const 
{
    std::cout << "Animal is making a sound\n";
}

std::string AAnimal::getCp() const 
{
    return cp;
}
