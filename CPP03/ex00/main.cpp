/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:16:13 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/11 15:55:57 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main () {

    ClapTrap a("Franz"); 
    ClapTrap b("Josef");
    ClapTrap c("Justus");
    ClapTrap d("Justus Copy");

    d = c;
    d.attack("Josef");
    b.takeDamage(d.getAttackDamage());


    a.attack("Josef");
    b.takeDamage(a.getAttackDamage());

    a.attack("Josef");
    b.takeDamage(50);

    for (int i = 0; i < 15; i++)
    {
        a.beRepaired(1);
    }
    a.attack("random");
    
    return (0);
}
