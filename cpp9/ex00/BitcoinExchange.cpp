/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:34:38 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/28 10:46:47 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() = default;
Bitcoin::Bitcoin(const Bitcoin &cp) = default;
Bitcoin& Bitcoin::operator=(const Bitcoin &cp) = default;
Bitcoin::~Bitcoin() = default;

// Helper function to trim leading and trailing spaces
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

// Function to load the exchange rate from the .csv file
void Bitcoin::ExchangeRateStack(const std::string &f)
{
    if (!std::filesystem::exists(f))
    {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
    }
    std::ifstream infile(f);
    if (!infile.is_open())
    {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        std::stringstream save(line);
        std::string date, val;
        if (std::getline(save, date, ',') && std::getline(save, val))
        {
            date = trim(date);
            val = trim(val);

            // Validate date and value
            if (DateValidator(date))
            {
                try {
                    double rate = std::stod(val);
                    Xchangerate[date] = rate;  // Store exchange rate for the date
                } catch (...) {
                }
            }
        }
    }
    infile.close();
}

// Function to process the input file
void Bitcoin::InputFileProcessor(const std::string& f)
{
    std::ifstream infile(f);
    if (!infile.is_open())
    {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
    }

    /*Implementation of  flag to skip the header line*/
    std::string line;
    bool SkipFirstLine = true;
    while (std::getline(infile, line))
    {
        if (SkipFirstLine) {
            SkipFirstLine = false;
            continue;
        }

        std::stringstream save(line);
        std::string date, val;
        if (std::getline(save, date, '|') && std::getline(save, val))
        {
            date = trim(date);
            val = trim(val);

            // Date validation
            if (!DateValidator(date))
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            if (val == "-1")
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }

            // Validate value range
            if (!ValueValidator(val))
            {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }

            // Convert value to double
            double btcVal = std::stod(val);

            // Find the closest lower date with a valid exchange rate
            auto closestDate = SearchForLowerDate(date);
            if (!closestDate)
            {
                std::cerr << "Error: Date not found for " << date << std::endl;
                continue;
            }

            // Calculate the bitcoin value for that date
            double Xchange = Xchangerate[*closestDate];
            std::cout << date << " => " << btcVal << " = " << btcVal * Xchange << std::endl;
        }
        else
        {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    infile.close();
}

/*Function to validate the date format*/
bool Bitcoin::DateValidator(const std::string &date)
{
    return std::regex_match(date, std::regex(R"(\d{4}-\d{2}-\d{2})"));
}

/*Function to validate the bitcoin value */
bool Bitcoin::ValueValidator(const std::string& val)
{
    try
    {
        double number = std::stod(val);
        return (number >= 0.0 && number <= 1000.0);
    }
    catch (...)
    {
        return false;
    }
}

/*Function to search for the closest lower date in the data.csv*/
std::optional<std::string> Bitcoin::SearchForLowerDate(const std::string &datum)
{
    auto n = Xchangerate.lower_bound(datum);
    if (n != Xchangerate.begin())
    {
        --n;
        return n->first;
    }
    return std::nullopt;
}









