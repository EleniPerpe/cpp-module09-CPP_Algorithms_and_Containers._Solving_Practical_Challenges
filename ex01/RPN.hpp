/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleni <eleni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:47:43 by eleni             #+#    #+#             */
/*   Updated: 2025/01/29 15:13:44 by eleni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<float> _stack;
        
    public:
        RPN();
        RPN(const RPN& copy);
        RPN(char* calc);
        RPN& operator=(const RPN& copy);
        ~RPN();
};