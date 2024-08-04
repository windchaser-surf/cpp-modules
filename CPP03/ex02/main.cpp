/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:16:13 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/12 11:23:25 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main () {

    ClapTrap franz("Franz");
    FragTrap justus("Justus");
    ScavTrap anton("Anton");

    franz.attack("Justus");
    justus.takeDamage(franz.getAttackDamage());
    
    justus.attack("Franz");
    franz.takeDamage(justus.getAttackDamage());
    
    anton.attack("Justus");
    justus.takeDamage(anton.getAttackDamage());
    
    justus.beRepaired(20);
    
    anton.attack("Justus");
    justus.takeDamage(anton.getAttackDamage());
    
    justus.attack("Franz");
    franz.takeDamage(justus.getAttackDamage());

    franz.beRepaired(20);
    
    return (0);
}
