#include <WrongCat.hpp>

WrongCat::WrongCat() : WrongAnimal::WrongAnimal()
{
	type = "WrongCat";
	std::cout << "An animal of type WrongCat was created by default constructor!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	(*this) = src;
	std::cout << "An animal of type WrongCat was created by copy constructor!" << std::endl;
}

WrongCat::~WrongCat() 
{
	std::cout << "An animal of type WrongCat was destroyed!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	if (&src == this)
		return (*this);
	type = src.type;
	std::cout << "An animal of type WrongCat was created by copy assignement constructor!" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
