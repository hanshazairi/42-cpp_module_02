/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:10:42 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/08 03:03:21 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed calc(const Point x, const Point y, const Point z) {
    Fixed tmp_1 = (x.get_x() - y.get_x()) * (z.get_y() - y.get_y());
    Fixed tmp_2 = (x.get_y() - y.get_y()) * (z.get_x() - y.get_x());

    return (tmp_1 - tmp_2);
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
    Fixed s = calc(a, c, point);
    Fixed t = calc(b, a, point);

    if ((s < Fixed(0)) != (t < Fixed(0)) && s != Fixed(0) && t != Fixed(0))
        return false;

    Fixed d = calc(c, b, point);

    return (d == Fixed(0) || (d < Fixed(0)) == (s + t <= Fixed(0)));
}
