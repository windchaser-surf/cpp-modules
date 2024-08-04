/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:07:01 by felix             #+#    #+#             */
/*   Updated: 2024/02/06 10:20:54 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB {
    
    private: 

        std::string _name; 
        Weapon *_type; 
    
    public: 

        HumanB(std::string name);
        ~HumanB();
        void    attack();
        void    setWeapon(Weapon &type);
        
};

#endif
