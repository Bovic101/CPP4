/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:53:26 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/26 09:28:30 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span {
private:
    unsigned int _maxLen;
    std::vector<int> _value;

public:
    Span(); //Default constructor
    Span(unsigned int N);//paratḿerised constructor
    Span(const Span& cp);//copy constructor
    Span& operator=(const Span& cp);
    ~Span();

    // functions
    void addNumber(int n);
    int shortestSpan();
    int longestSpan();

    // Exception handling
    class CustomException1 : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Span is full";
        }
    };

    class CustomException2 : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "No span can be found.";
        }
    };
};

#endif