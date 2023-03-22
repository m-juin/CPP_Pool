#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <FragTrap.hpp>
#include <ScavTrap.hpp>

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap&src);
		~DiamondTrap();
		DiamondTrap &operator=(const DiamondTrap&);
		void whoAmI();
		using ScavTrap::attack;
	private:
		std::string Name;
		using FragTrap::HitPoints;
		using ScavTrap::EnergyPoint;
		using FragTrap::AttackDamage;
};

#endif