/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:14:55 by eleni             #+#    #+#             */
/*   Updated: 2025/01/29 18:18:41 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& copy) : _stack(copy._stack) {}

RPN& RPN::operator=(const RPN& copy)
{
    if (this != &copy)
        this->_stack = copy._stack;
    return *this;
}

RPN::~RPN() {}

RPN::RPN(char* calc)
{
    std::istringstream ss(calc);
    std::string input;

    try
    {
        while (ss >> input)
        {
            if (std::isdigit(input[0]) && input.size() == 1)
                this->_stack.push(std::stoi(input));
            else if (input.find_first_not_of("+/*-") == std::string::npos && input.size() == 1)
            {
                // in case that with wrong amount of operators, needs to throw exceptions !!
                
                if (_stack.size() < 2)
                {
                    std::cout << "1" << std::endl;                
                    throw InvalidInputException();
                }
                int b = _stack.top();
                _stack.pop();
                int a = _stack.top();
                _stack.pop();

                switch(input[0])
                {
                    case '+':
                        _stack.push(a + b);
                        break;
                    case '-':
                        _stack.push(a - b);
                        break;
                    case '*':
                        _stack.push(a * b);
                        break;
                    case '/':
                        if (b == 0)
                            throw ZeroDivisionException();
                        _stack.push(a / b);
                        break;
                }
            }
            else
                throw InvalidInputException();

        }
        std::cout << this->_stack.top() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
};

const char* RPN::InvalidInputException::what() const throw()
{
    return ("Exception : Invalid Input");    
}

const char* RPN::ZeroDivisionException::what() const throw()
{
    return ("Exception : Cannot divide with zero");    
}