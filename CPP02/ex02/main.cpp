/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:02:45 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/07 10:46:37 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {

	Fixed a;
	Fixed const b( 10 );
 	Fixed const c( 42.42f );
	Fixed const d( b );
	Fixed const e (Fixed(5.05f) - Fixed(2));
	Fixed const f (Fixed(5.05f) * Fixed(2));
	Fixed const g (Fixed(5.05f) / Fixed(2));
	Fixed const h (Fixed(5.05f) + Fixed(2));
	Fixed i;
	
	a = Fixed( 1234.4321f );


	std::cout << "i = "<< i << std::endl;
	std::cout << "++i = " <<++i << std::endl;
	std::cout << "i++ = " << i++ << std::endl;
	std::cout << "i = " << i << std::endl;
	std::cout << "--i = " << --i << std::endl;
	std::cout << "i-- = " << i-- << std::endl; 
	std::cout << "i = " << i << std::endl;
	std::cout << Fixed::max( a, b)  << std::endl; 
	std::cout << Fixed::min( a, b)  << std::endl; 

	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a < b)
		std::cout << "a < b" << std::endl;
	if (d >= b)
		std::cout << "d >= b" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (d == b)
		std::cout << "d == b" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;	
	return (0);
}
