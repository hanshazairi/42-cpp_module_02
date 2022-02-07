/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:51:32 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/08 03:01:33 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x_(0), y_(0) {}

Point::Point(const float x, const float y) : x_(x), y_(y) {}

Point::Point(const Point &point) {
    *this = point;
}

Point &Point::operator=(const Point &point) {
    if (this != &point) {
        const_cast<Fixed&>(x_) = point.get_x();
        const_cast<Fixed&>(y_) = point.get_y();
    }

    return *this;
}

Point::~Point(void) {}

const Fixed Point::get_x(void) const {
    return x_;
}

const Fixed Point::get_y(void) const {
    return y_;
}

ostream &operator<<(ostream &o, const Point &point) {
    return (o << "(" << point.get_x() << ", " << point.get_y() << ")");
}
