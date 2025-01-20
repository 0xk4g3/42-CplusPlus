/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:49:05 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:49:06 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <cstring>
# include <iostream>

class Harl
{
  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

  public:
	Harl(void);
	~Harl(void);
	Harl(const Harl &other);            // make copy constructor
	Harl &operator=(const Harl &other); // coppay assignment operator
	void complain(std::string level);
};

#endif