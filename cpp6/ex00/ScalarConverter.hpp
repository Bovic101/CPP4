/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:42:11 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/22 10:03:14 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <limits>

class ScalarConverter{
    private:
    /*Check functions for input*/
    static bool CharChecker(const std::string& arg);
    static bool IntChecker(const std::string& arg);
    static bool FloatChecker(const std::string& arg);
    static bool DoubleChecker(const std::string& arg);
    
    /*print functins for converted datavalue*/
    static void printfChar(char c);
    static void printfInt(char num);
    static void printfFloat(char c);
    static void printfDouble(char  n);
    
    public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& cp);
    ScalarConverter& operator=(const ScalarConverter& cp);
    ~ScalarConverter();
    
    //Method
    /*The function determine the input type adn convert it to char,int,f and double*/
    static void convert(const std::string& arg);
};

#endif