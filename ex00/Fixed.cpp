/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:36:25 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/03 00:52:23 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed(void) : raw_(0) {
    cout << "Default constructor called" << endl;
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
    cout << "getRawBits member function called" << endl;

    return raw_;
}

void Fixed::setRawBits(const int raw) {
    raw_ = raw;
}
