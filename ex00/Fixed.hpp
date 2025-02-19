/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:25:14 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/19 15:40:39 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

class Fixed
{
private:
	int _n;
	static const int _bits;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &copy);
	int getRawBits(void) const;
	Fixed &operator=(const Fixed &src);
	void setRawBits(int const bits);
};
