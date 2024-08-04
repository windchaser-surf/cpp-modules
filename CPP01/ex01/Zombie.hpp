/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:20:23 by felix             #+#    #+#             */
/*   Updated: 2024/02/04 13:00:00 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>
#include <sstream>

class Zombie {

private: 
    
    std::string name;

public:

    Zombie();
    Zombie (std::string name);
    ~Zombie (void);
    void announce(int N);
    void setName (std::string name);

};

Zombie* zombieHorde(int N, std::string name);

#endif