
#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>
#include <cstdlib>

int main()
{
	//const AAnimal* k = new AAnimal();
	const Dog* j = new Dog();
	const Cat* i = new Cat();
	const Dog* j_copy = new Dog(*j);
	const Cat* i_copy = new Cat(*i);

	std::cout << std::endl;

	j->getIdea(rand() % 100);
	i->getIdea(rand() % 100);

	std::cout << std::endl;

	delete j;
	delete i;

	std::cout << std::endl;

	j_copy->getIdea(rand() % 100);
	i_copy->getIdea(rand() % 100);

	std::cout << std::endl;

	delete j_copy;
	delete i_copy;
	return 0;
}