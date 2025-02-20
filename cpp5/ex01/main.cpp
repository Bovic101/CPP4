/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:06:32 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/09 17:15:59 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassBureaucrat.hpp"

int main()
{
    try
    {
        BUREAUCRAT winner("Adeola", 1);
        BUREAUCRAT loser("Victor", 150);
        BUREAUCRAT average("Bolanle", 75);
        BUREAUCRAT copy_validator= loser;

        std::cout << winner <<std::endl;
        std::cout << loser <<std::endl;
        std::cout << average <<std::endl;
        std::cout <<"Copy constructor in operation: " << winner <<std::endl;

        std::cout << "\nIncreasing the average grade" <<std::endl;
        average.increaseGrade();
        std::cout << average <<std::endl;

        std::cout << "\nDecreasing the average grade" <<std::endl;
        average.decreaseGrade();
        std::cout << average <<std::endl;
        /*Throw exception error part*/
        std::cout << "\nIncreasing the winner grade" <<std::endl;
        winner.increaseGrade();
        std::cout << "\nDecreasing the loser grade" <<std::endl;
        winner.decreaseGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "\nCreating a Bureaucrat with grade 0 " <<std::endl;
        BUREAUCRAT Zero("N/A", 0); //this throw an exception
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}