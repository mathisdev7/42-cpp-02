/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:18:36 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/20 08:37:26 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::~Fixed()
{
}

Fixed::Fixed(const int nb)
{
	this->_n = nb << this->_bits;
}

Fixed::Fixed(const float nb)
{
	this->_n = roundf(nb * (1 << this->_bits));
}

Fixed::Fixed() : _n(0)
{
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

int Fixed::getRawBits(void) const
{
	return (this->_n);
}

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->_n = src.getRawBits();
	return (*this);
}

// ---------------------------------
// ---- comparison operators ---- //

bool Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

// ---- comparison operators ---- //

// ---------------------------------
// ---- arithmetic operators ---- //

float Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

float Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

// ---- arithmetic operators ---- //

// ---------------------------------
// ---- post-increment operators ---- //

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_n;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_n;
	return (temp);
}

// ---- post-increment operators ---- //

// ---------------------------------
// ---- pre-increment operators ---- //

Fixed Fixed::operator++()
{
	this->_n++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->_n--;
	return (*this);
}

// ---- pre-increment operators ---- //
// ---------------------------------

Fixed &Fixed::min(Fixed &left, Fixed &right)
{
	if (left.toFloat() <= right.toFloat())
		return (left);
	else
		return (right);
}

const Fixed &Fixed::min(Fixed const &left, Fixed const &right)
{
	if (left.toFloat() <= right.toFloat())
		return (left);
	else
		return (right);
}

Fixed &Fixed::max(Fixed &left, Fixed &right)
{
	if (left.toFloat() >= right.toFloat())
		return (left);
	else
		return (right);
}

const Fixed &Fixed::max(Fixed const &left, Fixed const &right)
{
	if (left.toFloat() >= right.toFloat())
		return (left);
	else
		return (right);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_n / (float)(1 << this->_bits));
}

int Fixed::toInt(void) const
{
	return (this->_n >> this->_bits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}

void Fixed::setRawBits(int const bits)
{
	this->_n = bits;
}
