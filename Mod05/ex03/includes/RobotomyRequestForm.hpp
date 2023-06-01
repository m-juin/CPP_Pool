/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:51:43 by mjuin             #+#    #+#             */
/*   Updated: 2023/05/30 16:13:46 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cmath>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm&src);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm&);
		void	execute(Bureaucrat const & executor) const;
	private:
		std::string	_target;
};

#endif