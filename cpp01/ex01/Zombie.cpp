/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:45:28 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:45:29 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){};

void Zombie::announce()
{
	std::cout << _name << ": "
				<< "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::SetName(std::string name)
{
	_name = name;
}
Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " has been destroyed" << std::endl;
}
