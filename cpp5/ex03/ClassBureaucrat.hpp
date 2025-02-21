/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBureaucrat.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:34:30 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/21 08:11:47 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_BUREAUCRAT_HPP
#define CLASS_BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AClassForm.hpp"

class AForm; // Forward declaration

class Bureaucrat {
private:
    const std::string _bname;
    int _bgrade;

public:
    // Constructors and Destructor
    Bureaucrat();
    Bureaucrat(const std::string& bname, int bgrade);
    Bureaucrat(const Bureaucrat& cp);
    Bureaucrat& operator=(const Bureaucrat& cp);
    ~Bureaucrat();

    // Getters
    const std::string& getBname() const;
    int getBgrade() const;

    // Methods
    void increaseGrade();
    void decreaseGrade();
    void signForm(AForm& form);
    void executeForm(AForm const& form) const;

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

// Overloaded Output Operator
std::ostream& operator<<(std::ostream& output, const Bureaucrat& b);

#endif // CLASS_BUREAUCRAT_HPP

