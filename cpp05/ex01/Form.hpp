/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:16:57 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/30 12:23:07 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form const& src);
		Form& operator=(Form const& src);
		~Form(void);

		std::string get_name(void) const;
		bool get_signed(void) const;
		int get_gradeToSign(void) const;
		int get_gradeToExecute(void) const;

		void beSigned(Bureaucrat Bureaucrat);

		class GradeTooHightException: std::exception
		{
			public:
				char const* what() const throw() { return ("Grade too hight"); }
		};
		class GradeTooLowException: std::exception
		{
			public:
				char const* what() const throw() { return ("Grade too low"); }
		};

	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
};

std::ostream& operator<<(std::ostream& o, Form const& src);

#endif
