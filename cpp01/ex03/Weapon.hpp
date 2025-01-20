/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:47:45 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:47:46 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP 
#define WEAPON_HPP


#include <iostream>

class Weapon{
          private:
                  std::string type;
          public:  
          Weapon(std::string type);
          const  std::string& getType()const;
          void setType(std::string newType);
          ~Weapon();
};



#endif