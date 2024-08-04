/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:56:09 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/02 18:20:50 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {

	this->fixedVal = 0;
	std::cout << "Class Fixed is created" << std::endl;
}

Fixed::Fixed(const Fixed& old) {
	
	std::cout << "Copy Constructor called" << std::endl;
	operator=(old);					  //Option 1
/* 	this->fixedVal = old.fixedVal; */ //Option 2 this should be better
}

Fixed&   Fixed::operator=(const Fixed& other) {
	
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other) {
		this->fixedVal = other.getRawBits();
	}
	return (*this);
}


int Fixed::getRawBits(void) const {
	
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedVal);
}

void    Fixed::setRawBits(int const raw) {

	this->fixedVal = raw;
}

Fixed::~Fixed() {
	
	std::cout << "Destructor called" << std::endl;
}
