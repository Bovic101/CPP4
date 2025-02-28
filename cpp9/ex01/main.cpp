/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:43:17 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/28 12:33:19 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage Format: ./RPN \"expression\"\n";
		return (1);
	}

	RPN exec;
	exec.processExpression(argv[1]);

	return (0);
}