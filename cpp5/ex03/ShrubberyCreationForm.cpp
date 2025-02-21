/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:43:57 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 17:24:35 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), _target("Default")
{
}

// Parameterized Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", 145, 137), _target(target)
{
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cp)
	: AForm(cp), _target(cp._target)
{
}

// Copy Assignment Operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cp) {
    if (this != &cp) {
        _target = cp._target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Execute the form
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getFormSigned()) 
    {
        throw AForm::FormUnableToSignException();
    }
    if (executor.getBgrade() > getExecGrade())
    {
        throw AForm::GradeTooLowException();
    }

    // Create the shrubbery file
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());

    if (!outfile) {
        std::cerr << "Error: Could not create " << filename << std::endl;
        return;
    }

    // ASCII art of a tree
    outfile << "       _-_\n";
    outfile << "    /~~   ~~\\\n";
    outfile << " /~~         ~~\\\n";
    outfile << "{               }\n";
    outfile << " \\  _-     -_  /\n";
    outfile << "   ~  \\ //  ~\n";
    outfile << "_- -   | | _- _\n";
    outfile << "  _ -  | |   -_\n";
    outfile << "      // \\\n";

    outfile.close();
    
    std::cout << "Shrubbery has been successfully created in " << filename << "." << std::endl;
}
