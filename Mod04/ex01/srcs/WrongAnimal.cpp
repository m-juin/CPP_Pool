#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal()
{
	std::cout << "An WrongAnimal was created by default constructor!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	type = src.type;
	std::cout << "An WrongAnimal was created by copy constructor!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	if (type.empty() == 0)
		std::cout << "A not typed WrongAnimal was destroyed!" << std::endl;
	else
		std::cout << "A " << type << " WrongAnimal was destroyed!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	if (&src == this)
		return (*this);
	type = src.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	if (type.empty() == 1)
		std::cout << "<<___>>" << std::endl;
	else if (type == "WrongCat")
		std::cout << "Grout!" << std::endl;
}
