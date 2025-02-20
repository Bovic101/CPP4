/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:52:46 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 17:28:10 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AClassForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string _target;

public:
    // Constructors and Destructor
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& cp);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& cp);
    ~PresidentialPardonForm();

    // Methods
    void execute(Bureaucrat const &executor) const;
};

#endif

