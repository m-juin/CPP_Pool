#ifndef CAT_HPP
#define CAT_HPP

#include <Animal.hpp>
#include <Brain.hpp>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &src);
		~Cat();
		Cat &operator=(const Cat&);
		void makeSound() const;
		virtual void getIdea(const int index) const;
	private:
		Brain *brain;
};

#endif