/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCat_Dog.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:38:49 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/01 22:19:31 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCAT_DOG_HPP
#define CLASSCAT_DOG_HPP

#include "ClassAnimal.hpp"
#include "ClassBrain.hpp"

class Dog : public Animal 
{
    private:
        Brain* brain;  // Brain object for the Dog

    public:
        Dog();  // Constructor
        Dog(const Dog& cp);  // Copy constructor
        Dog& operator=(const Dog& cp);  // Assignment operator
        virtual ~Dog();  // Destructor

        void makeSound() const;  // Override makeSound for Dog
};

class Cat : public Animal 
{
    private:
        Brain* brain;  // Brain object for the Cat

    public:
        Cat();  // Constructor
        Cat(const Cat& cp);  // Copy constructor
        Cat& operator=(const Cat& cp);  // Assignment operator
        virtual ~Cat();  // Destructor

        void makeSound() const;  // Override makeSound for Cat
};

#endif


