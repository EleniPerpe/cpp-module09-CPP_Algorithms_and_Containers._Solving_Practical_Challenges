/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:47:43 by eleni             #+#    #+#             */
/*   Updated: 2025/01/29 16:07:58 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
    private:
        std::stack<int> _stack;
        
    public:
        RPN();
        RPN(const RPN& copy);
        RPN(char* calc);
        RPN& operator=(const RPN& copy);
        ~RPN();

        class InvalidInputException : public std::exception
        {
            const char* what() const throw();
        };

        class ZeroDivisionException : public std::exception
        {
            const char* what() const throw();            
        };
};