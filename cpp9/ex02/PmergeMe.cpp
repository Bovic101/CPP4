/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:37:34 by victor-linu       #+#    #+#             */
/*   Updated: 2025/03/01 19:17:59 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &cp)
{
    *this = cp;
}
PmergeMe& PmergeMe::operator=(const PmergeMe &cp)   // Copy assignment operator
{
    if (this != &cp)
    {
        container1 = cp.container1;
        container2 = cp.container2;
        unsortedContainer = cp.unsortedContainer;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}


/* Function to parse input and store in the 2 containers */
void PmergeMe::InputProcessor(char **arg)
{
    int i = 0;
    while (arg[i] != NULL)
    {
        std::string str(arg[i]);
        if (str.empty())
        {
            std::cerr << RED << "Error: Empty input." << RESET << std::endl;
            exit(1);
        }

        char *endPtr;
        long num = std::strtol(str.c_str(), &endPtr, 10);

        
        if (*endPtr != '\0' || num < 0 || num > INT_MAX)  // Check if the entire string was converted to a number
        {
            std::cerr << RED << "Error: Invalid input '" << str << "'." << RESET << std::endl;
            exit(1);
        }

        container1.push_back(static_cast<int>(num));
        container2.push_back(static_cast<int>(num));
        unsortedContainer.push_back(static_cast<int>(num)); // This store the unsorted data
        i++;
    }

    if (container1.empty())
    {
        std::cerr << RED << "Error: No valid input provided." << RESET << std::endl;
        exit(1);
    }
}

/* The function Merge-Insertion Sort for Vector */
void PmergeMe::mergeInsertSortVector(std::vector<int>& vec)
{
    if (vec.size() <= 1) return;

    size_t i = 0;
    while (i < vec.size() - 1) // This will sort pairs of element
    {
        if (vec[i] > vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
        i += 2;
    }
    std::vector<int> largerElements; //Recursively sort the larger elements
    i = 1;
    while (i < vec.size())
    {
        largerElements.push_back(vec[i]);
        i += 2;
    }

    mergeInsertSortVector(largerElements);

    i = 0;
    while (i < vec.size())  //This insert the smaller elements int2 sorted larger
    {
        int key = vec[i];
        auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), key);
        largerElements.insert(pos, key);
        i += 2;
    }

    vec = largerElements;
}

/* The function Merge-Insertion Sort for deque */
void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq)
{
    if (deq.size() <= 1) return;

    size_t i = 0;
    while (i < deq.size() - 1)
    {
        if (deq[i] > deq[i + 1])
            std::swap(deq[i], deq[i + 1]);
        i += 2;
    }

    std::deque<int> largerElements;
    i = 1;
    while (i < deq.size())
    {
        largerElements.push_back(deq[i]);
        i += 2;
    }

    mergeInsertSortDeque(largerElements);

    i = 0;
    while (i < deq.size())
    {
        int key = deq[i];
        auto pos = std::lower_bound(largerElements.begin(), largerElements.end(), key);
        largerElements.insert(pos, key);
        i += 2;
    }

    deq = largerElements;
}

/*This function sort& easure time*/
void PmergeMe::sortAndMeasureTime(char **arg)
{
    InputProcessor(arg);

    size_t size = container1.size(); // Store the size of the containers

    // This measure time for vector
    auto startT1 = std::chrono::high_resolution_clock::now();
    mergeInsertSortVector(container1);
    auto endT1 = std::chrono::high_resolution_clock::now();
    double T1 = std::chrono::duration_cast<std::chrono::microseconds>(endT1 - startT1).count();

    // This measure time for deque
    auto startT2 = std::chrono::high_resolution_clock::now();
    mergeInsertSortDeque(container2);
    auto endT2 = std::chrono::high_resolution_clock::now();
    double T2 = std::chrono::duration_cast<std::chrono::microseconds>(endT2 - startT2).count();

    printOutput(size, T1, T2);
}

/*Output printing function*/
void PmergeMe::printOutput(size_t size, double T1, double T2)
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout << RED << "Before: " << RESET;
    size_t i = 0;
    while (i < size)
    {
        std::cout << unsortedContainer[i] << " ";
        i++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "After: " << RESET;
    i = 0;
    while (i < size)
    {
        std::cout << container1[i] << " ";
        i++;
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::vector: " << T1 << " us" << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::deque: " << T2 << " us" << std::endl;
}

