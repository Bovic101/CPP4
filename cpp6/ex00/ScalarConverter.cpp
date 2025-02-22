/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:41:41 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/22 13:06:16 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>

// Constructor
ScalarConverter::ScalarConverter() {}

// Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter& cp) {
    (void)cp;
}

// Copy Assignment Operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& cp) {
    (void)cp;
    return *this;
}

// Destructor
ScalarConverter::~ScalarConverter() {}

// Check if input is a char
bool ScalarConverter::CharChecker(const std::string& arg) {
    return (arg.length() == 1 && std::isprint(arg[0]) && !std::isdigit(arg[0]));
}

// Check if input is an integer
bool ScalarConverter::IntChecker(const std::string& arg) {
    size_t i = 0;
    if (arg[i] == '-' || arg[i] == '+') i++;
    while (i < arg.length()) {
        if (!std::isdigit(arg[i])) return false;
        i++;
    }
    return true;
}

// Check if input is a float
bool ScalarConverter::FloatChecker(const std::string& arg) {
    if (arg == "-inff" || arg == "+inff" || arg == "nanf") return true;

    size_t i = 0;
    bool decimal = false;
    if (arg[i] == '-' || arg[i] == '+') i++;

    while (i < arg.length()) {
        if (arg[i] == '.') {
            if (decimal) return false; // More than one dot
            decimal = true;
        } else if (!std::isdigit(arg[i])) {
            return (i == arg.length() - 1 && arg[i] == 'f'); // 'f' must be at the end
        }
        i++;
    }
    return decimal;
}

// Check if input is a double
bool ScalarConverter::DoubleChecker(const std::string& arg) {
    if (arg == "-inf" || arg == "+inf" || arg == "nan") return true;

    size_t i = 0;
    bool decimal = false;
    if (arg[i] == '-' || arg[i] == '+') i++;

    while (i < arg.length()) {
        if (arg[i] == '.') {
            if (decimal) return false;
            decimal = true;
        } else if (!std::isdigit(arg[i])) {
            return false;
        }
        i++;
    }
    return decimal;
}

/* Print functions */
void ScalarConverter::printChar(char c) {
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non-displayable" << std::endl;
}

void ScalarConverter::printInt(int num) {
    if (num == std::numeric_limits<int>::min()) {
        std::cout << "int: Non-displayable" << std::endl;
    } else {
        std::cout << "int: " << num << std::endl;
    }
}

void ScalarConverter::printFloat(float f) {
    std::cout << "float: " << f;
    if (f == static_cast<int>(f)) std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
    std::cout << "double: " << d;
    if (d == static_cast<int>(d)) std::cout << ".0";
    std::cout << std::endl;
}

/* Type conversion */
void ScalarConverter::convert(const std::string& arg) {
    if (CharChecker(arg)) {
        char c = arg[0];
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
        return;
    }

    if (IntChecker(arg)) {
        int num = std::strtol(arg.c_str(), NULL, 10);
        printChar(static_cast<char>(num));
        printInt(num);
        printFloat(static_cast<float>(num));
        printDouble(static_cast<double>(num));
        return;
    }

    if (FloatChecker(arg)) {
        float f = std::strtof(arg.c_str(), NULL);
        printChar(static_cast<char>(f));

        // Fix for NaN case
        if (std::isnan(f)) {
            std::cout << "int: Non-displayable" << std::endl;
        } else {
            printInt(static_cast<int>(f));
        }

        printFloat(f);
        printDouble(static_cast<double>(f));
        return;
    }

    if (DoubleChecker(arg)) {
        double d = std::strtod(arg.c_str(), NULL);
        printChar(static_cast<char>(d));

        // Fix for NaN case
        if (std::isnan(d)) {
            std::cout << "int: Non-displayable" << std::endl;
        } else {
            printInt(static_cast<int>(d));
        }

        printFloat(static_cast<float>(d));
        printDouble(d);
        return;
    }

    std::cout << "Unknown input" << std::endl;
}


