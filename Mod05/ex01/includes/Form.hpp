/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:15:29 by mjuin             #+#    #+#             */
/*   Updated: 2023/05/30 14:13:13 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;
	public:
		Form();
		Form(const std::string name, const int sign, const int exec);
		Form(const Form&src);
		~Form();
		Form		&operator=(const Form&);
		std::string	getName()		const;
		bool		getStatus()		const;
		int			getSignGrade()	const;
		int			getExecGrade()	const;
		void		beSigned(Bureaucrat signatory);

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

std::ostream	&operator<<(std::ostream& os, const Form& f);

#endif