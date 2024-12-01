/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:39:00 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/01 21:32:54 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAnimal.hpp"
#include "ClassCat_Dog.hpp"
#include "ClassBrain.hpp"

int main() 
{
    const AAnimal* j = new Dog();  // Create a Dog object
    const AAnimal* i = new Cat();  // Create a Cat object

    j->makeSound();  // Output: Woof! Woof!
    i->makeSound();  // Output: Meow! Meow!

    delete j;  // Delete Dog object
    delete i;  // Delete Cat object

    return 0;
}
