
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
	k->getIdea();
	j->getIdea(rand() % 100);
	i->getIdea(rand() % 100);
	delete k;
	delete j;//should not create a leak
	delete i;
	j_copy->getIdea(rand() % 100);
	i_copy->getIdea(rand() % 100);
	delete j_copy;//should not create a leak
	delete i_copy;
	return 0;
}