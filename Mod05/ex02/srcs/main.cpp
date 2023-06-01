/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:18:01 by mjuin             #+#    #+#             */
/*   Updated: 2023/05/31 13:51:57 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

void tryBureaucratBase()
{
	try
	{
		Bureaucrat *toto = new Bureaucrat("toto", 75);
		std::cout << toto << std::endl;
		delete(toto);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void tryBureaucratMax()
{
	try
	{
		Bureaucrat toto("toto", 1);
		std::cout << toto << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void tryBureaucratMin()
{
	try
	{
		Bureaucrat toto("toto", 150);
		std::cout << toto << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void tryBureaucratOverMax()
{
	try
	{
		Bureaucrat toto("toto", 0);
		std::cout << toto << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void tryBureaucratOverMin()
{
	try
	{
		Bureaucrat toto("toto", 151);
		std::cout << toto << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void tryValidRobotomy()
{
	Bureaucrat toto("toto", 15);
	AForm *BaseForm = new RobotomyRequestForm();
	try
	{
		toto.signForm(BaseForm);
		toto.executeForm(*BaseForm);
		std::cout << std::endl;
		delete(BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
		delete(BaseForm);
	}
}

void tryNotSignedRobotomy()
{
	Bureaucrat toto("toto", 15);
	AForm *BaseForm = new RobotomyRequestForm();
	try
	{
		toto.executeForm(*BaseForm);
		std::cout << std::endl;
		delete(BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
		delete(BaseForm);
	}
}

void tryNotGoodGradeSignRobotomy()
{
	Bureaucrat toto("toto", 150);
	AForm *BaseForm = new RobotomyRequestForm();
	try
	{
		toto.signForm(BaseForm);
		std::cout << std::endl;
		delete(BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
		delete(BaseForm);
	}
}

void tryNotGoodGradeExecRobotomy()
{
	Bureaucrat toto("toto", 70);
	AForm *BaseForm = new RobotomyRequestForm();
	try
	{
		toto.signForm(BaseForm);
		toto.executeForm(*BaseForm);
		delete(BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n";
		delete(BaseForm);
	}
}

void tryValidPresidential()
{
	Bureaucrat toto("toto", 1);
	AForm *BaseForm = new PresidentialPardonForm("George");
	try
	{
		toto.signForm(BaseForm);
		toto.executeForm(*BaseForm);
		std::cout << std::endl;
		delete(BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
		delete(BaseForm);
	}
}

void tryNotSignedPresidential()
{
	Bureaucrat toto("toto", 1);
	AForm *BaseForm = new PresidentialPardonForm("");
	try
	{
		toto.executeForm(*BaseForm);
		std::cout << std::endl;
		delete(BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
		delete(BaseForm);
	}
}

void tryNotGoodGradeSignPresidential()
{
	Bureaucrat toto("toto", 150);
	AForm *BaseForm = new PresidentialPardonForm();
	try
	{
		toto.signForm(BaseForm);
		std::cout << std::endl;
		delete(BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
		delete(BaseForm);
	}
}

void tryNotGoodGradeExecPresidential()
{
	Bureaucrat toto("toto", 6);
	AForm *BaseForm = new PresidentialPardonForm();
	try
	{
		toto.signForm(BaseForm);
		toto.executeForm(*BaseForm);
		delete(BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n";
		delete(BaseForm);
	}
}

void tryValidShrubbery()
{
	Bureaucrat toto("toto", 1);
	AForm *BaseForm = new ShrubberyCreationForm("");
	try
	{
		toto.signForm(BaseForm);
		toto.executeForm(*BaseForm);
		std::cout << std::endl;
		delete(BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
		delete(BaseForm);
	}
}

void tryNotSignedShrubbery()
{
	Bureaucrat toto("toto", 1);
	AForm *BaseForm = new ShrubberyCreationForm("");
	try
	{
		toto.executeForm(*BaseForm);
		std::cout << std::endl;
		delete(BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
		delete(BaseForm);
	}
}

void tryNotGoodGradeSignShrubbery()
{
	Bureaucrat toto("toto", 150);
	AForm *BaseForm = new ShrubberyCreationForm();
	try
	{
		toto.signForm(BaseForm);
		std::cout << std::endl;
		delete(BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
		delete(BaseForm);
	}
}

void tryNotGoodGradeExecShrubbery()
{
	Bureaucrat toto("toto", 144);
	AForm *BaseForm = new ShrubberyCreationForm();
	try
	{
		toto.signForm(BaseForm);
		toto.executeForm(*BaseForm);
		delete(BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << "\n";
		delete(BaseForm);
	}
}

int main()
{
	std::cout << "###	BUREAUCRAT BASE TEST	###" << std::endl << std::endl;
	tryBureaucratBase();
	tryBureaucratMin();
	tryBureaucratMax();
	tryBureaucratOverMin();
	tryBureaucratOverMax();
	std::cout << std::endl << "###	ROBOTOMY TEST	###" << std::endl << std::endl;
	std::srand((unsigned) time(0));
	tryValidRobotomy();
	tryNotSignedRobotomy();
	tryNotGoodGradeSignRobotomy();
	tryNotGoodGradeExecRobotomy();
	std::cout << std::endl << "###	Shrubbery TEST	###" << std::endl << std::endl;
	tryValidShrubbery();
	tryNotSignedShrubbery();
	tryNotGoodGradeSignShrubbery();
	tryNotGoodGradeExecShrubbery();
	std::cout << std::endl << "###	Presidential TEST	###" << std::endl << std::endl;
	tryValidPresidential();
	tryNotSignedPresidential();
	tryNotGoodGradeSignPresidential();
	tryNotGoodGradeExecPresidential();
}