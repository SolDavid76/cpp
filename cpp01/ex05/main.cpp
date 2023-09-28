/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:14:40 by djanusz           #+#    #+#             */
/*   Updated: 2023/09/28 15:14:40 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl bob;

	bob.complain("kekw");
	bob.complain("warning");
	bob.complain("debug");
	bob.complain("error");
	bob.complain("info");
}