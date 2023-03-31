#include <Cat.hpp>

Cat::Cat() : Animal::Animal()
{
	type = "Cat";
	std::cout << "An animal of type Cat was created by default constructor!" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	type = src.type;
	std::cout << "An animal of type Cat was created by copy constructor!" << std::endl;
}

Cat::~Cat() 
{
	std::cout << "An animal of type Cat was destroyed!" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	if (&src == this)
		return (*this);
	type = src.type;
	std::cout << "An animal of type Cat was created by copy assignement constructor!" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl; 
}
