/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:44:57 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 17:35:06 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AClassForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;

public:
    // Constructors and Destructor
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& cp);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& cp);
    ~ShrubberyCreationForm();

    // Methods
    void execute(Bureaucrat const &executor) const; // Removed 'override'
};

#endif
