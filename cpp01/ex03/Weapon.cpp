/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:47:37 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:47:38 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Weapon.hpp"

Weapon::Weapon(std::string init_type) : type(init_type){};
Weapon::~Weapon(){};

const std::string &Weapon::getType() const
{
	return (type);
}

void Weapon::setType(std::string newType)
{
	type = newType;
}