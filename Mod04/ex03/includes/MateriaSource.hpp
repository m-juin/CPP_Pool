#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <IMateriaSource.hpp>
#include <iostream>

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource&src);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource&);
		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
	private:
		AMateria *_inventory[4];
};

#endif