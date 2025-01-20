/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbendjab <hbendjab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:48:29 by hbendjab          #+#    #+#             */
/*   Updated: 2025/01/20 10:48:33 by hbendjab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP    


#include <iostream>



class Harl{
     
     private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
     public:
     Harl(void);
     ~Harl(void);
     Harl(const Harl& other);  
     Harl& operator=(const Harl& other);
     void complain(std::string level);
};

#endif