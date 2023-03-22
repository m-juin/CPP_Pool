
#include <ClapTrap.hpp>

int main( void ) 
{
	ClapTrap Bob("Bob");
	ClapTrap Bib("Bib");

	Bib.attack("Bob");
	Bob.takeDamage(5);
	Bob.beRepaired(5);
	Bib.attack("Bob");
	Bob.takeDamage(10);
	Bob.beRepaired(5);
	ClapTrap Baba(Bob);
	Baba.beRepaired(1);
	for (size_t i = 0; i < 9; i++)
	{
		Bib.attack("Baba");
	}
}