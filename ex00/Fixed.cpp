/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:18:36 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/19 15:40:55 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

Fixed::Fixed() : _n(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

int Fixed::getRawBits(void) const
{
	std::cout << "GetRawBits member function called" << std::endl;
	return (this->_n);
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Fixed assignation function called" << std::endl;
	if (this != &src)
		this->_n = src.getRawBits();
	return (*this);
}

void Fixed::setRawBits(int const bits)
{
	std::cout << "SetRawBits member function called" << std::endl;
	this->_n = bits;
}
