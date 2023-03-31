#include <Cat.hpp>

Cat::Cat() : Animal::Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "An animal of type Cat was created by default constructor!" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	brain = new Brain();
	(*this) = src;
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
	for (size_t i = 0; i < 100; i++)
	{
		this->brain->setIdea(i, "Waouf");
	}
	std::cout << "An animal of type Cat was created by copy assignement constructor!" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl; 
}

void Cat::getIdea(const int index) const
{
	std::cout << "this cat " << index << " idea is : " << (this->brain->getIdea(index)) << std::endl;
}
