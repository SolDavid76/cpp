/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:14:11 by djanusz           #+#    #+#             */
/*   Updated: 2023/09/21 15:19:51 by djanusz          ###   ########.fr       */
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
		std::string	get_lastname(void);
		std::string	get_nickname(void);
		std::string	get_phone(void);
		std::string	get_secret(void);

		void		set_firstname(std::string str);
		void		set_lastname(std::string str);
		void		set_nickname(std::string str);
		void		set_phone(std::string str);
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
