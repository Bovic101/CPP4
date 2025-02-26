/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:54:01 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/26 10:10:51 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
int	main(void)
{
	try
	{
		Span mySpan(5);
		mySpan.addNumber(2);
		mySpan.addNumber(5);
		mySpan.addNumber(7);
		mySpan.addNumber(9);
		mySpan.addNumber(11);
		std::cout << "The shortest span is " << mySpan.shortestSpan() << std::endl;
		std::cout << "The longest span is " << mySpan.longestSpan() << std::endl;
		mySpan.addNumber(25);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Span mySpan2(3);
		mySpan2.addNumber(42);
        //mySpan2.addNumber(12);
		std::cout << "Shortest span: " << mySpan2.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
    */

int	main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}