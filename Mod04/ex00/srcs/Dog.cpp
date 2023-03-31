#include <Dog.hpp>

Dog::Dog()
{
	type = "Dog";
	std::cout << "An animal of type Dog was created by default constructor!" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	(*this) = src;
	std::cout << "An animal of type Dog was created by copy constructor!" << std::endl;
}

Dog::~Dog() 
{
	std::cout << "An animal of type Dog was destroyed!" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	if (&src == this)
		return (*this);
	type = src.type;
	std::cout << "An animal of type Dog was created by copy assignement constructor!" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Waouf" << std::endl; 
}