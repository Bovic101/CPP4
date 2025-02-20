/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AClassForm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:41:08 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 11:13:16 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACLASSFORM_HPP
#define ACLASSFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "ClassBureaucrat.hpp"

class BUREAUCRAT;  // Forward declaration

class AForm {
private:
    const std::string _signee;
    bool _FormSigned;
    const int _signGrade;
    const int _execGrade;

public:
    // Constructors and Destructor
    AForm();  // Default constructor
    AForm(const std::string& signee, int signGrade, int execGrade); // Parameterized constructor
    AForm(const Form& cp); // Copy constructor
    AForm& operator=(const AForm& cp); // Copy assignment operator
    virtual ~AForm();

    // Getters
    std::string getSignee() const;
    bool getFormSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    
    // Function to sign the form
    void beSigned(const BUREAUCRAT& bsign);
    virtual void execute(BUREAUCRAT const & executor) const = 0; //virtual
    
    // Exception Classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class FormUnableToSignException : public std::exception
    {
        virtual const char* what() const throw();
    };
};

// Overload of the output operator for Form objects
std::ostream& operator<<(std::ostream& output, const Form& form);

#endif
