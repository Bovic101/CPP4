/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:16:03 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/22 14:17:09 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    /*Data creation*/
    Data test;
    test.str1 = 42;
    test.str2 = "Heilbronn";
    
    /*Connversion of Data for storage or transmission* and second back to Data ptr*/
    uintptr_t raw = Serializer::serialize(&test);
    Data* deserializedData = Serializer::deserialize(raw);
    
    /*output*/
    std::cout << "Main  data pointer: " << &test << std::endl;
    std::cout << "Serialized Data Ptr: " << raw << std::endl;
    std::cout << "Deconstructed Data Ptr: " <<deserializedData << std::endl;
    
    return(0);
}