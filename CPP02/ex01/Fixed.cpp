/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed1.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:56:09 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/04 12:53:13 by fwechsle         ###   ########.fr       */
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

Fixed::Fixed(float const inputFloat) {
	
	this->fixedVal = roundf(inputFloat * (1 << this->bits));
	std::cout << "Constructor float called" << std::endl;
}

Fixed::Fixed(int const inputInt) {

	this->fixedVal = inputInt * (1 << 8);
	std::cout << "Constructor int called" << std::endl;
}

Fixed&   Fixed::operator=(const Fixed& other) {
	
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other) {
		this->fixedVal = other.getRawBits();
	}
	return (*this);
}

int Fixed::toInt(void) const {

	return (this->fixedVal / (1 << this->bits));
}

float Fixed::toFloat(void) const {

	return ((float)this->fixedVal / (1 << this->bits));
}

std::ostream &operator<<(std::ostream& of, const Fixed& other){

		of << other.toFloat();
		return (of);
}

int Fixed::getRawBits(void) const {
	
	return (this->fixedVal);
}

void    Fixed::setRawBits(int const raw) {

	this->fixedVal = raw;
}

Fixed::~Fixed() {
	
	std::cout << "Destructor called" << std::endl;
}
