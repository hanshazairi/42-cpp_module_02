/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:47:29 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/08 03:15:01 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

#include "Fixed.hpp"

using std::ostream;
using std::roundf;

Fixed::Fixed(void) : raw_(0) {}

Fixed::Fixed(const int raw) : raw_(raw << NUM_FRACTIONAL_BITS_) {}

Fixed::Fixed(const float raw)
    : raw_(roundf(raw * (1 << NUM_FRACTIONAL_BITS_))) {}

Fixed::Fixed(const Fixed &fixed) {
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    if (this != &fixed)
        raw_ = fixed.get_raw();

    return *this;
}

Fixed::~Fixed(void) {}

bool Fixed::operator>(const Fixed &fixed) const {
    return (raw_ > fixed.raw_);
}

bool Fixed::operator<(const Fixed &fixed) const {
    return (raw_ < fixed.raw_);
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return (raw_ >= fixed.raw_);
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return (raw_ <= fixed.raw_);
}

bool Fixed::operator==(const Fixed &fixed) const {
    return (raw_ == fixed.raw_);
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return (raw_ != fixed.raw_);
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    return Fixed(this->to_float() + fixed.to_float());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return Fixed(this->to_float() - fixed.to_float());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return Fixed(this->to_float() * fixed.to_float());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    return Fixed(this->to_float() / fixed.to_float());
}

int Fixed::get_raw(void) const {
    return raw_;
}

void Fixed::set_raw(const int raw) {
    raw_ = raw;
}

int Fixed::to_int(void) const {
    return (raw_ >> NUM_FRACTIONAL_BITS_);
}

float Fixed::to_float(void) const {
    return (static_cast<float>(raw_) / (1 << NUM_FRACTIONAL_BITS_));
}

ostream &operator<<(ostream &o, const Fixed &fixed) {
    return (o << fixed.to_float());
}
