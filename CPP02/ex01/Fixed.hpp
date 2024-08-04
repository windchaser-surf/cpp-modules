/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:56:15 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/04 12:53:25 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <string.h>
# include <iostream>
# include <cmath>

class Fixed {
	
	private: 
	
		int 				fixedVal;
		static const int    bits = 8;
	
	public:
	 
		Fixed();
		Fixed(int const inputInt); //ex01
		Fixed(float const inputFloat);
		Fixed(const Fixed& old);
		~Fixed(void);
		Fixed &operator=(const Fixed& other);
		int     getRawBits(void) const;
		void    setRawBits(int const raw);
		float   toFloat(void) const;
		int     toInt(void) const;
};

std::ostream &operator<<(std::ostream& of, const Fixed& other);

#endif
