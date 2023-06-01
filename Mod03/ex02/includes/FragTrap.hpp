#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <ClapTrap.hpp>

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string Name);
		FragTrap(const FragTrap&src);
		~FragTrap();
		FragTrap &operator=(const FragTrap&);
		void highFivesGuys(void);
	private:
		FragTrap();
};

#endif