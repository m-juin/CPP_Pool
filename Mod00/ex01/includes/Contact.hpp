/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:28:08 by mjuin             #+#    #+#             */
/*   Updated: 2023/02/23 15:58:27 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	public:
		Contact();
		Contact(std::string first, std::string last, std::string nick, std::string number, std::string secret);
		std::string get_first();
		std::string get_last();
		std::string get_nick();
		std::string get_number();
		std::string get_secret();
	private:
		int index;
		std::string first_name;
		std::string	last_name;
		std::string nickname;
		std::string number;
		std::string secret;
};

#endif