/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:28:25 by mjuin             #+#    #+#             */
/*   Updated: 2023/02/24 15:26:54 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <sstream>
#include <iomanip> 

std::string Get_line(std::string Prompt)
{
	std::string ret;

	if (std::cin.eof())
		return ("");
	while (ret.empty())
	{
		std::cout << Prompt;
		getline(std::cin, ret);
		if (ret.empty() && std::cin.eof())
			return ("");
		else if (ret.empty())
			std::cout << "Please write something !" << std::endl;
	}
	return (ret);
}

Contact	CreateNewContact()
{
	Contact		newContact;
	std::string	First = Get_line("First name : ");
	std::string	Last = Get_line("Last name : ");
	std::string	Nick = Get_line("Nickname : ");
	std::string	Phone = Get_line("Phone number : ");
	std::string	Secret = Get_line("Darkest secret : ");
	if (First.empty() || Last.empty() || Nick.empty() || Phone.empty() || Secret.empty())
	{
		First = "";
		Last = "";
		Nick = "";
		Phone = "";
		Secret = "";
	}
	newContact = Contact(First, Last, Nick, Phone, Secret);
	return(newContact);
}

void	PrintLine(Contact contact, int index)
{
	std::string printed;
	
	printed = contact.get_first();
	if (printed.empty())
		return ;
	std::cout << "| " << std::setw(10) << index << " | ";
	if (printed.length() > 10)
		std::cout << printed.substr(0, 9) << ". | ";
	else
		std::cout << std::setw(10) << printed << " | ";
	printed = contact.get_last();
	if (printed.length() > 10)
		std::cout << printed.substr(0, 9) << ". | ";
	else
		std::cout << std::setw(10) << printed << " | ";
	printed = contact.get_nick();
	if (printed.length() > 10)
		std::cout << printed.substr(0, 9) << "." << " |";
	else
		std::cout << std::setw(10) << printed << " |";
	std::cout << std::endl;
}

void	PrintContact(PhoneBook book)
{
	std::string input;
	int			index;
	Contact		contact;

	if (std::cin.eof())
		return ;
	input = Get_line("Please, enter an index : ");
	if (input.empty() && std::cin.eof())
		return ;
	std::stringstream ss(input);
	ss >> index;
	if (index < 1 || index > 8)
	{
		std::cout << "Not a valid index." << std::endl;
		return ;
	}
	contact = book.SearchContact(index);
	if (contact.get_first().empty())
	{
		std::cout << "Contact not yet created." << std::endl;
		return ;
	}
	std::cout << "First name : " << contact.get_first() << std::endl;
	std::cout << "Last name : " << contact.get_last() << std::endl;
	std::cout << "Nickname : " << contact.get_nick() << std::endl;
	std::cout << "Phone number : " << contact.get_number() << std::endl;
	std::cout << "Darkest secret : " << contact.get_secret() << std::endl;
}

void	Search(PhoneBook book)
{
	int		pos = 1;
	
	if (book.SearchContact(1).get_first().empty())
	{
		std::cout << "PhoneBook is empty !" << std::endl;
		return ;
	}
	std::cout << "* ―――――――――― * ―――――――――― * ―――――――――― * ―――――――――― *" << std::endl;
	std::cout << "|      Index |      First |       Last |       Nick |" << std::endl;
	std::cout << "* ―――――――――― * ―――――――――― * ―――――――――― * ―――――――――― *" << std::endl;
	while (pos < 9)
	{
		PrintLine(book.SearchContact(pos), pos);
		pos++;
	}
	std::cout << "* ―――――――――― * ―――――――――― * ―――――――――― * ―――――――――― *" << std::endl;
	PrintContact(book);
}

int	main()
{
	std::string input;
	PhoneBook	book;
	Contact		NewContact;
	
	while (!std::cin.eof())
	{
		std::cout << "Enter a command : ";
		getline(std::cin, input);
		if (std::cin.eof() && input.empty())
			break;
		if (input == "ADD")
		{
			NewContact = CreateNewContact();
			if (std::cin.eof() && NewContact.get_first().empty())
				break;
			else if (!NewContact.get_first().empty())
				book.AddContact(NewContact);
		}
		else if (input == "SEARCH")
			Search(book);
		else if (input == "EXIT")
			return (0);
		else if (!std::cin.eof())
			std::cout << "Please enter a valid command." << std::endl;
	}
	std::cout << std::endl <<"CTRL + D pressed, the program will now close." << std::endl;
	return (0);
}