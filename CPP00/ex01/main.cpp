/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:48:33 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/05 10:04:33 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main() {

    Phonebook phonebook = Phonebook();
    std::string userInput = "";
    while (!std::cin.eof())
    {
        std::cout << "What can I do for you?: ";
        std::getline(std::cin, userInput);
        if (userInput == "ADD")
            phonebook.addContact();
        else if (userInput.compare("SEARCH") == 0)
            phonebook.printPhonebook();
        else if (userInput.compare("EXIT") == 0)
            break ;
        else if (!std::cin.eof()) 
            std::cout <<std::endl << "You have just the options: \"ADD\" | \"SEARCH\" | \"EXIT\"" << std::endl <<std::endl;
    }
    return (0);
}
