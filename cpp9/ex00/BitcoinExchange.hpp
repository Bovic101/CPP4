/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:35:03 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/28 11:17:38 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <filesystem>
# include <fstream>
# include <iostream>
# include <map>
# include <optional>
# include <regex>
# include <sstream>
# include <string>

class Bitcoin
{
  private:
	std::map<std::string, double> Xchangerate; // Search closest lower date with exchange rate

  public:
	Bitcoin();
	Bitcoin(const Bitcoin &cp);
	Bitcoin &operator=(const Bitcoin &cp);
	~Bitcoin();

	// Load exchange rates from file
    void ExchangeRateStack(const std::string &f); 

    //Process input values from file	
	void InputFileProcessor(const std::string &f);

	bool DateValidator(const std::string &date); // Check for the date format
	bool ValueValidator(const std::string &val); // check the value

	// Search closest lower date with exchange rate
    std::optional<std::string> SearchForLowerDate(const std::string &datum);
		
};

#endif



