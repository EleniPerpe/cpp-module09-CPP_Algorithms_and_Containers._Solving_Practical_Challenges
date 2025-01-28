/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:31:52 by eleni             #+#    #+#             */
/*   Updated: 2025/01/28 18:50:22 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <ctime>
#include <limits>

class BitcoinExchange
{
    private:
        std::multimap<std::string, double> _map;

    void MapingCSV();
    void checkingArg(const char* arg);
    int validFormatCheck(std::string& data, std::string& date, double& number, const std::string& nextLine);
        
    public:
        BitcoinExchange();
        explicit BitcoinExchange(const char* arg);
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& copy);
        ~BitcoinExchange();

        class NoDataBaseFileException : public std::exception
        {
            const char* what() const throw();
        };

        class EmptyDataBaseException : public std::exception
        {
            const char* what() const throw();
        };

        class WrongFormatException : public std::exception
        {
            const char* what() const throw();
        };
        
};

