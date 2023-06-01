
#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>
#include <cstdlib>

int main()
{
	const Animal* k = new Animal();
	const Dog* j = new Dog();
	const Cat* i = new Cat();
	const Dog* j_copy = new Dog(*j);
	const Cat* i_copy = new Cat(*i);

	std::cout << std::endl;

	k->getIdea();
	j->getIdea(rand() % 100);
	i->getIdea(rand() % 100);

	std::cout << std::endl;

	delete k;
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;
	j_copy->getIdea(rand() % 100);
	i_copy->getIdea(rand() % 100);

	delete j_copy;//should not create a leak
	delete i_copy;
	return 0;
}