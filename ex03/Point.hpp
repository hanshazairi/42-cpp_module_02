/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 00:48:16 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/08 03:08:00 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_POINT_HPP_
#define EX03_POINT_HPP_

#include <iostream>

#include "Fixed.hpp"

using std::ostream;

class Point {
 public:
    Point(void);
    Point(const float x, const float y);
    Point(const Point &point);
    Point &operator=(const Point &point);
    ~Point(void);

    const Fixed get_x(void) const;
    const Fixed get_y(void) const;

 private:
    const Fixed x_;
    const Fixed y_;
};

/* Point.cpp */
ostream &operator<<(ostream &o, const Point &point);

/* bsp.cpp */
bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif  // EX03_POINT_HPP_
