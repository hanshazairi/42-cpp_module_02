/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:36:00 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/03 00:53:59 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX00_FIXED_HPP_
#define EX00_FIXED_HPP_

class Fixed {
 public:
    Fixed(void);
    Fixed(const Fixed &fixed);
    Fixed &operator=(const Fixed &fixed);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(const int raw);

 private:
    static const int NUM_FRACTIONAL_BITS_ = 8;
    int raw_;
};

#endif  // EX00_FIXED_HPP_
