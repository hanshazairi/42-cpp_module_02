/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:47:09 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/08 03:14:36 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_FIXED_HPP_
#define EX03_FIXED_HPP_

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

    bool operator>(const Fixed &fixed) const;
    bool operator<(const Fixed &fixed) const;
    bool operator>=(const Fixed &fixed) const;
    bool operator<=(const Fixed &fixed) const;
    bool operator==(const Fixed &fixed) const;
    bool operator!=(const Fixed &fixed) const;

    Fixed operator+(const Fixed &fixed) const;
    Fixed operator-(const Fixed &fixed) const;
    Fixed operator*(const Fixed &fixed) const;
    Fixed operator/(const Fixed &fixed) const;

    int get_raw(void) const;
    void set_raw(const int raw);
    int to_int(void) const;
    float to_float(void) const;

 private:
    static const int NUM_FRACTIONAL_BITS_ = 8;
    int raw_;
};

/* Fixed.cpp */
ostream &operator<<(ostream &o, const Fixed &fixed);

#endif  // EX03_FIXED_HPP_
