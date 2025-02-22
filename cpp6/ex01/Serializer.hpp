/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:15:15 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/22 14:14:44 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstddef>
#include "Data.hpp"

typedef unsigned long uintptr_t; //manually declared unisigned int pointer as it is no available in c++98

class Serializer{
    public:
    Serializer();
    Serializer(const Serializer& cp);
    Serializer& operator=(const Serializer& cp);
    ~Serializer();

    //Function for storing data and reconstructing data
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif