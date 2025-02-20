/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:46:57 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 17:22:15 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>  // Needed for rand()
#include <ctime>    // Needed for time()

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45), _target("Default")
{
    srand(time(NULL)); // Seed the random number generator once
}

// Parameterized Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request", 72, 45), _target(target)
{
    srand(time(NULL)); // Seed the random number generator once
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cp)
	: AForm(cp), _target(cp._target)
{
}

// Copy Assignment Operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cp)
{
	if (this != &cp)
	{
		_target = cp._target;
	}
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Execute the form
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!getFormSigned()) 
    {
        throw AForm::FormUnableToSignException();
    }
    if (executor.getBgrade() > getExecGrade())
    {
        throw AForm::GradeTooLowException();
    }

    std::cout << "Drilling noises... tatatatattatattata!" << std::endl;

    bool success = (rand() % 2 == 0);
    if (success)
    {
        std::cout << _target << " was successfully robotomized!" << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed for " << _target << "." << std::endl;
    }
}
