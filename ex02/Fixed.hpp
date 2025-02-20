/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:25:14 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/20 08:34:41 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#pragma once

class Fixed
{
private:
	int _n;
	static const int _bits;

public:
	Fixed();
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed();
	Fixed(const Fixed &copy);
	int getRawBits(void) const;
	// overloaded operator
	Fixed &operator=(const Fixed &src);
	// comparison operators
	bool operator==(Fixed fixed) const;
	bool operator>(Fixed fixed) const;
	bool operator<(Fixed fixed) const;
	bool operator<=(Fixed fixed) const;
	bool operator>=(Fixed fixed) const;
	bool operator!=(Fixed fixed) const;
	// arithmetic operators
	float operator+(Fixed fixed) const;
	float operator-(Fixed fixed) const;
	float operator*(Fixed fixed) const;
	float operator/(Fixed fixed) const;
	// post-increment operators
	Fixed operator++(int);
	Fixed operator--(int);
	// pre-increment operators
	Fixed operator++();
	Fixed operator--();

	static Fixed &min(Fixed &left, Fixed &right);
	static const Fixed &min(Fixed const &left, Fixed const &right);
	static Fixed &max(Fixed &left, Fixed &right);
	static const Fixed &max(Fixed const &left, Fixed const &right);
	void setRawBits(int const bits);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);
