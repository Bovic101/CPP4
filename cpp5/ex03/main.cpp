/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:06:32 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/21 01:20:54 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
    Intern intern;
    
    // Creating valid forms
    AForm* shrubbery = intern.makeForm("shrubbery creation", "Victor");
    AForm* robotomy = intern.makeForm("robotomy request", "RobotX");
    AForm* pardon = intern.makeForm("presidential pardon", "Zaphod");

    // Attempt to create an invalid form
    AForm* unknown = intern.makeForm("unknown form", "N/A");

    // Cleanup allocated memory (delete NULL is safe)
    delete shrubbery;
    delete robotomy;
    delete pardon;
    delete unknown;

    return 0;
}

