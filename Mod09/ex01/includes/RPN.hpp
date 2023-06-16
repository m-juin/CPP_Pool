/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:57:30 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/16 14:10:04 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack> 
#include <iostream>

class RPN
{
	public:
		RPN();
		~RPN();
		bool calculate(std::string data);
		int		getTop();
	private:
		RPN(const RPN&src);
		RPN &operator=(const RPN&);
		std::stack<int> _value;
};

#endif