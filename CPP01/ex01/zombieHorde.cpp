/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:20:51 by felix             #+#    #+#             */
/*   Updated: 2024/02/04 13:29:36 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {

    
    Zombie* zombie_Horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombie_Horde[i].setName(name);
    }
    return (zombie_Horde);
}