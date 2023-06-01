#include <Ice.hpp>

Ice::Ice() : AMateria::AMateria("ice")
{
	_type = ("ice");
	//std::cout << "An ice materia was created with default constructor!" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria::AMateria(src)
{
	_type = src._type;
	//std::cout << "An ice materia was created with copy constructor!" << std::endl;
}

Ice::~Ice()
{
	//std::cout << "An ice materia was destroyed!" << std::endl;
}

Ice &Ice::operator=(const Ice &src)
{
	if (&src == this)
		return (*this);
	_type = src._type;
	//std::cout << "An ice materia was created with copy assignement constructor!" << std::endl;
	return (*this);
}

Ice *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bold at " << target.getName() << " *" << std::endl;
}
