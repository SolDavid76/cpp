/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 00:16:14 by djanusz           #+#    #+#             */
/*   Updated: 2023/10/30 15:15:50 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm const& src);
		AForm& operator=(AForm const& src);
		virtual ~AForm(void);

		std::string get_name(void) const;
		bool get_signed(void) const;
		int get_gradeToSign(void) const;
		int get_gradeToExecute(void) const;

		void beSigned(Bureaucrat Bureaucrat);

		virtual void execute(Bureaucrat const& executor) const = 0;

		class NotSignedException: public std::exception
		{
			public:
				char const* what() const throw() { return ("Form is not signed"); }
		};
		class GradeTooHightException: public std::exception
		{
			public:
				char const* what() const throw() { return ("Grade too hight"); }
		};
		class GradeTooLowException: public std::exception
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

std::ostream& operator<<(std::ostream& o, AForm const& src);

#endif
