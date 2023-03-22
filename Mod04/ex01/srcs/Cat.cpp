#include <Cat.hpp>

Cat::Cat() : Animal::Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "An animal of type Cat was created by default constructor!" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	type = src.type;
	brain = new Brain(*src.brain);
	std::cout << "An animal of type Cat was created by copy constructor!" << std::endl;
}

Cat::~Cat() 
{
	delete (brain);
	std::cout << "An animal of type Cat was destroyed!" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	if (&src == this)
		return (*this);
	type = src.type;
	delete (brain);
	brain = src.brain;
	std::cout << "An animal of type Cat was created by copy assignement constructor!" << std::endl;
	return (*this);
}
