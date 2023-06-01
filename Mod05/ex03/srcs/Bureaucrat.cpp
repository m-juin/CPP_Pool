/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:19:00 by mjuin             #+#    #+#             */
/*   Updated: 2023/05/31 13:49:42 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string new_name, int new_grade) : name(new_name)
{
	if (new_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (new_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = new_grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name), grade(src.grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (&src == this)
		return (*this);
	this->grade = src.grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

void Bureaucrat::signForm(AForm *form)
{
	try
	{
		form->beSigned(*this);
		std::cout << this->getName() << " signed \"" << form->getName() << "\"" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn\'t sign \"" << form->getName() << "\" because " << e.what() << std::endl;
	}
	
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed \"" << form.getName() << "\"" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn\'t execute \"" << form.getName() << "\" because " << e.what() << std::endl;
	}
}	

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Maximun grade is 1");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Minimun grade is 150");
}