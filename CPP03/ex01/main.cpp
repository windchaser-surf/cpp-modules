/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:16:13 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/11 16:57:35 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main () {

    ClapTrap a("Franz"); 
    ScavTrap b("Josef");
    ClapTrap c(a);

    c.attack("Josef");
    b.takeDamage(c.getAttackDamage());


    a.attack("Josef");
    b.takeDamage(a.getAttackDamage());

    a.beRepaired(40);
    a.beRepaired(40);
    a.beRepaired(40);
    a.beRepaired(40);
    a.beRepaired(40);
    a.beRepaired(40);
    a.beRepaired(40);
    a.beRepaired(40);
    a.beRepaired(40);
    a.beRepaired(40);
    a.beRepaired(40);

    a.attack("Josef");
    b.takeDamage(a.getAttackDamage());

    b.attack("Franz");
    a.takeDamage(b.getAttackDamage());

    b.attack("Franz");
    a.takeDamage(b.getAttackDamage());

    

    b.attack("Franz");
    a.takeDamage(b.getAttackDamage());
   
    return (0);
}
