/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:14:39 by eleni             #+#    #+#             */
/*   Updated: 2025/02/03 10:25:30 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
    public:
        void mergeMe(int argc, char** argv);
        void mergeSortList(std::list<int>& array);
        void mergeSortVector(std::vector<int>& array);
        template <typename T>
        void printList(const T& container);
};