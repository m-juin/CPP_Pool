#ifndef CAT_HPP
#define CAT_HPP

#include <AAnimal.hpp>
#include <Brain.hpp>

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat &src);
		~Cat();
		Cat &operator=(const Cat&);
		void makeSound();
	private:
		Brain *brain;
};

#endif