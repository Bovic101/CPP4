/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor-linux <victor-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:17:28 by victor-linu       #+#    #+#             */
/*   Updated: 2025/02/26 15:29:07 by victor-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
/*
int	main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}
    */
   
    /*Testing with the std:.list*/
    int main(void)
    {
        std::list<int> mList;
        mList.push_back(5);
        mList.push_back(17);
        std::cout << mList.back() <<std::endl; //it output the last element on stack
        mList.pop_back();
        std::cout << mList.size() << std::endl;
        mList.push_back(3);
        mList.push_back(5);
        mList.push_back(737);
        mList.push_back(0);
        std::list<int>::iterator it = mList.begin();
        std::list<int>::iterator ite = mList.end();
        
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        return(0);
    }