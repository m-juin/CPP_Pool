#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	_target = "Undefined";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return (*this);
	return(*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->checkExecCondition(executor);
	std::cout << "ZZZZZzzzzzzzzzzzzzZZZZZZZZZZZZZz" << std::endl;
	if (std::rand() % 2 == 1)
		std::cout << _target << " was succesfully robotomized" << std::endl;
	else
		std::cout << _target << " robotomy failed" << std::endl;
}
