/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:51:24 by djanusz           #+#    #+#             */
/*   Updated: 2023/11/27 12:30:24 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av) {
    if (ac < 2 || av[1][0] == '\0') {
        std::cout << "Usage: ./PmergeMe [args]" << std::endl;
        return 1;
    }
    try {
        PmergeMe sort;
        if (sort.parseInput(ac, av))
            std::cerr << "Error" << std::endl;
        else
            sort.time();
    } catch (std::exception& e) {
        std::cerr <<  "Error: " << e.what() << std::endl;
    }
    return (0);
}
