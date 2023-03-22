#include <ClapTrap.hpp>
#include <iostream>

ClapTrap::ClapTrap()
{
	this->Name = Name;
	HitPoints = 10;
	EnergyPoint = 10;
	AttackDamage = 0;
	std::cout << "void" << " was created with default constructor!" << std::endl;
}

ClapTrap::ClapTrap(std::string Name)
{
	this->Name = Name;
	HitPoints = 10;
	EnergyPoint = 10;
	AttackDamage = 0;
	std::cout << Name << " was created with ClapTrap defaultconstructor!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	this->Name = src.Name;
	this->HitPoints = src.HitPoints;
	this->AttackDamage = src.AttackDamage;
	this->EnergyPoint = src.EnergyPoint;
	std::cout << "Claptrap " << this->Name << " was created with copy constructor!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->Name << " was destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	this->Name = src.Name;
	this->HitPoints = src.HitPoints;
	this->AttackDamage = src.AttackDamage;
	this->EnergyPoint = src.EnergyPoint;
	std::cout << this->Name << " was created with ClapTrap copy assignement constructor!" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (EnergyPoint == 0)
	{
		std::cout << "ClapTrap " << this->Name << " doesn't have enough energy to attack!" << std::endl;
		return ;
	}
	else if (HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << " his dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
	this->EnergyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << "was already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " take " << amount << " damage!" << std::endl;
	HitPoints -= amount;
	if (HitPoints < 0)
		HitPoints = 0;
	if (HitPoints == 0)
		std::cout << "ClapTrap " << this->Name << " died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (EnergyPoint == 0)
	{
		std::cout << "ClapTrap " << this->Name << " doesn't have enough energy to repare!" << std::endl;
		return ;
	}
	else if (HitPoints == 0)
	{
		std::cout << "ClapTrap " << this->Name << " his dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " repaire " << amount << " Hitpoints!" << std::endl;
	this->HitPoints += amount;
	this->EnergyPoint--;
}
