/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBureaucrat.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:33:37 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/09 15:59:53 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassBureaucrat.hpp"

//Default Constructor
BUREAUCRAT::BUREAUCRAT() : _bname("Default"), _bgrade(150) {}
//Parameterised constructor
BUREAUCRAT::BUREAUCRAT(const std::string& bname ,int bgrade) :_bname(bname), _bgrade(bgrade)
{
    if (bgrade < 1)
    {
        throw GradeTooHighException();
    }
    if (bgrade > 150)
    {
        throw GradeTooLowException();
    }
}
//copy constructor instance
BUREAUCRAT::BUREAUCRAT(const BUREAUCRAT& cp) :_bname(cp._bname),_bgrade(cp._bgrade){}
//Copy assignment operator
BUREAUCRAT& BUREAUCRAT::operator=(const BUREAUCRAT& cp)
{
    if (this != &cp)
    {
        this->_bgrade =cp._bgrade;
    }
    return *this;
}
//Destructor
BUREAUCRAT::~BUREAUCRAT() {}

//Getter Function
std::string BUREAUCRAT::getBname() const
{
    return(_bname);
}
int BUREAUCRAT::getBgrade() const
{
    return(_bgrade);
}
/*grade increment function,which reduce the grade num to make it the high  grade*/
void BUREAUCRAT::increaseGrade()
{
    if (_bgrade <= 1)
    {
        throw GradeTooHighException();
    }
    _bgrade--;
}

/*grade decrement function,which increase the grade num to make it the lo2 grade*/
void BUREAUCRAT::increaseGrade()
{
    if (_bgrade >= 150)
    {
        throw GradeTooLowException();
    }
    _bgrade++;
}
//Exception handling
const char* BUREAUCRAT::GradeTooHighException::what() const throw()
{
    return("Exception::The Grade is too high");
}
const char* BUREAUCRAT::GradeTooLowException::what() const throw()
{
    return("Exception::The Grade is too low");
}

//Overload output Operator
std::ostream& operator << (std::ostream& output, const BUREAUCRAT& b)
{
    output << b.getBname() << "and the grade" << b.getBgrade();
    return(output);
}