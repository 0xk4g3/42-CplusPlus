/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:45:39 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:45:39 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*Nzombie;

	if (n <= 0)
		return (NULL);
	if (name.empty()
		|| name.find_first_not_of(" \t\n\r\v\f") == std::string::npos)
	{
		name = "Unnamed";
	}
	Nzombie = NULL;
	try
	{
		Nzombie = new Zombie[n];
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed :" << e.what() << std::endl;
		return (NULL);
	}
	for (int i = 0; i < n; i++)
	{
		Nzombie[i].SetName(name);
	}
	return (Nzombie);
}
