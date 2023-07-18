/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:53:49 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/29 10:19:21 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
enum	e_type { INT, DOUBLE, FLOAT, CHAR, INVALID };

class ScalarConverter
{
	public:
		static void convert(std::string src);
		~ScalarConverter();
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		static e_type getType(std::string src);
		static bool isFloat(std::string src);
		static bool isInt(std::string src);
		static bool isDouble(std::string src);
		static bool isChar(std::string src);
		static e_type isPseudo(std::string src);
};

#endif