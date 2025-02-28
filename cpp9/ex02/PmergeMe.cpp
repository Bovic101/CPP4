/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:37:34 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/28 13:21:21 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() = default;
PmergeMe::PmergeMe(const PmergeMe &cp) = default;
PmergeMe& PmergeMe::operator=(const PmergeMe &cp) = default;
PmergeMe::~PmergeMe() = default;

/*Function to parse input and store in the 2 containers*/
void PmergeMe:: InputProcessor(char **arg)
{
    int i = 0;
    while (arg[i] != NULL)
    {
        std::istringstream iss(arg[i]); //validate num
        int n;
        if (!(iss >> n) || n < 0)
        {
            std::cerr << "Error: Invalid input, Recheck -> " << n[i] << std::endl;
            exit(1);
        }
        container1.push_back(n);
        container2.push_back(n);
        i++;
    }
}

// Merge-Insertion Sort for Vector
void PmergeMe::mergeInsertSortContainer1()
{
    std::vector<int> tmp;
    std::vector<int>::iterator it;
    
    while (!container1.empty())
    {
        int min = container1[0]; // This takes 1st element is the smallest
        int index= 0;
        int i = 1;
        
        while (i < container1.size())
        {
            if (container1[i] < min)
            {
                min = container1[i];
                index = i;
            }
            i++;
        }

        tmp.push_back(min);
        container1.erase(container1.begin() + index); // This remove the smallest element
    }

    container1 = tmp; // This sssign sorted data back to vector container
}

/*Merge-Insertion Sort for Deque*/
void PmergeMe::mergeInsertSortContainer2()
{
    std::deque<int> tmp;
    std::deque<int>::iterator it;

    while (!container2.empty())
    {
        int min = container2[0]; // This take 1st element is the smallest
        int index = 0;
        int i = 1;
        
        while (i < container2.size()) // Find the smallest element
        {
            if (container2[2] < min)
            {
                min = container2[i];
                index = i;
            }
            i++;
        }

        tmp.push_back(min);
        container2.erase(container2.begin() + index);
    }

    container2 = tmp; // This assign sorted data back to deq container
}

/*This Function the measure sorting time*/
void PmergeMe::sortAndMeasureTime(char **arg)
{
    InputProcessor(arg);

    clock_t startT1 = clock();
    mergeInsertSortContainer1();
    clock_t endT1 = clock();
    double T1 = (double)(endT1 - startT1) / CLOCKS_PER_SEC * 1000000; // This Convert to microseconds

    clock_t startT2 = clock();
    mergeInsertSortContainer2();
    clock_t endT2 = clock();
    double T2 = (double)(endT2 - startT2) / CLOCKS_PER_SEC * 1000000;

    printOutput(T1, T2);
}

/*Function to print the output result*/
void PmergeMe::printOutput(double T1, double T2)
{
    std::cout << "Before: ";
    int i = 0;
    while (i < container1.size()) // Print original sequence
    {
        std::cout << container1[i] << " ";
        i++;
    }
    std::cout << std::endl;

    std::cout << "After: ";
    i = 0;
    while (i < container1.size()) // This print sorted sequence
    {
        std::cout << container1[i] << " ";
        i++;
    }
    std::cout << std::endl;

    std::cout << "Time to process with std::vector: " << T1 << " us" << std::endl;
    std::cout << "Time to process with std::deque: " << T2 << " us" << std::endl;
}
