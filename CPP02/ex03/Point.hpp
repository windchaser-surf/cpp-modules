/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:48:35 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/07 14:23:18 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {

    private: 

        Fixed x; 
        Fixed y; 
        
    public: 
        
        Point();
        Point(const float x, const float y);
        Point(const Point& old);
        ~Point();
   		Point &operator=(const Point& other);
        float getX(void) const; 
        float getY(void) const;
        
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
