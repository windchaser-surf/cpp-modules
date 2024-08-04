/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:36:51 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/06 10:39:53 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {

	Harl obj;

	if (argc != 2)
	{
		std::cout << "You have to enter one level! And nothing else is possible.." << std::endl;
		std::cout << std::endl;
		std::cout << "+++ LEVELS +++" << std::endl; 
		std::cout << "< DEBUG >" << std::endl;
		std::cout << "< INFO >" << std::endl;
		std::cout << "< WARNING >" << std::endl;
		std::cout << "< ERROR >" << std::endl;
		return (1);
	}
	obj.complain(argv[1]);

	return (0);
}
