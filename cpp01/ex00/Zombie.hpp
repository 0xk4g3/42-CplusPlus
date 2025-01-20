/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:44:58 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:45:20 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(std::string ZombieName);
	void announce();
	~Zombie();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
#endif