/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:35:00 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/23 09:47:46 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
/*Funcion print an integer*/
void printInt(int &x) 
{
    std::cout << x << " ";
}

/*Function to print a float*/
void printFloat(float &n) 
{
    std::cout << n << " ";
}

/*Function to print a string*/
void printString(std::string &str) {
    std::cout << str << " ";
}

/*Function to multiply an integer by 2*/ 
void multiplyByTwo(int &n) 
{
    n *= 2;
}

int main() {
    int Array[] = {10, 2, 11, 4, 5};
    size_t array_len = sizeof(Array) / sizeof(Array[0]); //cal size of array

    std::cout << "Original int array: ";
    iter(Array, array_len, printInt);
    std::cout << std::endl;

    iter(Array, array_len, multiplyByTwo);

    std::cout << "Result of Array multiply by 2: ";
    iter(Array, array_len, printInt);
    std::cout << std::endl;

    /*Test for float array*/
    float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    size_t floatSize = sizeof(floatArr) / sizeof(floatArr[0]);

    std::cout << "Float array: ";
    iter(floatArr, floatSize, printFloat);
    std::cout << std::endl;

    /* Test for string array*/
    std::string strArr[] = {"Victor", "is a", "winner"};
    size_t str_len = sizeof(strArr) / sizeof(strArr[0]); //cal length of str.

    std::cout << "String array: ";
    iter(strArr, str_len, printString);
    std::cout << std::endl;

    return 0;
}
