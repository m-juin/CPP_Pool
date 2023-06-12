/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:48:11 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/05 09:57:34 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T c = b;
	b = a;
	a = c;
}
template <typename T>
T	min(T &a, T &b)
{
	return (a < b ? a : b);
}
template <typename T>
T	max(T &a, T &b)
{
	return (a > b ? a : b);
}
#endif