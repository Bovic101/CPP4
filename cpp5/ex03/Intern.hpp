/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Intern.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:12:55 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 18:23:19 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AClassForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern{
    public:
    Intern(); //Default constructor
    Intern(const Intern& cp); //Parameterised constructor
    Intern& operator=(const Intern& cp);
    ~Intern();

    //Method
    AForm* makeForm(std::string formName, std::string formtarget);
};

#endif