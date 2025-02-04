/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:14:50 by eleni             #+#    #+#             */
/*   Updated: 2025/02/04 10:36:40 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Usage : ./PmergeMe <integers input>" << std::endl;
        return 1;
    }

    if (argc == 2)
    {
        std::cout << "Cannot sort only one element" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe list(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}