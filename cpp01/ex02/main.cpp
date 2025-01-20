/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:45:52 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:45:53 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "########## First Part ###############" << std::endl;
	std::cout << "The memory address of the string variable: " << &string << std::endl;
	std::cout << "The memory address held by stringPTR:      " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:      " << &stringREF << std::endl;
	std::cout << "########## First Part ###############" << std::endl;

	std::cout << "The value of the string variable:          " << string << std::endl;
	std::cout << "The value pointed to by stringPTR:         " << *stringPTR << std::endl;
	std::cout << "The value of stringREF:                    " << stringREF << std::endl;

	return (0);
}