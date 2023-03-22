/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:17 by mjuin             #+#    #+#             */
/*   Updated: 2023/02/28 13:47:31 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str Address = " << &str << std::endl;
	std::cout << "stringPTR Address = " << stringPTR << std::endl;
	std::cout << "stringREF Address = " << &stringREF << std::endl;

	std::cout << "str value = " << str << std::endl;
	std::cout << "stringPTR Address = " << *stringPTR << std::endl;
	std::cout << "stringREF Address = " << stringREF << std::endl;
}