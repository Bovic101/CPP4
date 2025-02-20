/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:46:43 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 14:12:52 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AClassForm.hpp"
#include <cstdlib> //needed for randomisatiom
#include <iostream>
#include <ctime>

class RobotomyRequestForm : public AForm{
    private:
    std::string _target;
    public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& targetfile);
    RobotomyRequestForm(const  RobotomyRequestForm& cp);
    RobotomyRequestForm& operator = (const  RobotomyRequestForm& cp);
    ~ RobotomyRequestForm();

    void execute(BUREAUCRAT const & executor) const;
};

#endif