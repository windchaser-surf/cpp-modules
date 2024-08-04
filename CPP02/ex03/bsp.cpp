/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:57:38 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/07 19:45:02 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float cross_product(Point const a, Point const b, Point const c) {

	float result = (b.getX() - a.getX()) * (c.getY() - a.getY()) - \
			(c.getX() - a.getX()) * (b.getY() - a.getY());
	if (result < 0)
		result *= -1;
	return (result);
}

float calc_area(Point const a, Point const b, Point const c) {

	return (0.5 * cross_product(a, b, c));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	
	float A0 = calc_area(a, b, c);
	float A1 = calc_area(a, b, point);
	float A2 = calc_area(a, c, point);
	float A3 = calc_area(b, c, point);

	if (A1 == 0 || A2 == 0 || A3 == 0)
		return (false);

	return (A0 == A1 + A2 + A3);
}
