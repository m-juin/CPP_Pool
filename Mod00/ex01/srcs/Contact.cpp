/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:18:10 by mjuin             #+#    #+#             */
/*   Updated: 2023/02/24 12:33:22 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

Contact::Contact()
{
}

Contact::Contact(std::string first, std::string last, std::string nick, std::string number, std::string secret)
{
	this->first_name = first;
	this->last_name = last;
	this->nickname = nick;
	this->number = number;
	this->secret = secret;
}

std::string Contact::get_first()
{
	return (this->first_name);
}

std::string Contact::get_last()
{
	return (this->last_name);
}

std::string Contact::get_nick()
{
	return (this->nickname);
}

std::string Contact::get_number()
{
	return (this->number);
}

std::string Contact::get_secret()
{
	return (this->secret);
}
