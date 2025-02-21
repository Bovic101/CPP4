/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBureaucrat.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:33:37 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/21 08:12:08 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassBureaucrat.hpp"
#include "AClassForm.hpp"
#include <iostream>

// Default Constructor
Bureaucrat::Bureaucrat() : _bname("Default"), _bgrade(150) {}

// Parameterized Constructor
Bureaucrat::Bureaucrat(const std::string& bname, int bgrade)
    : _bname(bname), _bgrade(bgrade)
{
    if (bgrade < 1) {
        throw GradeTooHighException();
    }
    if (bgrade > 150) {
        throw GradeTooLowException();
    }
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat& cp)
    : _bname(cp._bname), _bgrade(cp._bgrade) {}

// Copy Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& cp) {
    if (this != &cp) {
        _bgrade = cp._bgrade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getter Functions
const std::string& Bureaucrat::getBname() const {
    return _bname;
}

int Bureaucrat::getBgrade() const {
    return _bgrade;
}

// Grade Modification
void Bureaucrat::increaseGrade() {
    if (_bgrade <= 1) {
        throw GradeTooHighException();
    }
    _bgrade--;
}

void Bureaucrat::decreaseGrade() {
    if (_bgrade >= 150) {
        throw GradeTooLowException();
    }
    _bgrade++;
}

// Function for signing forms
void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << _bname << " signed " << form.getSignee() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << _bname << " couldn't sign " << form.getSignee()
                  << " because: " << e.what() << std::endl;
    }
}

// Function for executing forms
void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << _bname << " executed " << form.getSignee() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << _bname << " couldn't execute " << form.getSignee()
                  << " because: " << e.what() << std::endl;
    }
}

// Exception Handling
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Exception: Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Exception: Grade is too low!";
}

// Overloaded Output Operator
std::ostream& operator<<(std::ostream& output, const Bureaucrat& b) {
    output << b.getBname() << " has a grade of " << b.getBgrade();
    return output;
}

