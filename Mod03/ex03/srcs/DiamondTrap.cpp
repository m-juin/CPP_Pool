#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	Name = name;
	ClapTrap::Name += "_clap_name";
	std::cout << Name << " was created with DiamondTrap default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) :ClapTrap(src), FragTrap(src), ScavTrap(src)
{

	this->Name = src.Name;
	std::cout << Name << " was created with DiamondTrap copy constructor" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << Name << " was destroyed with DiamondTrap destructor!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	if (&src == this)
		return (*this);
	this->Name = src.Name;
	std::cout << this->Name << " was created with DiamondTrap copy assignement constructor!" << std::endl;
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name = " << this->Name << std::endl << "ClapTrap name = " << ClapTrap::Name << std::endl;
}
