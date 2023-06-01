
#include <DiamondTrap.hpp>

int main( void ) 
{
	{
		DiamondTrap bob("bob");
		FragTrap bab("bab");
		std::cout << std::endl;
		bob.attack("bab");
		bob.whoAmI();
	}
	std::cout << std::endl;
	{
		DiamondTrap BN("BN");
		DiamondTrap Prince(BN);
		std::cout << std::endl;
		BN.whoAmI();
		Prince.whoAmI();
		std::cout << std::endl;
		for (int i = 0; i < 55; i++)
		{
			BN.attack("Prince");
		}
		std::cout << std::endl;
	}
}