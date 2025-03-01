/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:37:03 by victor-linu       #+#    #+#             */
/*   Updated: 2025/03/01 19:19:21 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << RED << "Usage: " << argv[0] << " <sequence of integers>" << RESET << std::endl;
        return 1;
    }

    // Validate input arguments
    int i = 1;
    while (i < argc)
    {
        std::string arg(argv[i]);
        if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cerr << RED << "Error: Invalid input '" << arg << "'. Expected positive integers only." << RESET << std::endl;
            return 1;
        }
        i++;
    }
    try
    {
        PmergeMe sorter;
        sorter.sortAndMeasureTime(argv + 1);
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        return 2;
    }

    return 0;
}
