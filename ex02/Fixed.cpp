/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:56:46 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/03 01:30:35 by hbaddrul         ###   ########.fr       */
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
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void) {
    ++raw_;

    return *this;
}

Fixed &Fixed::operator--(void) {
    --raw_;

    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    ++raw_;

    return tmp;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    --raw_;

    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a <= b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a >= b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a <= b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a >= b ? a : b);
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
