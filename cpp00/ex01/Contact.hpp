/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:14:11 by djanusz           #+#    #+#             */
/*   Updated: 2023/09/18 14:48:24 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
# include "main.hpp"

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		std::string	get_firstname(void);
		void		set_firstname(std::string str);
		std::string	get_lastname(void);
		void		set_lastname(std::string str);
		std::string	get_nickname(void);
		void		set_nickname(std::string str);
		std::string	get_phone(void);
		void		set_phone(std::string str);
		std::string	get_secret(void);
		void		set_secret(std::string str);

		void		fill_infos(void);
		void		search(void);
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phone;
		std::string	_secret;
};

#endif
