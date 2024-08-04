/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:28:41 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/03 13:13:47 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include "Contact.hpp"
#include <string>
#include <cstdlib>

class Phonebook {

private: 

	Contact Contacts[8];	
	int	capa; 

public: 

	Phonebook();
	~Phonebook();
	void addContact();
	void printPhonebook();
    bool    isNumber(std::string& str);
	
};

#endif
