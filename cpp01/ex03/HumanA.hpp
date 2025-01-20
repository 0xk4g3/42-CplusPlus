/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:46:30 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:46:48 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>
class HumanA
{
  private:
	std::string name;
	Weapon &weapon;

  public:
	HumanA(std::string human, Weapon &weapon);
	void attack(void);
	~HumanA();
};

#endif