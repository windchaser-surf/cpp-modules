/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 12:02:45 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/07 14:49:05 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {

	Point a;
	Point b(5.0, 0.0);
	Point c(0.0, 5.0);
	Point p(0.0, 5.0);
	if (bsp(a, b, c, p))
		std::cout << "Point p is inside of the triangle!" << std::endl;
	else 
		std::cout << "Point p is outside of the triangle!" << std::endl;


	Point a1(0.0, 0.0);
	Point b1(3.0, 0.0);
	Point c1(0.0, 3.0);
	Point p1(4.0, 4.0);
	if (bsp(a1, b1, c1, p1))
		std::cout << "Point p1 is inside of the triangle!" << std::endl;
	else 
		std::cout << "Point p1 is outside of the triangle!" << std::endl;
	
		
	Point a2(0.0, 0.0);
	Point b2(2.0, 2.0);
	Point c2(4.0, 4.0);
	Point p2(3.0, 3.0);
	if (bsp(a2, b2, c2, p2))
		std::cout << "Point p2 is inside of the triangle!" << std::endl;
	else 
		std::cout << "Point p2 is outside of the triangle!" << std::endl;
	



	Point a3(-1.0, -1.0);
	Point b3(2.0, -1.0);
	Point c3(-1.0, 2.0);
	Point p3(0.0, 0.0);
	if (bsp(a3, b3, c3, p3))
		std::cout << "Point p3 is inside of the triangle!" << std::endl;
	else 
		std::cout << "Point p3 is outside of the triangle!" << std::endl;

	Point a4(0.0, 0.0);
	Point b4(3.0, 0.0);
	Point c4(1.5, 2.598);
	Point p41(1.0, 1.0);
	Point p42(4.0, 4.0);
	if (bsp(a4, b4, c4, p41))
		std::cout << "Point p41 is inside of the triangle!" << std::endl;
	else 
		std::cout << "Point p41 is outside of the triangle!" << std::endl;
	
	if (bsp(a4, b4, c4, p42))
		std::cout << "Point p42 is inside of the triangle!" << std::endl;
	else 
		std::cout << "Point p42 is outside of the triangle!" << std::endl;
	
	return (0);
}
