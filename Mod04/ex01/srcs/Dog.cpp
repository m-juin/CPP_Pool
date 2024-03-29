#include <Dog.hpp>

Dog::Dog() : Animal::Animal(), brain(NULL)
{
	type = "Dog";
	brain = new Brain();
	std::cout << "An animal of type Dog was created by default constructor!" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src), brain(NULL)
{
	(*this) = src;
	std::cout << "An animal of type Dog was created by copy constructor!" << std::endl;
}

Dog::~Dog() 
{
	delete (brain);
	std::cout << "An animal of type Dog was destroyed!" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	if (&src == this)
		return (*this);
	type = src.type;
	brain = new Brain(*src.brain);
	std::cout << "An animal of type Dog was created by copy assignement constructor!" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Waouf" << std::endl; 
}

void Dog::getIdea(const int index) const
{
	std::cout << "this dog " << index << " idea is : " << (this->brain->getIdea(index)) << std::endl;
}
