/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:44:40 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:45:13 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*Nzombie;

	if (name.empty())
		name = "Unnamed";
	Nzombie = NULL;
	try
	{
		Nzombie = new Zombie(name);
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed :" << e.what() << std::endl;
		return (NULL);
	}
	return (Nzombie);
}
