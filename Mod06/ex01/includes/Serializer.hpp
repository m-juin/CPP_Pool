/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:24:17 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/23 14:28:53 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include  <stdint.h>
#include <iostream>

struct Data
{
	Data();
	std::string value;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer&src);
		~Serializer();
		Serializer &operator=(const Serializer&);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif