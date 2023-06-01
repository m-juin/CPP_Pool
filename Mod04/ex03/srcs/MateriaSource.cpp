#include <MateriaSource.hpp>

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	//std::cout << "A new MateriaSource was created with default constructor!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
	//std::cout << "A new MateriaSource was created with copy constructor!" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
				delete (_inventory[i]);
	//std::cout << "A MateriaSource was destroyed!" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this == &src)
		return (*this);
	for (size_t i = 0; i < 4; i++)
		if (_inventory[i] != NULL)
				delete (_inventory[i]);
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = src._inventory[i]->clone();
	//std::cout << "A new MateriaSource was created with copy assignement constructor!" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (m->getType().empty())
		return ;
	for (size_t i = 0; i < 5; i++)
	{
		if (i == 4)
			return ;
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m->clone();
			delete(m);
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (0);
}
