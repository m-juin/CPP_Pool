#include <Cure.hpp>

Cure::Cure() : AMateria::AMateria("cure")
{
	_type = ("cure");
	std::cout << "An cure materia was created with default constructor!" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria::AMateria(src)
{
	_type = src._type;
	std::cout << "An cure materia was created with copy constructor!" << std::endl;
}

Cure::~Cure()
{
	std::cout << "An cure materia was destroyed!" << std::endl;
}

Cure &Cure::operator=(const Cure &src)
{
	if (&src == this)
		return (*this);
	_type = src._type;
	std::cout << "An cure materia was created with copy assignement constructor!" << std::endl;
	return (*this);
}

Cure *Cure::clone() const 
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
