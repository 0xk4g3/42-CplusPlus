/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:45:05 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:45:22 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "\n=== Testing normal cases ===" << std::endl;
	{
		Zombie *horde1 = zombieHorde(N, "Normal");
		if (horde1)
		{
			for (int i = 0; i < N; i++)
				horde1[i].announce();
			delete[] horde1;
		}
	}
	return (0);
}