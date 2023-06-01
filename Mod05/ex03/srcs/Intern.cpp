#include <Intern.hpp>

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &src)
{
	if (&src == this)
		return (*this);
	return (*this);
}

AForm *Intern::makeForm(std::string form_name, std::string form_target)
{
	int	index;
	std::string formNameArray[3] = { "ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm" };
	functionPtr functionArray[3] = { &Intern::makeShrub, &Intern::makeRobot, &Intern::makePres };
	AForm	*formptr;

	for (index = 0; index < 3; index++)
	{
		if (formNameArray[index] == form_name)
			break;
	}
	if (index == 3)
	{
		std::cerr << "There is no form named " << form_name << std::endl;
		return (NULL);
	}
	formptr = (this->*functionArray[index])(form_target);
	return(formptr);

}

AForm *Intern::makePres(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobot(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrub(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
