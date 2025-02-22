/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:15:15 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/22 13:33:45 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint> //This is for the unsiged inter ptr: uintptr_t
#include "Data.hpp"

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