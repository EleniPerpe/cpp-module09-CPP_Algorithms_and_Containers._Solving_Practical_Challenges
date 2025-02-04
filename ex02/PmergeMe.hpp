/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:14:39 by eleni             #+#    #+#             */
/*   Updated: 2025/02/04 15:35:41 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <stdexcept> 
#include <cstring> 
#include <cctype> 
#include <ctime>

class PmergeMe
{
    public:
        PmergeMe(int argc, char** argv);
        void PmergeSortList(std::list<int>& list);
        void PmergeSortVector(std::vector<int>& vector);

        class NoIntegerException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
    private:
        template <typename T>
        void PmergePrintList(const T& container);
        std::list<int> mergeList(std::list<int> left, std::list<int> right);
        std::vector<int> mergeVector(std::vector<int> left, std::vector<int> right);
};