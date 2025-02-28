/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:34:08 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/28 11:18:25 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Usage: ./btc <csv_file\n";
        return(1);
    }

    Bitcoin coin;
    coin.ExchangeRateStack("data.csv");//To extract rate from the csv file
    coin.InputFileProcessor(argv[1]);
    return(0);
}
