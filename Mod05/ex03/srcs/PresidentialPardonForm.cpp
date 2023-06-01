#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	_target = "Undefined";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this == &src)
		return (*this);
	return(*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkExecCondition(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
