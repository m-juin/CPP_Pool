#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(const ClapTrap&);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap&);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	protected:
		ClapTrap();
		ClapTrap(std::string Name);
		std::string	Name;
		int			HitPoints;
		int			EnergyPoint;
		int			AttackDamage;
	private:
};

#endif