#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal&src);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal&);
		std::string getType() const;
		void makeSound() const;
	protected:
		std::string type;
};

#endif