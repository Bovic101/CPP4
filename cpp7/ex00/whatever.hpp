/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 08:23:47 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/23 08:53:08 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

/*Template for swap function*/

template <typename U>
void	swap(U &a, U &b)
{
	U	tmp;

	tmp = a;
	a = b;
	b = tmp;
}
/*Template function that compares the two values and returns the smallest
one. If the two of them are equal, then it returns the second one*/
template <typename U>
U min(const U &a, const U &b)
{
    if (a <  b)
    {
        return(a);
    }
    return(b);
}


/*Template function that compares the two values and returns the latrgest
one. If the two of them are equal, then it returns the second one.*/
template <typename U>
U min(const U &a, const U &b)
{
    if (a > b)
    {
        return(a);
    }
    return(b);
}

#endif