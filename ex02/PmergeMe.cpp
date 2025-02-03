/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:14:36 by eleni             #+#    #+#             */
/*   Updated: 2025/02/03 16:26:32 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
    PmergeSortList(mergeList);
    PmergeprintList(mergeList);
    // PmergeprintList(mergeVector);
}

// Function to merge two sorted lists
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

    // Add remaining elements
    result.splice(result.end(), left);
    result.splice(result.end(), right);
    
    return result;
}

// Merge Sort function for std::list<int>
std::list<int> PmergeSortList(std::list<int> list) 
{
    std::cout << "Hello" << std::endl;

    if (list.size() <= 1)
        return list;
    // Split the list into two halves
    std::list<int> left, right;
    auto mid = list.begin();
    std::advance(mid, list.size() / 2);  // Move mid to the middle

    left.splice(left.begin(), list, list.begin(), mid);
    right.splice(right.begin(), list);

    // Recursively sort both halves and merge them
    return merge(PmergeSortList(left), PmergeSortList(right));
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
