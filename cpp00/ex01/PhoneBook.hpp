/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:56:05 by djanusz           #+#    #+#             */
/*   Updated: 2023/09/18 14:49:36 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		static int	nbcontact;

		void		add(void);
		void		search(void);
		Contact		*get_contactlist(void);
	private:
		Contact		_contactlist[8];
};

#endif
