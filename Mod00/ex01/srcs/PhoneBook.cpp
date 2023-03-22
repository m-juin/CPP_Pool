/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:18:39 by mjuin             #+#    #+#             */
/*   Updated: 2023/02/24 12:35:50 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

PhoneBook::PhoneBook()
{
	cur_index = 1;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::AddContact(Contact contact)
{
	contact_list[cur_index - 1] = contact;
	cur_index++;
	if (cur_index == 9)
		cur_index = 1;
}

Contact PhoneBook::SearchContact(int index)
{
	return (contact_list[index - 1]);
}
