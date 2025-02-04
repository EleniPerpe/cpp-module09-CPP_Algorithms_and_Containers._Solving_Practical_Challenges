/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:14:36 by eleni             #+#    #+#             */
/*   Updated: 2025/02/04 16:32:54 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::list<int> PmergeMe::mergeList(std::list<int> left, std::list<int> right) 
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
    if (list.size() <= 1)
        return;

    std::list<int> left, right;
    auto mid = list.begin();
    std::advance(mid, list.size() / 2);

    left.splice(left.begin(), list, list.begin(), mid);
    right.splice(right.begin(), list);

    PmergeSortList(left);
    PmergeSortList(right);
    
    list = mergeList(left, right);
}

std::vector<int> PmergeMe::mergeVector(std::vector<int> left, std::vector<int> right)
{
    std::vector<int> result;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            result.push_back(left[i]);
            i++;
        }
        else
        {
            result.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size())
    {
        result.push_back(left[i]);
        i++;
    }

    while (j < right.size())
    {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

void PmergeMe::PmergeSortVector(std::vector<int>& vector)
{
   if (vector.size() <= 1)
    return;

    size_t mid = vector.size() / 2;
    std::vector<int> left(vector.begin(), vector.begin() + mid);
    std::vector<int> right(vector.begin() + mid, vector.end());

    PmergeSortVector(left);
    PmergeSortVector(right);

    vector = mergeVector(left, right);
}

PmergeMe::PmergeMe(int argc, char** argv)
{
    std::list<int> mergeList;
    std::vector<int> mergeVector;

    // auto startParsing = std::chrono::high_resolution_clock::now();
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
    // auto endParsing = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double, std::micro> parsingTime = endParsing - startParsing;
    std::cout << "Before: ";
    PmergePrintList(mergeVector);
    

    auto startList = std::chrono::high_resolution_clock::now();
    PmergeSortList(mergeList);
    auto endList = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> timeList = endList - startList;
    
    std::cout << "After:  ";
    PmergePrintList(mergeList);
    
    auto startVector = std::chrono::high_resolution_clock::now();
    PmergeSortVector(mergeVector);
    auto endVector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> timeVector = endVector - startVector;
    
    // std::cout << "After:  ";
    // PmergePrintList(mergeVector);
    
    // std::cout << "Time to process a range of " << argc - 1 << " elements with std::list :   " << parsingTime.count() + timeList.count() << " us" << std::endl;
    // std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << parsingTime.count() + timeVector.count() << " us" << std::endl; 


    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list :   " << timeList.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << timeVector.count() << " us" << std::endl;
}

template <typename T>
void PmergeMe::PmergePrintList(const T& container)
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
