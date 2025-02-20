/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassForm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:41:08 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 09:22:38 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSFORM_HPP
#define CLASSFORM_HPP

#include <iostream>
#include <stdexcept>
#include "ClassBureaucrat.hpp"

class BUREAUCRAT;

class Form {
    private:
    const std::string _signee;
    bool _FormSigned;
    const int _signGrade;
    const int _execGrade;
    
    public:
    Form(); //Default constructor
    Form(const std::string& signee, int signGrade, int execGrade); //Paramterised Constructor
    Form(const Form& cp); //Copy constructor
    Form& operator =(const Form& cp);
    ~Form();//Destructor

    //Getters
    std::string getSignee() const;
    bool getFormSigned () const;
    int getSignGrade () const;
    int getExecGrade() const;
    
    /*Function that check if the Bureaucrat have the required grade to sign the form*/
    void beSigned(const BUREAUCRAT& bsign);
    
     //Exception Class
     class GradeTooHighException : public std::exception
     {
        public: 
        virtual const char* what() const throw(); //overide
     };
     class GradeTooLowException : public std::exception
     {
        public: 
        virtual const char* what() const throw(); //overide
     };
    
};
//Overload Output operator


std::ostream& operator << (std::ostream& output, const Form& form);


#endif