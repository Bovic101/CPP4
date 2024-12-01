/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:38:38 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/01 21:34:42 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSAANIMAL_HPP
#define CLASSAANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal 
{
    protected:
        std::string cp;

        // Make constructor protected to prevent direct instantiation of AAnimal
        AAnimal();  // Declare the constructor

    public:
        virtual ~AAnimal();  // Declare the destructor

        virtual void makeSound() const = 0; // Pure virtual function for making sound

        std::string getCp() const;  // Declare the getCp function
};

#endif



