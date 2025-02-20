/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:06:32 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 17:54:12 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "ClassBureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AClassForm.hpp"

int main()
{
    srand(time(NULL)); // Initialize random seed

    Bureaucrat winner("Adeola", 70);  // Adeola with grade 75
    Bureaucrat average("Victor", 35);  // Victor with grade 5

    ShrubberyCreationForm tree("Big");
    RobotomyRequestForm alexa("Scream");
    PresidentialPardonForm prisoner("Escobar");

    std::cout << "\n--- Commencement of Signing Forms ---\n" << std::endl;

    // Signing Forms with Exception Handling
    try {
        winner.signForm(tree);
    } catch (const std::exception &e) {
        std::cerr << winner.getBname() << " couldn't sign " << tree.getSignee()
                  << " because: " << e.what() << std::endl;
    }

    try {
        winner.signForm(alexa);
    } catch (const std::exception &e) {
        std::cerr << winner.getBname() << " couldn't sign " << alexa.getSignee()
                  << " because: " << e.what() << std::endl;
    }

    try {
        average.signForm(prisoner);
    } catch (const std::exception &e) {
        std::cerr << average.getBname() << " couldn't sign " << prisoner.getSignee()
                  << " because: " << e.what() << std::endl;
    }

    std::cout << "\n--- Form Execution Has Started ---\n" << std::endl;

    // Executing Forms with Exception Handling
    try {
        winner.executeForm(tree);
    } catch (const std::exception &e) {
        std::cerr << winner.getBname() << " couldn't execute " << tree.getSignee()
                  << " because: " << e.what() << std::endl;
    }

    try {
        winner.executeForm(alexa);
    } catch (const std::exception &e) {
        std::cerr << winner.getBname() << " couldn't execute " << alexa.getSignee()
                  << " because: " << e.what() << std::endl;
    }

    try {
        average.executeForm(alexa);
    } catch (const std::exception &e) {
        std::cerr << average.getBname() << " couldn't execute " << alexa.getSignee()
                  << " because: " << e.what() << std::endl;
    }

    try {
        average.executeForm(prisoner);
    } catch (const std::exception &e) {
        std::cerr << average.getBname() << " couldn't execute " << prisoner.getSignee()
                  << " because: " << e.what() << std::endl;
    }

    return 0;
}
