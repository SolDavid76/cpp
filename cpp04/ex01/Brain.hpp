/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:00:30 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/13 19:29:30 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain& src);
		Brain& operator=(Brain const& src);
		~Brain(void);

		const std::string* get_ideas(void) const;
		void set_ideas(std::string idea, unsigned int index);
	private:
		std::string _ideas[100];
};

#endif
