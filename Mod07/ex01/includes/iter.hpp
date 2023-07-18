/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:48:11 by mjuin             #+#    #+#             */
/*   Updated: 2023/07/05 10:11:57 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename F>
void	iter(T *array, unsigned int N, F *f)
{
	if (f == NULL || array == NULL)
		return ;
	for (unsigned int i = 0; i < N; i++)
	{
		try
		{
			f(array[i]);
		}
		catch(const std::exception& e)
		{
			std::cerr << std::endl << "Error : " << e.what() << '\n';
		}
	}
}

#endif