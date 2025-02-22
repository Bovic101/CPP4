/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:42:11 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/22 13:04:51 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <limits>

class ScalarConverter {
private:
    /* Check functions for input */
    static bool CharChecker(const std::string& arg);
    static bool IntChecker(const std::string& arg);
    static bool FloatChecker(const std::string& arg);
    static bool DoubleChecker(const std::string& arg);
    
    /* Print functions for converted data values */
    static void printChar(char c);
    static void printInt(int num);
    static void printFloat(float f);
    static void printDouble(double d);

public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& cp);
    ScalarConverter& operator=(const ScalarConverter& cp);
    ~ScalarConverter();

    // Method to determine the input type and convert it to char, int, float, and double
    static void convert(const std::string& arg);
};

#endif
