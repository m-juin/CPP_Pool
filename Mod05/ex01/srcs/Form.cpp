#include <Form.hpp>

Form::Form() : _name("Form"), _sign_grade(150), _exec_grade(150)
{
	this->_signed = false;
}

Form::Form(const std::string name, const int sign, const int exec) : _name(name), _sign_grade(sign), _exec_grade(exec)
{
	this->_signed = false;
	if (sign < 1 || exec < 1)
		throw Form::GradeTooHighException();
	else if (sign > 150 || exec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : _name(src.getName()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	this->_signed = src.getStatus();
}

Form::~Form()
{
}

Form &Form::operator=(const Form &src)
{
	if (&src == this)
		return (*this);
	this->_signed = src.getStatus();
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getStatus() const
{
	return(this->_signed);
}

int Form::getSignGrade() const
{
	return(this->_sign_grade);
}

int Form::getExecGrade() const
{
	return(this->_exec_grade);
}

void Form::beSigned(Bureaucrat signatory)
{
	if (signatory.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
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

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}
