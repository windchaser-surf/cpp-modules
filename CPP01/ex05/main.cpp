/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:36:51 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/05 12:38:36 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {

    Harl obj;

    obj.complain("ERROR");
    obj.complain("DEBUG");
    obj.complain("INFO");
    obj.complain("WARNING");
    obj.complain("NOTHING");
    obj.complain("");

    return (0);
}
