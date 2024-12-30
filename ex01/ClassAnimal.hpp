/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:38:38 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/30 11:13:55 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSANIMAL_HPP
#define CLASSANIMAL_HPP

#include <string>
#include <iostream>

class Animal 
{
    protected:
        std::string cp;  // Class member for the name

    public:
        Animal();  // Default constructor
        virtual ~Animal();  // Virtual destructor for proper cleanup

        virtual void makeSound() const;  // Virtual function to make sound
        std::string getCp() const;  // Getter for the 'cp' string
};

#endif
