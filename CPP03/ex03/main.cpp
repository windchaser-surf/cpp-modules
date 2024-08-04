/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:16:13 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/12 15:51:48 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main () {

    DiamondTrap jakob("jakob");
    DiamondTrap chris("chris");
    DiamondTrap felix("felix");


    chris.attack("jakob");
    jakob.takeDamage(chris.getAttackDamage());
    
    
    chris.attack("jakob");
    jakob.takeDamage(chris.getAttackDamage());
    
    chris.attack("jakob");
    jakob.takeDamage(chris.getAttackDamage());
    
    chris.attack("jakob");
    jakob.takeDamage(chris.getAttackDamage());
    
    for (int i = 0; i < 80; i++)
    {
        felix.attack("chris");
        chris.takeDamage(felix.getAttackDamage());
        std::cout << "--------------------------------------------------" << std::endl;
    }
    
    jakob.whoAmI();
    
    return (0);
}
