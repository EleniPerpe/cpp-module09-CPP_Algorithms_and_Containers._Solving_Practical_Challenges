/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:14:36 by eleni             #+#    #+#             */
/*   Updated: 2025/02/04 10:25:51 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::list<int> merge(std::list<int> left, std::list<int> right) 
{
    std::list<int> result;
    
    while (!left.empty() && !right.empty()) 
    {
        if (left.front() <= right.front()) 
        {
            result.push_back(left.front());
            left.pop_front();
        } else 
        {
            result.push_back(right.front());
            right.pop_front();
        }
    }

    result.splice(result.end(), left);
    result.splice(result.end(), right);
    
    return result;
}

void PmergeMe::PmergeSortList(std::list<int>& list)
{
    // std::cout << "Hello" << std::endl;

    if (list.size() <= 1)
        return;

    std::list<int> left, right;
    auto mid = list.begin();
    std::advance(mid, list.size() / 2);

    left.splice(left.begin(), list, list.begin(), mid);
    right.splice(right.begin(), list);

    PmergeSortList(left);
    PmergeSortList(right);
    list = merge(left, right);
}

PmergeMe::PmergeMe(int argc, char** argv)
{
    std::list<int> mergeList;
    std::vector<int> mergeVector;

    for (int i = 1; i < argc; i++)
    {
        try
        {
            for (size_t j = 0; j < std::strlen(argv[i]); j++)
            {
                if (!std::isdigit(argv[i][j]))
                    throw NoIntegerException();
            }
            int num = std::stoi(argv[i]);
            mergeList.push_back(num);
            mergeVector.push_back(num);
        }
        catch (const std::exception& e)
        {
            throw NoIntegerException();
        }        
    }
    clock_t startList = clock();
    PmergeSortList(mergeList);
    clock_t endList = clock();
    double timeList = (double(endList - startList) / CLOCKS_PER_SEC) * 1e6;
    std::cout << "Time to process a range of " << argc - 1 << "elements with std::list : " << timeList << " us" << std::endl;
    PmergeprintList(mergeList);
    // PmergeprintList(mergeVector);
}

template <typename T>
void PmergeMe::PmergeprintList(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

const char* PmergeMe::NoIntegerException::what() const throw()
{
    return "Exception: No integer (int) input";
}
