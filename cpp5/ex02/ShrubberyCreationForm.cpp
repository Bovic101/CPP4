/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:43:57 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 14:43:30 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Default Constructor 
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("creating Shrubbery", 145, 137), _target("default") {}
// Parameterised Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &targetfile)
	: AForm("Creating Shrubbery", 145, 137), _target(targetfile)
{
}
//Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cp)
	: AForm(cp), _target(cp._target)
{
}
//Copy of Assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cp)
{
	if (this != &cp)
	{
		_target = cp._target;
	}
	return (*this);
}
//Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*execute() check if the form is not signed and the formalso check if Bureaucratic grade is low*/
void ShrubberyCreationForm::execute(BUREAUCRAT const &executor) const
{
	if (!getFormSigned())
	{
		throw AForm::FormUnableToSignException();
	}
	if (executor.getBgrade() > getExecGrade())
	{
		throw AForm::GradeTooLowException();
	}

	std::ofstream file((_target + "ShrubberyTree").c_str());
	if (!file)
	{
		return ;
	}
	file << R"(
        _-_
     /~~   ~~\
  /~~         ~~\
 {               }
  \  _-     -_  /
    ~  \\ //  ~
 _- -   | | _- _
   _ -  | |   -_
       // \
 )";
     file.close();
}