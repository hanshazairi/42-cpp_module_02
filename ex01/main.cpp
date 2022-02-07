/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:03:23 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/08 00:33:57 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

using std::cout;
using std::endl;

int main(void) {
    Fixed a;
    const Fixed b(10);
    const Fixed c(42.42f);
    const Fixed d(b);

    a = Fixed(1234.4321f);

    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "c is " << c << endl;
    cout << "d is " << d << endl;

    cout << "a is " << a.toInt() << " as integer" << endl;
    cout << "b is " << b.toInt() << " as integer" << endl;
    cout << "c is " << c.toInt() << " as integer" << endl;
    cout << "d is " << d.toInt() << " as integer" << endl;

    return 0;
}
