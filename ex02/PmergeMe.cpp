/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:14:36 by eleni             #+#    #+#             */
/*   Updated: 2025/02/03 11:43:45 by eleni            ###   ########.fr       */
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
}

const char* PmergeMe::NoIntegerException::what() const throw()
{
    return "Exception: No integer input";
}

template <typename T>
void PmergeMe::PmergeprintList(const T& container)
{
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
