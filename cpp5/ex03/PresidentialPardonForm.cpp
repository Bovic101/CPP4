/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:52:34 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 17:21:28 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon", 25, 5), _target("Default")
{
}

// Parameterized Constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon", 25, 5), _target(target)
{
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cp)
	: AForm(cp), _target(cp._target)
{
}

// Copy Assignment Operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& cp) {
    if (this != &cp) {
        _target = cp._target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Execute the form
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!getFormSigned())  // Ensure the form is signed
    {
        throw AForm::FormUnableToSignException();
    }
    if (executor.getBgrade() > getExecGrade())
    {
        throw AForm::GradeTooLowException();
    }
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
