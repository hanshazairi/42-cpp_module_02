/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:03:06 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/02 21:07:57 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX01_FIXED_HPP_
#define EX01_FIXED_HPP_

#include <iostream>

using std::ostream;

class Fixed {
 public:
    Fixed(void);
    explicit Fixed(const int raw);
    explicit Fixed(const float raw);
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(const int raw);
    float toFloat(void) const;
    int toInt(void) const;

 private:
    static const int NUM_FRACTIONAL_BITS_ = 8;
    int raw_;
};

/* Fixed.cpp */
ostream &operator<<(ostream &o, const Fixed &fixed);

#endif  // EX01_FIXED_HPP_
