/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:44:21 by eleni             #+#    #+#             */
/*   Updated: 2025/01/28 17:54:40 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char** argv)
{
    // (void)argc;
    // (void)argv;
    if (argc != 2)
        return (std::cout << "Wrong usage: ./btc <input.txt>" << std::endl, 0);
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
        return (std::cout << "Unable to open the file" << std::endl, 0);
    if (inputFile.peek() == std::ifstream::traits_type::eof())
        return (std::cout << "The file is empty" << std::endl, 0);
    // if (inputFile.tellg() == 0)
    //     return (std::cout << "The file is empty" << std::endl, 0);
    BitcoinExchange exchange(argv[1]);
    inputFile.close();
}