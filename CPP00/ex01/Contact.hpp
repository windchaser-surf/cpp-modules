/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:16:07 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/05 10:03:24 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

class Contact {

private:

    std::string first_name; 
    std::string last_name;
    std::string nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

public:

    Contact();
    ~Contact();
    void        setContact();
    void        printContact();
    void        printIndexContact(int index);
    void        setContactAttribute(std::string& attribute, \
                const std::string& prompt);
    std::string replaceTabsWithSpaces(const std::string& str);
    std::string truncateContact(std::string str);
            
};

#endif
