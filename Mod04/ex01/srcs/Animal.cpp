#include <Animal.hpp>

Animal::Animal()
{
	std::cout << "An animal was created by default constructor!" << std::endl;
}

Animal::Animal(const Animal &src)
{
	(*this) = src;
	std::cout << "An animal was created by copy constructor!" << std::endl;
}

Animal::~Animal()
{
	if (type.empty() == 0)
		std::cout << "A not typed animal was destroyed!" << std::endl;
	else
		std::cout << "A " << type << " animal was destroyed!" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	if (&src == this)
		return (*this);
	type = src.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << ">>___<<" << std::endl;
}

void Animal::getIdea() const
{
	std::cout << "this is a basic animal, he doesn't have a brain" << std::endl;
}
