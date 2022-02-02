/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:03:16 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/03 00:51:23 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

#include "Fixed.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::roundf;

Fixed::Fixed(void) : raw_(0) {
    cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int raw) : raw_(raw << NUM_FRACTIONAL_BITS_) {
    cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float raw)
    : raw_(roundf(raw * (1 << NUM_FRACTIONAL_BITS_))) {
    cout << "Float constructor called" << endl;
}

Fixed::Fixed(const Fixed &fixed) {
    cout << "Copy constructor called" << endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    cout << "Copy assignment operator called" << endl;

    if (this != &fixed)
        raw_ = fixed.getRawBits();

    return *this;
}

Fixed::~Fixed(void) {
    cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const {
    return raw_;
}

void Fixed::setRawBits(const int raw) {
    raw_ = raw;
}

float Fixed::toFloat(void) const {
    return (static_cast<float>(raw_) / (1 << NUM_FRACTIONAL_BITS_));
}

int Fixed::toInt(void) const {
    return (raw_ >> NUM_FRACTIONAL_BITS_);
}

ostream &operator<<(ostream &o, const Fixed &fixed) {
    return (o << fixed.toFloat());
}
