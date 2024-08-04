/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:56:15 by fwechsle          #+#    #+#             */
/*   Updated: 2024/03/02 12:42:50 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <string.h>
# include <iostream>

class Fixed {
    
    private: 
    
        int fixedVal;
        static const int bits = 8;
    
    public:
     
        Fixed();
        Fixed(const Fixed& old);
        ~Fixed(void);
        Fixed &operator=(const Fixed& other);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif
