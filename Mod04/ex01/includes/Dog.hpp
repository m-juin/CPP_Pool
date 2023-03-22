#ifndef DOG_HPP
#define DOG_HPP

#include <Animal.hpp>
#include <Brain.hpp>

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog&src);
		~Dog();
		Dog &operator=(const Dog&);
	private:
		Brain *brain;
};

#endif