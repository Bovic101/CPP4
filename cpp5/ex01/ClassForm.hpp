/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassForm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:41:08 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 11:13:16 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSFORM_HPP
#define CLASSFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "ClassBureaucrat.hpp"

class BUREAUCRAT;  // Forward declaration

class Form {
private:
    const std::string _signee;
    bool _FormSigned;
    const int _signGrade;
    const int _execGrade;

public:
    // Constructors and Destructor
    Form();  // Default constructor
    Form(const std::string& signee, int signGrade, int execGrade); // Parameterized constructor
    Form(const Form& cp); // Copy constructor
    Form& operator=(const Form& cp); // Copy assignment operator
    ~Form();

    // Getters
    std::string getSignee() const;
    bool getFormSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    
    // Function to sign the form
    void beSigned(const BUREAUCRAT& bsign);
    
    // Exception Classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Overload of the output operator for Form objects
std::ostream& operator<<(std::ostream& output, const Form& form);

#endif
