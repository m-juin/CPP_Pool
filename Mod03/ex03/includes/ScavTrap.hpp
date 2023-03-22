#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <ClapTrap.hpp>

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap&src);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap&);
		void guardGate();
	private:
		
};

#endif
