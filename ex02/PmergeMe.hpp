/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:14:39 by eleni             #+#    #+#             */
/*   Updated: 2025/02/04 10:18:24 by eleni            ###   ########.fr       */
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
        std::vector<int> PmergeSortVector(std::vector<int>& array);
        template <typename T>
        void PmergeprintList(const T& container);

        class NoIntegerException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};