/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:03:09 by felix             #+#    #+#             */
/*   Updated: 2024/02/06 10:20:52 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA {
    
    private: 

        std::string _name; 
        Weapon &_type; 
    
    public: 

        void    attack();
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
};

#endif
