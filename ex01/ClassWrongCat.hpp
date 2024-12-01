/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassWrongCat.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:38:56 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/01 22:18:59 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSWRONGCAT_HPP
#define CLASSWRONGCAT_HPP

#include "iostream"
#include "ClassAnimal.hpp"

class WrongAnimal 
{
    protected:
        std::string cp; 

    public:
        WrongAnimal();
        virtual ~WrongAnimal();

        virtual void makeSound() const;
        std::string getCp() const; //getter
};

class WrongCat : public WrongAnimal 
{
    public:
        WrongCat();
        ~WrongCat();
        void makeSound() const;
};

#endif
