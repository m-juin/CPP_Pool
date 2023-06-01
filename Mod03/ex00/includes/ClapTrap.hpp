#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	public:
		ClapTrap(std::string Name);
		ClapTrap(const ClapTrap&);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap&);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		ClapTrap();
		std::string	Name;
		int			HitPoints;
		int			EnergyPoint;
		int			AttackDamage;
};

#endif