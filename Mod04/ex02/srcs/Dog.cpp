#include <Dog.hpp>

Dog::Dog() : AAnimal::AAnimal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "An animal of type Dog was created by default constructor!" << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal(src)
{
	type = src.type;
	brain = new Brain(*src.brain);
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
	delete (brain);
	brain = src.brain;
	std::cout << "An animal of type Dog was created by copy assignement constructor!" << std::endl;
	return (*this);
}

void Dog::makeSound()
{
	std::cout << "Wouf!" << std::endl;
}
