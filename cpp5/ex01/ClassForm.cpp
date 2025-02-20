/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassForm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:40:44 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 11:12:56 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassForm.hpp"

// Default Constructor
Form::Form()
    : _signee("Default"), _FormSigned(false), _signGrade(150), _execGrade(150)
{
}

// Parameterized Constructor
Form::Form(const std::string& signee, int signGrade, int execGrade)
    : _signee(signee), _FormSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
    {
        throw GradeTooHighException();
    }
    if (signGrade > 150 || execGrade > 150)
    {
        throw GradeTooLowException();
    }
}

// Copy Constructor
Form::Form(const Form& cp)
    : _signee(cp._signee), _FormSigned(cp._FormSigned),
      _signGrade(cp._signGrade), _execGrade(cp._execGrade)
{
}

// Copy Assignment Operator
Form& Form::operator=(const Form& cp)
{
    if (this != &cp)
    {
        // Note: _signee, _signGrade, and _execGrade are const and cannot be changed
        _FormSigned = cp._FormSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getters
std::string Form::getSignee() const {
    return _signee;
}

bool Form::getFormSigned() const {
    return _FormSigned;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecGrade() const {
    return _execGrade;
}

// Function to sign the form
void Form::beSigned(const BUREAUCRAT& bsign)
{
    if (bsign.getBgrade() > _signGrade)
    {
        throw GradeTooLowException();
    }
    _FormSigned = true;
}

// Exception Definitions
const char* Form::GradeTooHighException::what() const throw() {
    return "Exception: Form grade too high, recheck";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Exception: Form grade too low, recheck";
}

// Overload output operator for Form objects
std::ostream& operator<<(std::ostream& output, const Form& form)
{
    output << "Form: " << form.getSignee() 
           << " | Signed: " << (form.getFormSigned() ? "Yes" : "No")
           << " | Sign Grade: " << form.getSignGrade()
           << " | Execute Grade: " << form.getExecGrade();
    return output;
}
