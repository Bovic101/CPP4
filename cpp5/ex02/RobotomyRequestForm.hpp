/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:46:43 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 17:34:08 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AClassForm.hpp"
#include <cstdlib>  // Needed for randomization
#include <ctime>    // Needed for seeding random numbers

class RobotomyRequestForm : public AForm {
private:
    std::string _target;

public:
    // Constructors and Destructor
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& cp);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& cp);
    ~RobotomyRequestForm();

    // Methods
    void execute(Bureaucrat const &executor) const; // Removed 'override'
};

#endif
