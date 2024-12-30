/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:33:57 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/30 09:11:43 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAnimal.hpp"

Animal::Animal() : cp("") 
{
    std::cout << " Called constructor for animal\n";
}

Animal::~Animal() {
    std::cout << "Called destructor for animal" << std::endl;
}

void Animal::makeSound() const 
{
    std::cout << "making sound" << std::endl;
}

std::string Animal::getCp() const 
{
    return cp;
}
