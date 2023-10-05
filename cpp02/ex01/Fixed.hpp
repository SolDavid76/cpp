/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:51:27 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/04 13:57:11 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int x);
		Fixed(const float x);
		Fixed(const Fixed& src);
		~Fixed(void);

		Fixed& operator=(Fixed const& rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
	private:
		int RawBits;
		static const int nb_bits = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& src);

#endif