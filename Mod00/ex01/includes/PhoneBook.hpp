/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:28:06 by mjuin             #+#    #+#             */
/*   Updated: 2023/02/23 16:21:13 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <Contact.hpp>

class PhoneBook 
{
    public:
		PhoneBook();
		~PhoneBook();
		void AddContact(Contact contact);
		Contact SearchContact(int index);
    private:
		Contact contact_list[8];
		int		cur_index;
};

#endif