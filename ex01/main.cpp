/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:39:00 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/30 11:17:10 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassAnimal.hpp"
#include "ClassCat_Dog.hpp"
#include "ClassBrain.hpp"

int main() 
{
    const Animal* j = new Dog();  // Create a Dog object
    const Animal* i = new Cat();  // Create a Cat object

    j->makeSound();
    i->makeSound(); 
    delete j;
    delete i;

    return 0;
}
