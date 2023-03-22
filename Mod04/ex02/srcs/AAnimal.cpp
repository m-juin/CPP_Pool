#include <AAnimal.hpp>

AAnimal::AAnimal()
{
	std::cout << "An animal was created by default constructor!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	type = src.type;
	std::cout << "An animal was created by copy constructor!" << std::endl;
}

AAnimal::~AAnimal()
{
	if (type.empty() == 0)
		std::cout << "A not typed animal was destroyed!" << std::endl;
	else
		std::cout << "A " << type << " animal was destroyed!" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	if (&src == this)
		return (*this);
	type = src.type;
	return (*this);
}

std::string AAnimal::getType() const
{
	return (type);
}
