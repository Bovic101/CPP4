/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:37:03 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/28 13:42:44 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: Usage Format: ./PmergeMe <sequence >\n";
		return (1);
	}

	PmergeMe SortData;
	SortData.sortAndMeasureTime(argv + 1);

	return (0);
}