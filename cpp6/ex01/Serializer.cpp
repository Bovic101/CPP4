/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:15:18 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/22 14:15:55 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructor
Serializer::Serializer()
{
}

// Copy Constructor
Serializer::Serializer(const Serializer &cp)
{
	(void)cp;
}

// Copy Assignment Operator
Serializer &Serializer::operator=(const Serializer &cp)
{
	(void)cp;
	return (*this);
}
// Destructor
Serializer::~Serializer()
{
}
/*Convert ptr to uintptr_t type of serialisation*/
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

// Convert uintptr_t back to a pointer
Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}