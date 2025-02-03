/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:14:50 by eleni             #+#    #+#             */
/*   Updated: 2025/02/03 10:18:02 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Usage : ./PmergeMe <integers input>" << std::endl;
        return 1;
    }

    if (argc == 2)
    {
        std::cout << "Cannot sort only one number" << std::endl;
        return 1;
    }
}