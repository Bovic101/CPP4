/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:37:54 by victor-linu       #+#    #+#             */
/*   Updated: 2025/03/01 19:07:11 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <climits>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

class PmergeMe
{
private:
    std::vector<int> container1; // Vector container
    std::deque<int> container2;  // Deque container
    std::vector<int> unsortedContainer; // Store unsorted data

public:
    PmergeMe();
    PmergeMe(const PmergeMe &cp);
    PmergeMe& operator=(const PmergeMe &cp);
    ~PmergeMe();

    // Functions
    void sortAndMeasureTime(char **arg); // This Sort and measure time
    void InputProcessor(char **arg);     // Parse input
    void mergeInsertSortVector(std::vector<int>& vec);
    void mergeInsertSortDeque(std::deque<int>& deq);  // This will Sort deque using merge-insertion
    void printOutput(size_t size, double T1, double T2);
};

#endif