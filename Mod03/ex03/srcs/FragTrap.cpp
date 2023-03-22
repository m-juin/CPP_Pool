#include <FragTrap.hpp>

FragTrap::FragTrap() : ClapTrap()
{
	this->HitPoints = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
	std::cout << "void" << " was created with FragTrap default constructor!" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	this->Name = Name;
	this->HitPoints = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
	std::cout << Name << " was created with FragTrap default constructor!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	this->Name = src.Name;
	this->HitPoints = src.HitPoints;
	this->EnergyPoint = src.EnergyPoint;
	this->AttackDamage = src.AttackDamage;
	std::cout << this->Name << " was created with FragTrap copy constructor!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->Name << " was destroyed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	if (&src == this)
		return (*this);
	this->Name = src.Name;
	this->HitPoints = src.HitPoints;
	this->EnergyPoint = src.EnergyPoint;
	this->AttackDamage = src.AttackDamage;
	std::cout << this->Name << " was created with FragTrap copy assignement constructor!" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if (EnergyPoint == 0)
	{
		std::cout << "FragTrap " << this->Name << " doesn't have enough energy to high fives!" << std::endl;
		return ;
	}
	else if (HitPoints == 0)
	{
		std::cout << "FragTrap " << this->Name << " his dead!" << std::endl;
		return ;
	}
	std::cout << this->Name << " high fives!" << std::endl;
}
