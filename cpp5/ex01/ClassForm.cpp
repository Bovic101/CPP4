/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassForm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:40:44 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 09:46:05 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassForm.hpp"

//Default Constructor
Form::Form()
	: _signee("Default"), _FormSigned(false), _signGrade(150), _execGrade(150)
{
}
//Parameterised Constructor
Form::Form(const std::string &signee, int signGrade, int execGrade)
	: _signee(signee), _FormSigned(false), _signGrade(signGrade),
		_execGrade(execGrade)
{
    if (signGrade < 1 ||  execGrade < 1)
    {
        throw GradeTooHighException();
    }
    if (signGrade > 150 || execGrade > 150 )
    {
        throw GradeTooLowException();
    }  
}

//Copy constructor
Form::Form(const Form& cp) : _signee(cp._signee), _FormSigned(cp._FormSigned), _signGrade(cp._signGrade), _execGrade(cp._execGrade){}
//Copy assignment opearator