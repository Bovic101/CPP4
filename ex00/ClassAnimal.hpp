/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:38:38 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/30 08:53:04 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSANIMAL_HPP
#define CLASSANIMAL_HPP

#include <string>
#include <iostream>

class Animal 
{
    protected:
        std::string cp;

    public:
        Animal();
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getCp() const;
};

#endif