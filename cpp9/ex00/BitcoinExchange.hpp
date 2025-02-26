/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:35:03 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/26 22:13:19 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <map>
#include <regex>
#include <fstream>
#include <optional>//handle missing date
#include <filesystem> //check if dile exit
#include <string>

class Bitcoin{
    private:
    std::map<std::string, double> Xchangerate;
    
    bool DateValidator(const std::string& date);
    bool ValueValidator(const std::string &val);
    std::optional<std::string>SearchForLowerDate(const std::string &datum);
    
    public:
    Bitcoin();
    Bitcoin(const Bitcoin& cp);
    Bitcoin &operator=(const Bitcoin &cp);
    
    void ExchangeRateStack(const std::string& f);
    void InputFileProcessor(const std::string& f);
};

#endif
