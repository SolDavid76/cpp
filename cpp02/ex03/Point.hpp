/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:50:00 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/05 11:43:55 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point& src);
		~Point(void);

		Point& operator=(Point const& rhs);

		Fixed get_x(void);
		Fixed get_y(void);
	private:
		Fixed _x;
		Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
