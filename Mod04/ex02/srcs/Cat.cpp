#include <Cat.hpp>

Cat::Cat() : AAnimal::AAnimal(), brain(NULL)
{
	type = "Cat";
	brain = new Brain();
	std::cout << "An animal of type Cat was created by default constructor!" << std::endl;
}

Cat::Cat(const Cat &src) : AAnimal(src), brain(NULL)
{
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
	brain = new Brain(*src.brain);
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
