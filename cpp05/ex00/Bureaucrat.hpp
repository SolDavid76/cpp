/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:17:04 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/27 00:17:05 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& src);
		Bureaucrat& operator=(Bureaucrat const& src);
		~Bureaucrat(void);

		std::string get_name(void) const;
		int get_grade(void) const;

		void promote(void);
		void demote(void);

		class GradeTooHightException: public std::exception
		{
			public:
				const char* what() const throw() { return ("Grade too hight"); }
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw() { return ("Grade too low"); }
		};
	private:
		std::string const _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& src);

#endif
