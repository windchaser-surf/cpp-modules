/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:31:45 by felix             #+#    #+#             */
/*   Updated: 2024/02/04 13:00:21 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {

    private :

    std::string name;

    public: 

    Zombie();
    Zombie(std::string name);
    ~Zombie(void);
    void    announce (void);

};

    Zombie* newZombie(std::string name);
    void    randomChump(std::string name);

#endif
