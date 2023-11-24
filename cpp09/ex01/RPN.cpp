/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:21:30 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/21 15:49:43 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int top_pop(std::stack<int>& expression)
{
	int res = expression.top();
	expression.pop();
	return (res);
}

int calc(std::stack<int>& expression, char op)
{
	if (expression.size() < 2)
		throw ft_exception("Error");

	int right = top_pop(expression);
	int left = top_pop(expression);
	if (op == '+')
		return (left + right);
	if (op == '-')
		return (left - right);
	if (op == '*')
		return (left * right);
	if (op == '/')
	{
		if (!right)
			throw ft_exception("Error");
		else
			return (left / right);
	}
	return (0);
}

int rpn(std::string str)
{
	std::stack<int> expression;

	for (unsigned long int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			expression.push(str[i] - '0');
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			expression.push(calc(expression, str[i]));
		else if (isspace(str[i]))
			continue;
		else
			throw ft_exception("Error");
	}
	if (expression.size() != 1)
		throw ft_exception("Error");
	return (expression.top());
}
