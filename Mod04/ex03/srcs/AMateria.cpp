#include <AMateria.hpp>

AMateria::AMateria(std::string const & type)
{
	_type = type;
	std::cout << "A AMateria of type " << _type << " was created with default constructor!" << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	_type = src._type;
	std::cout << "A AMateria of type " << _type << " was created with copy constructor!" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "A AMateria of type " << _type << " was destroyed!" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (&src == this)
		return (*this);
	_type = src._type;
	std::cout << "A AMateria of type " << _type << " was created with assignement copy constructor!" << std::endl;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
