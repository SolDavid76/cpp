/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:30:43 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/29 16:52:28 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <iostream>
# include <ctime>

class Base
{
	public:
		virtual ~Base(void) {};
};

class A: public Base {};

class B: public Base {};

class C: public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
