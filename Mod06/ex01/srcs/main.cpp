/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:36:24 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/23 14:21:55 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
	Data *data = new Data();
	Serializer toto();
	uintptr_t	ptr;
	data->value = "Hello";
	std:: cout << "Data value before conversion = " << data->value << std::endl;
	std:: cout << "Data Address before conversion = " << data << std::endl;
	ptr = Serializer::serialize(data);
	data = NULL;
	std:: cout << "Data Address during conversion = " << data << std::endl;
	data = Serializer::deserialize(ptr);
	std:: cout << "Data value after conversion = " << data->value << std::endl;
	std:: cout << "Data Address after conversion = " << data << std::endl;
	delete(data);
}