/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:45:33 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/05 11:45:52 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point AB(((Point)b).get_x().toFloat() - ((Point)a).get_x().toFloat(), ((Point)b).get_y().toFloat() - ((Point)a).get_y().toFloat());
	Point BC(((Point)c).get_x().toFloat() - ((Point)b).get_x().toFloat(), ((Point)c).get_y().toFloat() - ((Point)b).get_y().toFloat());
	Point CA(((Point)a).get_x().toFloat() - ((Point)c).get_x().toFloat(), ((Point)a).get_y().toFloat() - ((Point)c).get_y().toFloat());
	Point PA(((Point)a).get_x().toFloat() - ((Point)point).get_x().toFloat(), ((Point)a).get_y().toFloat() - ((Point)point).get_y().toFloat());
	Point PB(((Point)b).get_x().toFloat() - ((Point)point).get_x().toFloat(), ((Point)b).get_y().toFloat() - ((Point)point).get_y().toFloat());
	Point PC(((Point)c).get_x().toFloat() - ((Point)point).get_x().toFloat(), ((Point)c).get_y().toFloat() - ((Point)point).get_y().toFloat());
	return ((((PA.get_x().toFloat() * AB.get_y().toFloat()) - (PA.get_y().toFloat() * AB.get_x().toFloat())) * ((PB.get_x().toFloat() * BC.get_y().toFloat()) - (PB.get_y().toFloat() * BC.get_x().toFloat())) * ((PC.get_x().toFloat() * CA.get_y().toFloat()) - (PC.get_y().toFloat() * CA.get_x().toFloat()))) >= 0);
}

// AB = (xB - xA, yB - yA)
// BC = (xC - xB, yC - yB)
// CA = (xA - xC, yA - yC)
// AP = (xP - xA, yP - yA)
// (PA × AB) * (PB × BC) * (PC × CA) > 0