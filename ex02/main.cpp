/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:55:58 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/03 01:01:38 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

using std::cout;
using std::endl;

int main(void) {
    Fixed a;
    const Fixed b(Fixed(5.05f) * Fixed(2));

    cout << a << endl;
    cout << ++a << endl;
    cout << a << endl;
    cout << a++ << endl;
    cout << a << endl;

    cout << b << endl;

    cout << Fixed::max(a, b) << endl;

    return 0;
}
