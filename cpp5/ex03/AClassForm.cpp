/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AClassForm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:40:44 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 11:12:56 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AClassForm.hpp"

// Default Constructor
AForm::AForm() : _signee("Default"), _FormSigned(false), _signGrade(150), _execGrade(150) {}

// Parameterized Constructor
AForm::AForm(const std::string& signee, int signGrade, int execGrade)
    : _signee(signee), _FormSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1) {
        throw GradeTooHighException();
    }
    if (signGrade > 150 || execGrade > 150) {
        throw GradeTooLowException();
    }
}

// Copy Constructor
AForm::AForm(const AForm& cp)
    : _signee(cp._signee), _FormSigned(cp._FormSigned), _signGrade(cp._signGrade), _execGrade(cp._execGrade) {}

// Copy Assignment Operator
AForm& AForm::operator=(const AForm& cp) {
    if (this != &cp) {
        _FormSigned = cp._FormSigned;
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

// Getters
const std::string& AForm::getSignee() const {
    return _signee;
}

bool AForm::getFormSigned() const {
    return _FormSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecGrade() const {
    return _execGrade;
}

// Function to sign the form
void AForm::beSigned(const Bureaucrat& bsign) {
    if (bsign.getBgrade() > _signGrade) {
        throw GradeTooLowException();
    }
    _FormSigned = true;
}

// Exception Handling
const char* AForm::GradeTooHighException::what() const throw() {
    return "Exception: Form grade too high, recheck.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Exception: Form grade too low, recheck.";
}

const char* AForm::FormUnableToSignException::what() const throw() {
    return "Exception: Form not signed, recheck.";
}

// Overloaded Output Operator
std::ostream& operator<<(std::ostream& output, const AForm& form) {
    output << "Form: " << form.getSignee() 
           << " | Signed: " << (form.getFormSigned() ? "Yes" : "No")
           << " | Sign Grade: " << form.getSignGrade()
           << " | Execute Grade: " << form.getExecGrade();
    return output;
}
