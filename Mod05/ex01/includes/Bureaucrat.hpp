/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:10:42 by mjuin             #+#    #+#             */
/*   Updated: 2023/05/30 14:13:37 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string new_name, int new_grade);
		Bureaucrat(const Bureaucrat&src);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat&);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form *form);
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& b);

#endif