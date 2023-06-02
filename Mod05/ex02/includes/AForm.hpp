/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:15:29 by mjuin             #+#    #+#             */
/*   Updated: 2023/06/02 14:16:21 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;
	public:
		AForm();
		AForm(const std::string name, const int sign, const int exec);
		AForm(const AForm&src);
		virtual 		~AForm();
		AForm			&operator=(const AForm&);
		std::string		getName()		const;
		bool			getStatus()		const;
		int				getSignGrade()	const;
		int				getExecGrade()	const;
		void			beSigned(Bureaucrat signatory);
		void 			checkExecCondition(Bureaucrat signatory) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
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
		class AlreadySignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream& os, const AForm& f);

#endif