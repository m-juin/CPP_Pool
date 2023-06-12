/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:48:11 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/07 12:17:27 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

template <typename T>
void	easyfind(T container, int searched)
{
	int index = 0;

	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		const int& element = static_cast<int&>(*it);
		if (element == searched)
		{
			std::cout << "First occurence of int " << searched << " found at index " << index << std::endl;
			return ;
		}
		index++;
	}
	std::cerr << "int " << searched << " not found !" << std::endl;
}
#endif