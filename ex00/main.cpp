/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:35:52 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/02 18:40:15 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

using std::cout;
using std::endl;

int main(void) {
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    cout << a.getRawBits() << endl;
    cout << b.getRawBits() << endl;
    cout << c.getRawBits() << endl;

    return 0;
}
