/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:44:57 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 14:44:27 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AClassForm.hpp"
#include <fstream>

class  ShrubberyCreationForm : public AForm{
    private:
    std::string _target;
    public:
    ShrubberyCreationForm(); //default consstructor
    ShrubberyCreationForm(const std::string& targetfile); //parameterised constructor
    ShrubberyCreationForm(const ShrubberyCreationForm& cp);//copy constructor
    ShrubberyCreationForm& operator = (const ShrubberyCreationForm& cp);
    ~ShrubberyCreationForm();
    
    void execute(BUREAUCRAT const & executor) const;
};


#endif