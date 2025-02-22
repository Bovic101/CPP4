/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:41:41 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/22 12:34:23 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructor
ScalarConverter::ScalarConverter() {}
// Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter& cp)
{
    (void)cp;
}
// Copy Assignment Operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& cp)
{
    (void)cp;
    return *this;
}
//Destructor
ScalarConverter::~ScalarConverter() {}

//To check if input is char
bool ScalarConverter::CharChecker(const std::string& arg)
{
    return(arg.length() == 1 && std::isprint(arg[0]) && !std::isdigit(arg[0]));
}
bool ScalarConverter::IntChecker(const std::string& arg)
{
    int i = 0;
    if (arg[i] == '-' || arg[i] == '+')
    {
        i++;
    }
    while (i < arg.length())
    {
        if (!std::isdigit(arg[i]))
        {
            return(false);
        }
        i++;
    }
    
    return(true);
}

bool ScalarConverter::FloatChecker(const std::string& arg)
{
    if (arg == "-inff" || arg == "+inff" || arg == "nanf")
    {
        return(true);
    }
    int i = 0;
    bool decimal = false;
    if (arg[i] == '-' || arg[i] == '+')
    {
        i++;
    }
    while (i < arg.length())
    {
        if (arg[i] == '.')
        {
            if (decimal) //Having more than dot
            {
                return(false);
            }
            decimal=true;
            
        }
        else if (!std::isdigit(arg[i]))
        {
            return(i == arg.length() -1 && arg[i] == 'f'); //append 'f' at  the end 
        }
        i++;
        
    }
    return(decimal);
}

bool ScalarConverter::DoubleChecker(const std::string& arg)
{
    if (arg == "-inf" || arg == "+inf" || arg == "nan")
    {
        return(true);
    }
    int i = 0;
    bool decimal = false;
    if (arg[i] == '-' || arg[i] == '+')
    {
        i++;
    }
    while (i < arg.length())
    {
        if (arg[i] == '.')
        {
            if (decimal) //Having more than dot
            {
                return(false);
            }
            decimal=true;
            
        }
        else if (!std::isdigit(arg[i]))
        {
            return(false);
        }
        i++;
    }
    return(decimal);
}

/*Printing*/
void ScalarConverter::printfChar(char c)
{
    if (std::isprint(c))
    {
        std::cout << "char value: " << c << " "<< std::endl;
    }
    else
        std::cout << "char value: Can't be displayed" << std::endl;
}

void ScalarConverter::printfInt(char num)
{
    std::cout << "int value: " << num << std::endl;
}

void ScalarConverter::printfFloat(char c)
{
    std::cout << "float value: " << c;
    if (c == static_cast<int>(c)) std::cout << ".0";
    std::cout << "c" << std::endl;
}

void ScalarConverter::printfDouble(char n)
{
    std::cout << "double value : " << n;
    if (n == static_cast<int>(n)) std::cout << ".0";
    std::cout << std::endl;
}

/*Type conversion*/
void ScalarConverter::convert(const std::string& arg)
{
    if(CharChecker(arg))
    {
        char c = arg[0];
        printfChar(c);
        printfInt(static_cast <int>(c));
        printfFloat(static_cast<float>(c));
        printfDouble(static_cast<double>(c));
        return;
    }
    if (IntChecker(arg))
    {
        int num = std::atoi(arg.c_str());
        printfChar(static_cast<char>(num));
        printfChar(num);
        printfFloat(static_cast<float>(num));
        printfDouble(static_cast <double>(num));
        return;
    }
    if (FloatChecker(arg))
    {
        float c = std::atof(arg.c_str());
        printfChar(static_cast<char>(c));
        printfInt(static_cast <int> (c));
        printfFloat(c);
        printfDouble(static_cast<double>(c));
        return;
    }
    if (DoubleChecker(arg))
    {
        double n = std::atof(arg.c_str());
        printfChar(static_cast<char>(n));
        printfInt(static_cast<int>(n));
        printfFloat(static_cast<float>(n));
        printfDouble(n);
        return;
    }
    std::cout << "Unknown arg" <<std::endl;
}