/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:09:38 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/02 14:17:27 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CPP
#define INTERN_CPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern&src);
		~Intern();
		Intern &operator=(const Intern&);
		AForm  *makeForm(std::string form_name, std::string form_target);
	private:
		AForm	*makePres(std::string target);
		AForm	*makeRobot(std::string target);
		AForm	*makeShrub(std::string target);
};

typedef AForm *(Intern::*functionPtr)(std::string target);

#endif