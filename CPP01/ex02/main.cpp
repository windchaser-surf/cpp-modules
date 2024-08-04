/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:31:40 by felix             #+#    #+#             */
/*   Updated: 2024/02/04 13:55:03 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main() {

    std::string str = "HI THIS IS BRAIN";
    std::string* strPTR = &str;
    std::string& strREF = str;

    std::cout << "+++ Memory address +++" << std::endl;
    std::cout << "String: " << &str << std::endl;
    std::cout << "Pointer: " << strPTR << std::endl; 
    std::cout << "Reference: " << &strREF << std::endl; 

    std::cout << "+++ value +++" << std::endl;
    std::cout << "String: " << str << std::endl;
    std::cout << "Pointer: " << *strPTR << std::endl;
    std::cout << "Reference: " << strREF << std::endl;
    
    return (0);
}
