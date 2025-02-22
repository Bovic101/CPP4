/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:55:08 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/22 15:30:07 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

/*Function to generate a random instance of A, B, or C*/
Base	*generate(void)
{
	int	i;

	std::srand(std::time(NULL));  // random generator for class
	int select = std::rand() % 3; // Generates A, B or C
	i = 0;
	while (i < 3)
	{
		if (select == 0)
			return (new A());
		if (select == 1)
			return (new B());
		if (select == 2)
			return (new C());
		i++;
	}
	return (NULL);//endpoint but can not call
}

/*Function to identify the type using a pointer*/
void	identify(Base *p)
{
	int	i;

	if (!p)
	{
		std::cout << "Null*" << std::endl;
		return ;
	}
	i = 0;
	while (i < 3)
	{
		if (dynamic_cast<A *>(p))
		{
			std::cout << "A" << std::endl;
			return ;
		}
		if (dynamic_cast<B *>(p))
		{
			std::cout << "B" << std::endl;
			return ;
		}
		if (dynamic_cast<C *>(p))
		{
			std::cout << "C" << std::endl;
			return ;
		}
		i++;
	}
}

/*Function to identify the type using reference*/
void	identify(Base &p)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		try
		{
			(void)dynamic_cast<A &>(p);
			std::cout << "A" << std::endl;
			return ;
		}
		catch (...)
		{
		}
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			return ;
		}
		catch (...)
		{
		}
		try
		{
			(void)dynamic_cast<C &>(p);
			std::cout << "C" << std::endl;
			return ;
		}
		catch (...)
		{
		}
		i++; //  does not execute as it return on success.
	}
}

int	main(void)
{
	Base *obj = generate();

	std::cout << "Identification by pointer:" << std::endl;
	identify(obj);

	std::cout << "Identification by reference:" << std::endl;
	identify(*obj);

	delete obj;
	return (0);
}