/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:34:38 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/27 10:22:24 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() = default;
Bitcoin::Bitcoin(const Bitcoin &cp) = default;
Bitcoin& Bitcoin::operator=(const Bitcoin &cp) = default;
Bitcoin::~Bitcoin() = default;

/*Function to load the exchange rate feom the .csv file*/
void Bitcoin::ExchangeRateStack(const std::string &f)
{
    if (!std::filesystem::exists(f))
    {
        std::cerr << "Failure: File is not existing: " << f << std::endl;
        return;
    }
    std::ifstream infile(f);
    if (!infile.is_open())
    {
        std::cerr << "Error: Unable to pen the csv file. \n";
        return;
    }
    std::string line;
    while (std::getline(infile, line));
    {
        std::stringstream save(line);
        std::string date, val;
        if (std::getline(save, date, ',') && std::getline(save, val))
        {
            if (DateValidator(date) && ValueValidator(val))
            {
                Xchangerate[date] = std::stod(val);
            }
            
        }
        
        
    }
    
    infile.close();
}

/*Function to process the input file*/
void Bitcoin::InputFileProcessor(const std::string& f)
{
    if (!std::filesystem::exists(f))
    {
        std::cerr << "Failure: File is not existing: " << f << std::endl;
        return;
    }
    std::ifstream infile(f);
    if (!infile.is_open())
    {
        std::cerr << "Error: Unable to pen the csv file. \n";
        return;
    }
    std::string line;
    while (std::getline(infile, line))
    {
        std::stringstream save(line);
        std::string date, val;
        if (std::getline(save, date, '|') && std::getline(save, val))
        {
            date = date.substr(0, date.find_last_not_of(" ")+ 1);
            val = val.substr(val.find_first_not_of(" "));
            if (!DateValidator(date))
            {
                std::cerr << "Failure: bad input " << date << std::endl;
                continue;
            }
            if (ValueValidator(val))
            {
                std::cerr << "Failure: Invalid value. " << date << std::endl;
                continue;
            }
            double btcVal = std::stod(val);
            auto closestDate = SearchForLowerDate(date);
            if (!closestDate)
            {
                std::cerr << "Failure: Date not found for. " << date << std::endl;
                continue;
            }
            double Xchange = Xchangerate[*closestDate];
            std::cout << date << "--" << btcVal << "=" << btcVal * Xchange << std::endl;
            continue;
            
        }
        else
        {
            std::cerr << "Error: bad input --" << line << std::endl;
        }
    }
    infile.close();
}

/*Function to validate date format*/
bool Bitcoin::DateValidator(const std::string &date)
{
    return std::regex_match(date, std::regex(R"(\d{4}-\d{2}-\d{2})"));
}

/*Function to validate the bitcoin value*/
bool Bitcoin::ValueValidator(const std::string& val)
{
    try
    {
        double number = std::stod(val);
        return(number >= 0.0 && number <= 1000.0);
    }
    catch(...)
    {
        return false;
    }
}

/*Function to fint the closet lower date in the csv file*/
std::optional<std::string> Bitcoin::SearchForLowerDate(const std::string &datum)
{
    auto n = Xchangerate.lower_bound(datum);
    if (n != Xchangerate.begin())
    {
        --n;
        return(n->first);
    }
    return(std::nullopt);
}