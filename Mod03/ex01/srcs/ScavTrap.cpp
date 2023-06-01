#include <ScavTrap.hpp>

ScavTrap::ScavTrap() : ClapTrap()
{
	this->Name = "";
	this->HitPoints = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
	std::cout << "An unknown was created with ScavTrap default constructor!" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	this->Name = Name;
	this->HitPoints = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
	std::cout << Name << " was created with ScavTrap default constructor!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	*this = src;
	std::cout << this->Name << " was created with ScavTrap copy constructor!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->Name << " was destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (this == &src)
		return (*this);
	this->Name = src.Name;
	this->HitPoints = src.HitPoints;
	this->EnergyPoint = src.EnergyPoint;
	this->AttackDamage = src.AttackDamage;
	std::cout << this->Name << " was created with ScavTrap copy assignement constructor!" << std::endl;
	return (*this);
}

void ScavTrap::guardGate()
{
	if (EnergyPoint == 0)
	{
		std::cout << "ScavTrap " << this->Name << " doesn't have enough energy to enter guard mode!" << std::endl;
		return ;
	}
	else if (HitPoints == 0)
	{
		std::cout << "ScavTrap " << this->Name << " his dead!" << std::endl;
		return ;
	}
	std::cout << this->Name << " entered in guard mode!" << std::endl;
	EnergyPoint--;
}

void ScavTrap::attack(const std::string &target)
{
	if (EnergyPoint == 0)
	{
		std::cout << "ScavTrap " << this->Name << " doesn't have enough energy to attack!" << std::endl;
		return ;
	}
	else if (HitPoints == 0)
	{
		std::cout << "ScavTrap " << this->Name << " his dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->Name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
	this->EnergyPoint--;
}
