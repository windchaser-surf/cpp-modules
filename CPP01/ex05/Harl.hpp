/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:33:16 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/05 10:40:30 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>

class Harl {

	private: 

		void    debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:

		Harl();
		~Harl();
		void	complain(std::string level);

};

#endif
