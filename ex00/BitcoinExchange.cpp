/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:46:29 by eleni             #+#    #+#             */
/*   Updated: 2025/01/28 18:30:47 by eleni            ###   ########.fr       */
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

    // for (const auto& print : _map) 
    // {
    // std::cout << print.first << " : " << print.second << std::endl;
    // }

}
       
void BitcoinExchange::checkingArg(const char* arg)
{
    std::ifstream file(arg, std::ifstream::in);
    if (!file.is_open())
    {
        throw NoDataBaseFileException();
    }

    std::string nextLine;
    int i = 0;
    while (std::getline(file, nextLine))
    {
        if (i == 0)
        {
            if (nextLine == "date | value")
            {
                i++;
                continue;
            }
            else
            {
                std::cout << "Wrong first line format : <date | value>" << std::endl;
                continue;
            } 
        }

        if (nextLine.find('|') == std::string::npos)
        {
            std::cout << "Error: bad input => " << nextLine << std::endl;
            continue;
        }
        
        std::string date = nextLine.substr(0, nextLine.find(' '));
        std::tm tm = {};
        std::istringstream ss(date);
        ss >> std::get_time(&tm, "%Y-%m-%d");

        if (ss.fail())
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        if (tm.tm_year < 0 || tm.tm_year > 124 || tm.tm_mon < 0 || tm.tm_mon > 11 || 
            tm.tm_mday < 1 || tm.tm_mday > 31)
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        std::time_t t = std::mktime(&tm);
        if (t == -1)
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        std::string data = nextLine.substr(nextLine.find('|') + 1);
        double number = std::atof(data.c_str());
        if (number < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (number > std::numeric_limits<int>::max())
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        std::cout << date << " : " << number << std::endl;
    }


    if (i == 0)
        throw EmptyDataBaseException();
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
        checkingArg(arg);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


const char* BitcoinExchange::NoDataBaseFileException::what() const throw()
{
    return ("Exception : Error on opening the file");
} 

const char* BitcoinExchange::EmptyDataBaseException::what() const throw()
{
    return ("Exception : Empty file");
}

const char* BitcoinExchange::WrongFormatException::what() const throw()
{
    return ("Exception : Wrong format");
} 