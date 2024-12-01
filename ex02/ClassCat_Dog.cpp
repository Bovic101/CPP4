/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCat_Dog.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:38:43 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/01 21:30:20 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassCat_Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain()) 
{
    cp = "Dog";  // Initialize cp to "Dog"
    std::cout << "Called Dog constructor\n";
}

Dog::Dog(const Dog& cp) : AAnimal(cp), brain(new Brain(*cp.brain)) 
{
    std::cout << "Called Dog copy constructor\n";
}

Dog& Dog::operator=(const Dog& cp) 
{
    std::cout << "Called Dog assignment operator\n";
    if (this != &cp) 
    {
        AAnimal::operator=(cp);
        *brain = *cp.brain;
    }
    return *this;
}

Dog::~Dog() 
{
    delete brain;
    std::cout << "Called Dog destructor\n";
}

void Dog::makeSound() const 
{
    std::cout << "Woof! Woof!\n";  // Dog's sound
}

Cat::Cat() : brain(new Brain()) 
{
    cp = "Cat";  // Initialize cp to "Cat"
    std::cout << "Called Cat constructor\n";
}

Cat::Cat(const Cat& cp) : AAnimal(cp), brain(new Brain(*cp.brain)) 
{
    std::cout << "Called Cat copy constructor\n";
}

Cat& Cat::operator=(const Cat& cp) 
{
    std::cout << "Called Cat assignment operator\n";
    if (this != &cp) 
    {
        AAnimal::operator=(cp);
        *brain = *cp.brain;
    }
    return *this;
}

Cat::~Cat() 
{
    delete brain;
    std::cout << "Called Cat destructor\n";
}

void Cat::makeSound() const 
{
    std::cout << "Meow! Meow!\n";  // Cat's sound
}

