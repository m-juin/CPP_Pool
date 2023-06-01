#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <ICharacter.hpp>

class Character : public ICharacter
{
	public:
		Character(std::string Name);
		Character(const Character&src);
		~Character();
		Character &operator=(const Character&);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		std::string _name;
		AMateria* _inventory[4];
};

#endif
