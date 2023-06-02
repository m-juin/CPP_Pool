/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:24:17 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/02 12:45:06 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include  <stdint.h>
#include "iostream"

struct Data
{
	Data();
	std::string value;
};

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer&src);
		~Serializer();
		Serializer &operator=(const Serializer&);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		
};

#endif