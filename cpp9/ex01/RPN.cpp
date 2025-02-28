/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:43:41 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/28 12:28:06 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() = default; //default constructor
RPN::RPN(const RPN &cp) = default; //parametised constructor
RPN& RPN::operator=(const RPN &cp) = default;
RPN::~RPN() = default;

/*Function that process RPN  expressions and output the result*/
void RPN:: processExpression(const std::string &exp)
{
    std::istringstream str(exp);
    std::string token;

    while (str>> token) // This read  each token from input
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (num.size() < 2)
            {
                std::cerr << "Error: Operands insufficient\n";
                return;
            }

            int b = num.top(); num.pop();
            int a = num.top(); num.pop();
            int c= 0;

            if (token == "+") c = a + b;
            else if (token == "-") c = a - b;
            else if (token == "*") c = a * b;
            else if (token == "/")
            {
                if (b == 0)
                {
                    std::cerr << "Error: Division by zero\n";
                    return;
                }
                c = a / b;
            }

            num.push(c);
        }
        else
        {
            std::istringstream numStr(token);
            int n;
            if (!(numStr >> n))  // This validate number
            {
                std::cerr << "Error: Invalid token input -> " << token << std::endl;
                return;
            }
            num.push(n);
        }
    }

    if (num.size() != 1)
    {
        std::cerr << "Error: Invalid RPN expression\n";
        return;
    }

    std::cout << num.top() << std::endl;
}