
#include <ScavTrap.hpp>

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

	ScavTrap toto("toto");
	toto.guardGate();
	Bib.attack("toto");
	toto.takeDamage(5);
	toto.beRepaired(5);
	Bib.attack("toto");
	toto.takeDamage(15);
	toto.attack("bib");
	Bib.takeDamage(20);
	Bib.beRepaired(5);
	for (size_t i = 0; i < 50; i++)
	{
		toto.attack("bib");
	}
	
}