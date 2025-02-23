/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:52:31 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/23 10:40:40 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/*Function to print an Array of any type*/
template <typename T>
void	printArr(const Array<T> &array)
{
	size_t	i;

	i = 0;
	while (i < array.size())
	{
		std::cout << array[i] << " ";
		i++;
	}
	std::cout << std::endl;
}

int	main(void)
{
	size_t	i;
	size_t	j;

	std::cout << "----- Testing Integer Array -----" << std::endl;
	Array<int> intArray(5);
	i = 0;
	while (i < intArray.size())
	{
		intArray[i] = (i + 1) * 5;
		i++;
	}
	std::cout << "Integer Array: ";
	printArr(intArray);
	std::cout << "\n----- Testing Float Array -----" << std::endl;
	Array<float> floatArray(5);
	j = 0;
	while (j < floatArray.size())
	{
		floatArray[j] = (j + 1) * 2.2f;
		j++;
	}
	std::cout << "Float Array: ";
	printArr(floatArray);
	std::cout << "\n----- Testing String Array -----" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "Victor";
	strArray[1] = "Bolanle";
    strArray[2] = "Odebunmi";
    
	std::cout << "String Array: ";
	printArr(strArray);
	std::cout << "\n----- Testing Copy Constructor -----" << std::endl;
	Array<int> copyArray(intArray);
	std::cout << "Copied Integer Array: ";
	printArr(copyArray);
	std::cout << "\n----- Testing Assignment Operator -----" << std::endl;
	Array<int> assignedArray;
	assignedArray = intArray;
	std::cout << "Assigned Integer Array: ";
	printArr(assignedArray);
	std::cout << "\n----- Testing Out-of-Bounds-----" << std::endl;
	try
	{
		std::cout << intArray[6] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
