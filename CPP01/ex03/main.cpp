/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:58:14 by felix             #+#    #+#             */
/*   Updated: 2024/02/06 10:26:03 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("Attack Weapon Bobieeee!!!");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Waterpistol for summer-party! ");
		bob.attack();
	}
	{
		Weapon club = Weapon();
		
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("waterbombs!");
		jim.attack();
}
return 0;
}
