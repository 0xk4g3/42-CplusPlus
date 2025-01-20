/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:47:09 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:47:15 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "./Weapon.hpp"

# include <iostream>

class HumanB
{
  private:
	std::string name;
	Weapon *weapon;

  public:
	HumanB(std::string human);
	void setWeapon(Weapon &weapon);
	void attack(void);
	~HumanB();
};

#endif