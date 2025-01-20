/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:45:32 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:45:34 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# define N 4

# include <iostream>

class Zombie
{
  private:
	std::string _name;

  public:
	void SetName(std::string name);
	Zombie();
	void announce();
	~Zombie();
};

Zombie	*zombieHorde(int n, std::string name);

#endif
