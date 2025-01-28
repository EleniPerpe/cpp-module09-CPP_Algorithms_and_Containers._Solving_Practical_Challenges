/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:46:29 by eleni             #+#    #+#             */
/*   Updated: 2025/01/28 16:30:56 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::MapingCSV()
{
    std::ifstream file("data.csv", std::ifstream::in);
    if (!file.is_open())
        throw NoDataBaseFileException();

    std::string nextLine;
    int i = 0;
    while (std::getline(file, nextLine))
    {
        if (i == 0 && nextLine == "date,exchange_rate")
            continue;
        i++;
        std::string date = nextLine.substr(0, nextLine.find(','));
        std::string data = nextLine.substr(nextLine.find(',') + 1);

        this->_map.insert(std::make_pair(date, std::atof(data.c_str())));
    }

    if (i == 0)
        throw EmptyDataBaseException();

    for (const auto& pair : _map) {
    std::cout << pair.first << " : " << pair.second << std::endl;
}

}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {(void)copy;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) 
{
    (void)copy;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char* arg) 
{
    (void)arg;
    try
    {
        MapingCSV();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


const char* BitcoinExchange::NoDataBaseFileException::what() const throw()
{
    return ("NoDataBaseFileException");
} 

const char* BitcoinExchange::EmptyDataBaseException::what() const throw()
{
    return ("EmptyDataBaseException");
} 