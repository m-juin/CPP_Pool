/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:18:01 by mjuin             #+#    #+#             */
/*   Updated: 2023/05/30 14:37:47 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void tryBureaucratBase()
{
	try
	{
		Bureaucrat toto("toto", 75);
		std::cout << toto << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
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
		std::cerr << "Exception: " << e.what() << '\n';
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
		std::cerr << "Exception: " << e.what() << '\n';
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
		std::cerr << "Exception: " << e.what() << '\n';
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
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void tryFormBase()
{
	try
	{
		Form BaseForm("BaseForm", 75, 75);
		std::cout << BaseForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void tryFormMax()
{
	try
	{
		Form MaxForm("MaxForm", 150, 150);
		std::cout << MaxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void tryFormMin()
{
	try
	{
		Form MinForm("MinForm", 1, 1);
		std::cout << MinForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void tryFormOverMax()
{
	try
	{
		Form OverMaxForm("OverMaxForm", 151, 151);
		std::cout << OverMaxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void tryFormOverMin()
{
	try
	{
		Form OverMinForm("OverMinForm", 0, 0);
		std::cout << OverMinForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void tryBaseSign()
{
	try
	{
		Bureaucrat toto("toto", 75);
		Form BaseForm("A Base Form", 76, 76);
		toto.signForm(&BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void tryEqualSign()
{
	try
	{
		Bureaucrat toto("toto", 75);
		Form BaseForm("A Equal Form", 75, 75);
		toto.signForm(&BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void tryOverSign()
{
	try
	{
		Bureaucrat toto("toto", 75);
		Form BaseForm("A Great Form", 74, 74);
		toto.signForm(&BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}

void trydoubleSign()
{
	try
	{
		Bureaucrat toto("toto", 75);
		Form BaseForm("A Great Form", 76, 76);
		toto.signForm(&BaseForm);
		toto.signForm(&BaseForm);
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
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
	std::cout << std::endl << "###	FORM BASE TEST	###" << std::endl << std::endl;
	tryFormBase();
	tryFormMin();
	tryFormMax();
	tryFormOverMin();
	tryFormOverMax();
	std::cout << std::endl << "###	FORM ADVANCED TEST	###" << std::endl << std::endl;
	tryBaseSign();
	tryEqualSign();
	tryOverSign();
	trydoubleSign();
}