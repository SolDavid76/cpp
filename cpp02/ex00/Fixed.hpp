/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:51:27 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/03 15:41:04 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed& src);
		~Fixed(void);

		Fixed& operator=(Fixed const& rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int RawBits;
		static const int nb_bits = 8;
};


#endif