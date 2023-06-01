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
		virtual void makeSound() const = 0;
		virtual void getIdea() const;
		std::string type;
};

#endif