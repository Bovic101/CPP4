/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:44:33 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/28 11:52:00 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class RPN{
    private:
    std::stack<int> num; //Tho store the oprands
    
    public:
    RPN();
    RPN(const RPN &cp);
    RPN& operator=(const RPN &cp);
    ~RPN();
    
    void processExpression(const std::string &exp); //RPN expression processor
};
#endif