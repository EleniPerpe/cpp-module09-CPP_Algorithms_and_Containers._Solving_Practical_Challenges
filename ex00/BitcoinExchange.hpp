/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:31:52 by eleni             #+#    #+#             */
/*   Updated: 2025/01/28 16:23:28 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::multimap<std::string, float> _map;

    void MapingCSV();
        
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
        
};

