#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "Undefined";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
		return (*this);
	return(*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream tree;
	this->checkExecCondition(executor);
	std::string file = _target + "_shrubbery";
	tree.open(file.c_str());
	tree << "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n";
	tree.close();
}
