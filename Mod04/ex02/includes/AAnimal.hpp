#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
	public:
		virtual ~AAnimal();
	protected:
		AAnimal();
		AAnimal(const AAnimal&src);
		AAnimal &operator=(const AAnimal&);
		std::string getType() const;
		virtual void makeSound() = 0;
		std::string type;
};

#endif