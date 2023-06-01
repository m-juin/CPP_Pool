#include <AForm.hpp>

AForm::AForm() : _name("Form"), _sign_grade(150), _exec_grade(150)
{
	this->_signed = false;
}

AForm::AForm(const std::string name, const int sign, const int exec) : _name(name), _sign_grade(sign), _exec_grade(exec)
{
	this->_signed = false;
	if (sign < 1 || exec < 1)
		throw AForm::GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : _name(src.getName()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	this->_signed = src.getStatus();
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &src)
{
	if (&src == this)
		return (*this);
	this->_signed = src.getStatus();
	return (*this);
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getStatus() const
{
	return(this->_signed);
}

int AForm::getSignGrade() const
{
	return(this->_sign_grade);
}

int AForm::getExecGrade() const
{
	return(this->_exec_grade);
}

void AForm::beSigned(Bureaucrat signatory)
{
	if (this->_signed == true)
		throw AForm::AlreadySignedException();
	if (signatory.getGrade() > this->_sign_grade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void AForm::checkExecCondition(Bureaucrat signatory) const
{
	if (this->getStatus() == false)
		throw AForm::NotSignedException();
	if (signatory.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "Form name = " << f.getName() << std::endl;
	os << "Form sign grade = " << f.getSignGrade() << std::endl;
	os << "Form exec grade = " << f.getExecGrade() << std::endl;
	if (f.getStatus() == true)
		os << "Form status " << "signed" << std::endl;
	else
		os << "Form status " << "not signed" << std::endl;
	return (os);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return ("Form is already signed");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form wasn't signed");
}
