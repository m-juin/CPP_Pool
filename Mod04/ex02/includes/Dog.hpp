#ifndef DOG_HPP
#define DOG_HPP

#include <AAnimal.hpp>
#include <Brain.hpp>

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(const Dog&src);
		~Dog();
		Dog &operator=(const Dog&);
		void makeSound();
	private:
		Brain *brain;
};

#endif