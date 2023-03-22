
#include <Cat.hpp>
#include <Dog.hpp>
#include <WrongCat.hpp>

int main( void ) 
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	const Animal *toto = new Animal();
	const Animal *tata = new Cat();
	const Dog *titi = new Dog();
	const Animal *tutu = new Dog(*titi);

	std::cout << i->getType() << " " << std::endl;
	std::cout << tata->getType() << " " << std::endl;
	std::cout << titi->getType() << " " << std::endl;

	i->makeSound();
	meta->makeSound();
	toto->makeSound();
	tata->makeSound();
	titi->makeSound();
	tutu->makeSound();

	delete (meta);
	delete (i);
	delete (toto);
	delete (tata);
	delete (titi);
	delete (tutu);
	return 0;
}