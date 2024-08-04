/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:56:09 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/07 10:46:44 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {

	this->fixedVal = 0;
}

Fixed::Fixed(const Fixed& old) {
	
	operator=(old);					  //Option 1
/* 	this->fixedVal = old.fixedVal; */ //Option 2 this should be better
}

Fixed::Fixed(float const inputFloat) {
	
	this->fixedVal = roundf(inputFloat * (1 << this->bits));
}

Fixed::Fixed(int const inputInt) {

	this->fixedVal = inputInt * (1 << 8);
}

Fixed&   Fixed::operator=(const Fixed& other) {
	
	if (this != &other) {
		this->fixedVal = other.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator>(const Fixed& other) const {
	
	if (this->toFloat() > other.toFloat())
		return (true);
	else 
		return (false);
}

bool Fixed::operator<(const Fixed& other) const {
	
	if (this->toFloat() < other.toFloat())
		return (true);
	else 
		return (false);
}

bool	Fixed::operator>=(const Fixed& other) const {

	if (this->toFloat() >= other.toFloat())
		return (true);
	else 
		return (false);
}

bool	Fixed::operator<=(const Fixed& other) const {

	if (this->toFloat() <= other.toFloat())
		return (true);
	else 
		return (false);
}

bool	Fixed::operator==(const Fixed& other) const {

	if (this->toFloat() == other.toFloat())
		return (true);
	else 
		return (false);
}

bool	Fixed::operator!=(const Fixed& other) const {

	if (this->toFloat() != other.toFloat())
		return (true);
	else 
		return (false);
}

Fixed 	Fixed::operator*(const Fixed& other) const {
	
	Fixed ret;
	ret.fixedVal = (this->toFloat() * other.toFloat()) * (1 << this->bits);
	return (ret);
}

Fixed 	Fixed::operator/(const Fixed& other) const{
	
	Fixed ret;
	ret.fixedVal = (this->toFloat() / other.toFloat() * (1 << this->bits));
	return (ret);
}

Fixed 	Fixed::operator+(const Fixed& other) const {
	
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed 	Fixed::operator-(const Fixed& other) const {
	
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed& 	Fixed::operator++(void) {

	this->fixedVal += 1;
	return (*this);
}

Fixed 	Fixed::operator++(int) {

	Fixed temp(this->toFloat());
	++(this->fixedVal);
	return (temp);	
}

Fixed& Fixed::operator--(void) {

	this->fixedVal -= 1; 
	return (*this);
}

Fixed Fixed::operator--(int) {
	
	Fixed temp(*this); 
	--(this->fixedVal);
	return (temp);
}

int Fixed::toInt(void) const {

	return (this->fixedVal / (1 << this->bits));
}

float Fixed::toFloat(void) const {

	return ((float)this->fixedVal / (1 << this->bits));
}


int Fixed::getRawBits(void) const {
	
	return (this->fixedVal);
}

void    Fixed::setRawBits(int const raw) {

	this->fixedVal = raw;
}

Fixed::~Fixed() {
	
}

std::ostream &operator<<(std::ostream& of, const Fixed& other){

		of << other.toFloat();
		return (of);
}

Fixed&	Fixed::max(Fixed& one, Fixed& two) {
	
	if (one.toFloat() > two.toFloat())
		return (one);
	return (two);
}

Fixed&	Fixed::max(const Fixed& one, const Fixed& two) {
	
	if (one.toFloat() > two.toFloat())
		return ((Fixed&)one);
	return ((Fixed&)two);
}

Fixed&	Fixed::min(Fixed& one, Fixed& two) {
	
	if (one.toFloat() > two.toFloat())
		return (two);
	return (one);
}

Fixed&	Fixed::min(const Fixed& one, const Fixed& two) {
	
	if (one.toFloat() > two.toFloat())
		return ((Fixed&)two);
	return ((Fixed&)one);
}
