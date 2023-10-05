/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:51:27 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/05 11:53:09 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int x);
		Fixed(const float x);
		Fixed(const Fixed& src);
		~Fixed(void);

		Fixed& operator=(Fixed const& rhs);

		/* ARITHMECTIC OPERATORS */
		Fixed operator+(Fixed const& rhs);
		Fixed operator-(Fixed const& rhs);
		Fixed operator*(Fixed const& rhs);
		Fixed operator/(Fixed const& rhs);

		/* INCREMENT/DECREMENT OPERATORS */
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		/* COMPARISON OPERATORS */
		bool operator<(Fixed const& rhs);
		bool operator>(Fixed const& rhs);
		bool operator<=(Fixed const& rhs);
		bool operator>=(Fixed const& rhs);
		bool operator==(Fixed const& rhs);
		bool operator!=(Fixed const& rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

		static Fixed& min(Fixed& x, Fixed& y);
		static Fixed const& min(Fixed const& x, Fixed const& y);
		static Fixed& max(Fixed& x, Fixed& y);
		static Fixed const& max(Fixed const& x, Fixed const& y);
	private:
		int RawBits;
		static const int nb_bits = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& src);

#endif