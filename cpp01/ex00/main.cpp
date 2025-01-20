/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:44:27 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:45:10 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie **NewZombie = new Zombie *[5];
	for (int i = 0; i < 5; i++)
	{
		NewZombie[i] = new Zombie("haithem");
	}
	for (int i = 0; i < 5; i++)
	{
		NewZombie[i]->announce();
	}
	for (int i = 0; i < 5; i++)
	{
		delete NewZombie[i];
	}
	delete[] NewZombie;

	randomChump("bendjaballah");
	randomChump("bendjaballah");
	randomChump("bendjaballah");
	randomChump("bendjaballah");
	randomChump("bendjaballah");

	return (0);
}