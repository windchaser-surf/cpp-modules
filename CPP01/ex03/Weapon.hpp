/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:00:20 by felix             #+#    #+#             */
/*   Updated: 2024/02/06 12:04:12 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon {
	
	private: 
	
		std::string _type;

	public: 
	
		Weapon();
		Weapon(std::string type);
		~Weapon();
		std::string         getType(void) const;
		void                setType(std::string type);
};

#endif
