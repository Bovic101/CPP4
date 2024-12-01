/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassBrain.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vodebunm <vodebunm@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 10:15:52 by vodebunm          #+#    #+#             */
/*   Updated: 2024/12/30 11:15:39 by vodebunm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSBRAIN_HPP
#define CLASSBRAIN_HPP

#include <iostream>

class Brain 
{
    public:
        std::string ideas[100];

        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& cp);
        ~Brain();
};

#endif
