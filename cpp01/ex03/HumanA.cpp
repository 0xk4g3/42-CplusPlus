/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:46:23 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:46:24 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string human, Weapon &weapon) : name(human), weapon(weapon)
{
}

HumanA::~HumanA(){};
void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}