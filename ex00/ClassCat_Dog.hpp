/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassCat_Dog.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:38:49 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/30 09:24:46 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSCAT_DOG_HPP
#define CLASSCAT_DOG_HPP

#include <istream>
#include "ClassAnimal.hpp"

class Dog : public Animal 
{
    public:
        Dog();
        ~Dog();
        void makeSound() const override;
};

class Cat : public Animal 
{
    public:
        Cat();
        ~Cat();
        void makeSound() const override;
};

#endif
