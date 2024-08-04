/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:46:27 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/07 14:31:50 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {
	this->x = Fixed(0);
	this->y = Fixed(0);
}

Point::Point(const float x, const float y) {
	
	this->x = Fixed(x);
	this->y = Fixed(y);
}

Point::Point(const Point& old) {

	*this = old;
}

Point   &Point::operator=(const Point& old) {

	if (this != &old)
	{
		this->x = old.x;
		this->y = old.y;
	}
	return (*this);
}

float Point::getX(void) const {

	return (this->x.toFloat());
}

float Point::getY(void) const {

	return (this->y.toFloat());
}

Point::~Point(){
	
}
