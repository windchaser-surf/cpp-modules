/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:06:43 by felix             #+#    #+#             */
/*   Updated: 2024/02/06 10:12:55 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    
    Zombie* heap_zombie = newZombie("Heapiii");
    heap_zombie->announce();
    randomChump("Stackiiii");
    delete heap_zombie;
    return (0);
}
