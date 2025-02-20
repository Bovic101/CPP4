/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:06:32 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/20 11:13:39 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassBureaucrat.hpp"

int main()
{
    BUREAUCRAT winner("Adeola", 75);//Adeola with grade 75
    Form examform("Exam form", 60, 40 );//form is signe with grade 60 and exec at 20
    std::cout << winner <<std::endl;
    std::cout << examform <<std::endl; //print exam form details
    winner.signForm(examform);//try to sign form for adeola
    std::cout << examform <<std::endl; //print form to see if the form is signed or not
    return(0);
}