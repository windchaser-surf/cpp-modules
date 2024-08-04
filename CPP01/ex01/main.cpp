/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:20:57 by felix             #+#    #+#             */
/*   Updated: 2024/02/04 13:05:44 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main () {

	int N = 5; 

		Zombie* zombie_Horde = zombieHorde(N, "Zombie1");
		for (int i = 0; i < N; i++)
		{
			zombie_Horde[i].announce(i);
		}
	delete [] zombie_Horde;
	return (0);
}