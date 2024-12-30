/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCat_Dog.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:38:43 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/30 09:24:31 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassCat_Dog.hpp"

Dog::Dog() 
{
    cp = "Dog";  // Setting  cp to Class Animal Variable to "Dog"
    std::cout << "Called Dog constructor\n";
}

Dog::~Dog() 
{
    std::cout << "Called Dog destructor" << std::endl;
}

void Dog::makeSound() const 
{
    std::cout << "gbogbo\n";
}

Cat::Cat() 
{
    cp = "Cat";  
    std::cout << "Called cat constructor\n";
}

Cat::~Cat() 
{
    std::cout << " Called cat constructor\n";
}

void Cat::makeSound() const 
{
    std::cout << "Meow" <<std::endl;
}