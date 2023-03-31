
#include <FragTrap.hpp>

int main( void ) 
{
	ClapTrap Bob("Bob");
	ClapTrap Bib("Bib");

	Bib.attack("Bob");
	Bob.takeDamage(0);
	Bob.beRepaired(5);
	Bib.attack("Bob");
	Bob.takeDamage(10);
	Bob.beRepaired(5);
	ClapTrap Baba(Bob);
	Baba.beRepaired(1);

	FragTrap toto("toto");
	toto.highFivesGuys();
	Bib.attack("toto");
	toto.takeDamage(5);
	toto.beRepaired(5);
	Bib.attack("toto");
	toto.takeDamage(15);
	toto.attack("bib");
	Bib.takeDamage(20);
	Bib.beRepaired(5);
	toto.highFivesGuys();
}