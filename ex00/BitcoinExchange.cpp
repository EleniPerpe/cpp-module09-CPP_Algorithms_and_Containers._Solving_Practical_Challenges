/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:46:29 by eleni             #+#    #+#             */
/*   Updated: 2025/01/28 19:39:12 by eleni            ###   ########.fr       */
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
       
int BitcoinExchange::validFormatCheck(std::string& data, std::string& date, double& number, const std::string& nextLine)
{
     if (nextLine.find('|') == std::string::npos)
        {
            std::cout << "Error: bad input => " << nextLine << std::endl;
            return 0;
        }
        
        date = nextLine.substr(0, nextLine.find(' '));
        std::tm tm = {};
        std::istringstream ss(date);
        ss >> std::get_time(&tm, "%Y-%m-%d");

        if (ss.fail())
            return (std::cout << "Error: bad input => " << nextLine << std::endl, 0);

        // if (tm.tm_year < 0 || tm.tm_year > 124 || tm.tm_mon < 0 || tm.tm_mon > 11 || 
        //     tm.tm_mday < 1 || tm.tm_mday > 31)
        //      return (std::cout << "Error: bad input => " << date << std::endl, 0);
        
        std::time_t t = std::mktime(&tm);
        if (t == -1)
            return (std::cout << "Error: bad input => " << nextLine << std::endl, 0);
        
        data = nextLine.substr(nextLine.find('|') + 1);
        number = std::atof(data.c_str());
        if (number < 0)
            return (std::cout << "Error: not a positive number." << std::endl, 0);
        if (number > std::numeric_limits<int>::max())
            return (std::cout << "Error: too large a number." << std::endl, 0);
        return 1;
}

void BitcoinExchange::searchMap(const std::string& date, double& number)
{
    for (std::map<std::string, double>::iterator it = this->_map.begin(); it != this->_map.end(); it++)
    {
        if (it->first == date)
            std::cout << date << " => " << number  << " = " << it->second * number << std::endl;
    }

}
       
void BitcoinExchange::checkingArg(const char* arg)
{
    std::ifstream file(arg, std::ifstream::in);
    if (!file.is_open())
        throw NoDataBaseFileException();

    std::string nextLine, data, date;
    int i = 0;
    double number;
    
    while (std::getline(file, nextLine))
    {
        if (i == 0)
        {
            if (nextLine != "date | value")
                throw WrongFormatException();
            i++;
            continue;
        }

        int flag = validFormatCheck(data, date, number, nextLine);
        if (flag == 1)
            searchMap(date, number);
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