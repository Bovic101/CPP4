/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:54:38 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/25 15:39:00 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> val;
	val.push_back(1);
	val.push_back(2);
	val.push_back(3);
	val.push_back(4);
	val.push_back(5);
	try
	{
		std::vector<int>::iterator iterate = easyfind(val, 2);
		std::cout << "Found: " << *iterate << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::iterator iterate = easyfind(val, 7);
		std::cout << "Found: " << *iterate << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::iterator iterate = easyfind(val, 5);
		std::cout << "Found: " << *iterate << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
