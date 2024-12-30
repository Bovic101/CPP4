/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:39:00 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/30 10:02:25 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAnimal.hpp"
#include "ClassCat_Dog.hpp"
#include "ClassWrongCat.hpp"
int main() 
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    // Displaying the types of the animals
    std::cout << j->getCp() << " " << std::endl;
    std::cout << i->getCp() << " " << std::endl; 
    
    i->makeSound();
    j->makeSound();
    meta->makeSound();  // Output: random animal sound

    delete meta;
    delete j;
    delete i;

    return 0;
}