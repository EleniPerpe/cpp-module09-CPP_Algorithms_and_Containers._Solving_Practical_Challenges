/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:49:20 by eleni             #+#    #+#             */
/*   Updated: 2025/01/29 15:11:35 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage : ./RPN <inverted Polish mathematical expression>" << std::endl;
        return 1;
    }
    
    std::string input = argv[1];
    if (input.find_first_not_of("0123456789 +-*/") != std::string::npos)
    {
        std::cout << "The input accepts only digits and the operators : + - * /" << std::endl;
        return 1;
    }
    
    RPN expression(argv[1]);
}