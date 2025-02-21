/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:13:05 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/21 01:25:21 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ClassBureaucrat.hpp"

#include "Intern.hpp"

// Default Constructor
Intern::Intern() {}

// Copy Constructor
Intern::Intern(const Intern& cp) { (void)cp; }

// Copy Assignment Operator
Intern& Intern::operator=(const Intern& cp) {
    (void)cp;
    return *this;
}

// Destructor
Intern::~Intern() {}

// Functions that create  forms
AForm* createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* createPardon(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) 
{
    // Available forms and their corresponding creation functions
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[])(std::string) = {
        createShrubbery,
        createRobotomy,
        createPardon
    };

    int i = 0;
    while (i < 3) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
        i++;
    }
    std::cerr << "Error: Form '" << formName << "' does not exist!" << std::endl;// Error if the form doesn't exist
    return NULL;
}
