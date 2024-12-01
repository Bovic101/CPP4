/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCat_Dog.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:38:49 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/01 22:21:25 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCAT_DOG_HPP
#define CLASSCAT_DOG_HPP

#include "ClassAnimal.hpp"
#include "ClassBrain.hpp"

class Dog : public AAnimal 
{
    private:
        Brain* brain;

    public:
        Dog();
        Dog(const Dog& cp);
        Dog& operator=(const Dog& cp);
        ~Dog();
        void makeSound() const;
};

class Cat : public AAnimal 
{
    private:
        Brain* brain;

    public:
        Cat();
        Cat(const Cat& cp);
        Cat& operator=(const Cat& cp);
        ~Cat();
        void makeSound() const;
};

#endif




