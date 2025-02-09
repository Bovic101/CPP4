/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBureaucrat.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:34:30 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/09 15:56:58 by victor-linu      ###   ########.fr       */
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
    BUREAUCRAT& operator=(const BUREAUCRAT& cp); //Copy assignment operator
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
        virtual const char* what() const throw(); //overide
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char* what() const throw(); //overide
    };
};
//Overload Output operator


std::ostream& operator << (std::ostream& output, const BUREAUCRAT& b);

#endif