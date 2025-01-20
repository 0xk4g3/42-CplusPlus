/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:44:53 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:45:18 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string ZombieName) : _name(ZombieName.empty() ? "Unnamed" : ZombieName){};

void Zombie::announce()
{
	std::cout << _name << ": "
				<< "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " has been destroyed" << std::endl;
}
