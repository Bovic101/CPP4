/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:46:57 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 14:42:51 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//Default Constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Roboter Request", 72, 45), _target("Default")
{
}

//Parameterise Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &targetfile)
	: AForm("Roboter Request", 72, 45), _target(targetfile)
{
}
//Copy Vonstructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cp)
	: AForm(cp), _target(cp._target)
{
}
// Copy Assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cp)
{
	if (this != &cp)
	{
		_target = cp._target;
	}
	return (*this);
}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
}

//Execute the Form
void RobotomyRequestForm::execute(BUREAUCRAT const & executor) const
{
    if (!getFormSigned())
    {
        throw AForm::FormUnableToSignException();
    }
    if (executor.getBgrade() > getExecGrade())
    {
        throw AForm::GradeTooLowException();
    }
    std::cout << " Drilling noises tatatatattatattata" << std::endl;
    srand(time(NULL)); //Random seed initiliastion
    if (rand() % 2) //use to randomly determine success or failure
    {
        std::cout << _target << "was successfully robotomised" << std::endl;
    }
    else
        std::cout << "Robotomy failed " << _target <<std::endl;
}
