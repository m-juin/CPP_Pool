#include <Character.hpp>

Character::Character(std::string Name)
{
	_name = Name;
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	//std::cout << "Character " << Name << " was created with default constructor!" << std::endl;
}

Character::Character(const Character &src)
{
	*this = src;
	//std::cout << "Character " << _name << " was created with copy constructor!" << std::endl;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
				delete (_inventory[i]);
	//std::cout << "Character " << _name << " was destroyed!" <<std::endl;
}

Character &Character::operator=(const Character &src)
{
	if (this == &src)
		return (*this);
	for (size_t i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
				delete (_inventory[i]);
	_name = src._name;
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = src._inventory[i]->clone();
	//std::cout << "Character " << _name << " was created with copy assignement constructor!" << std::endl;
	return (*this);
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	if (m == NULL || m->getType().empty())
		return ;
	for (size_t i = 0; i < 5; i++)
	{
		if (i == 4)
			return ;
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (_inventory[idx] == NULL)
		return ;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (_inventory[idx] == NULL)
		return ;
	_inventory[idx]->use(target);
}
