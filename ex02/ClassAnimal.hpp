/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:38:38 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/01 21:05:18 by vodebunm         ###   ########.fr       */
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

    public:
        AAnimal();
        virtual ~AAnimal();  // Virtual destructor for cleanup

        virtual void makeSound() const= 0;  // Virtual function to make sound
        std::string getCp() const; 
};

#endif
