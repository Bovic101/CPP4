/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassWrongCat.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:38:53 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/30 09:54:00 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassWrongCat.hpp"

WrongAnimal::WrongAnimal() : cp("WrongAnimal") 
{
    std::cout << "Called wrong animal constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << "Called wrong animal destructor" << std::endl;
}

void WrongAnimal::makeSound() const 
{
    std::cout << "Wrong animal Sound" << std::endl;
}

std::string WrongAnimal::getCp() const 
{
    return cp;
}

WrongCat::WrongCat() 
{
    cp = "WrongCat";  // initilise cp to "WrongCat"
    std::cout << "Called WrongCat constructor" << std::endl;
}

WrongCat::~WrongCat() 
{
    std::cout << " Called WrongCat destructor" <<std::endl;
}

void WrongCat::makeSound() const 
{
    std::cout << "Wrong animal sound\n";  // give the same sound as WrongAnimal
}
