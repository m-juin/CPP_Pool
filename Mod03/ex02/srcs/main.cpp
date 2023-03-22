
#include <FragTrap.hpp>

int main( void ) 
{
	ClapTrap Bob("Bob");
	FragTrap Bibo("Bibo");
	FragTrap Biba(Bibo);
	Biba.highFivesGuys();
	Bibo.highFivesGuys();
	Bibo.beRepaired(5);
	Bibo.attack("bob");
}