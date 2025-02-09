/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBureaucrat.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:34:30 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/09 14:28:55 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClassBUREAUCRAT_HPP
#define ClassBUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class BUREAUCRAT{
    private:
    const std::string _bname;
    int _bgrade;
    
    public:
    BUREAUCRAT(); //Default Constructor
    BUREAUCRAT(const std::string& bname ,int bgrade); //Parameterised constructor
    BUREAUCRAT(const BUREAUCRAT& cp); //Copy constructor#
    BUREAUCRAT& operator=(const BUREAUCRAT& cp); //Copy assignment operatoe
    ~BUREAUCRAT();
    
    //Getters to get retrieve the valus of a the privat
    std::string getBname() const;
    int getBgrade() const;

    //Function to increase and decrease grade
    void increaseGrade();
    void decreaseGrade();

    //Exception Class
    class GradeTooHighException : public std::exception
    {
        virtual const char* what() const throw(); //ooveride
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char* what() const throw(); //ooveride
    };
};
//Overload Output operator

std::ostream& operator << (std::ostream& a, const BUREAUCRAT& b);

#endif