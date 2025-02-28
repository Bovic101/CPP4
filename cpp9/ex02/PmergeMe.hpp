/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:37:54 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/28 12:43:43 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <cstdlib>

class PmergeMe
{
private:
    std::vector<int> container1; // a Vector container
    std::deque<int> container2;  // a deque container

public:
    PmergeMe();
    PmergeMe(const PmergeMe &cp);
    PmergeMe& operator=(const PmergeMe &cp);
    ~PmergeMe();

    void sortAndMeasureTime(char **arg); //  This Sort and measure time
    void InputProcessor(char **arg);     // Parsing input values
    void mergeInsertSortVector();      // This Sort vector using Merge-Insertion
    void mergeInsertSortDeque();       // This Sort deque using Merge-Insertion

    void printOutput(double T1, double T2); 
};

#endif