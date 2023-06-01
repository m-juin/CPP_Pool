/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:44:18 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/04/25 14:13:00 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <IMateriaSource.hpp>
#include <MateriaSource.hpp>
#include <AMateria.hpp>
#include <Character.hpp>
#include <Ice.hpp>
#include <Cure.hpp>

int main()
{
	{
		std::cout << "Basic test" << std::endl;
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");
		AMateria *tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;

		std::cout << "\n";
	}
	{
		std::cout << "Materia test" << std::endl;
		ICharacter *Ybbob = new Character("Ybbob");
		AMateria *ice = new Ice();
		ice->getType();
		ice->use(*Ybbob);
		AMateria *clone = ice->clone();
		delete (ice);
		clone->getType();
		clone->use(*Ybbob);
		delete (clone);
		AMateria *cure = new Cure();
		cure->getType();
		cure->use(*Ybbob);
		clone = cure->clone();
		delete (cure);
		clone->getType();
		clone->use(*Ybbob);
		AMateria *clone2 = clone->clone();
		delete (clone);
		clone2->getType();
		clone2->use(*Ybbob);
		delete (clone2);
		delete (Ybbob);
		std::cout << "\n";
	}
	{
		std::cout << "Character test" << std::endl;
		IMateriaSource *Materias = new MateriaSource();
		ICharacter *Ybbob = new Character("Ybbob");
		ICharacter *Bobby = new Character("Bobby");
		AMateria *ice = new Ice();
		AMateria *ice2 = new Ice();
		AMateria *cure = new Cure();
		AMateria *cure2 = new Cure();
		AMateria *cure3 = new Cure();
		Ybbob->equip(ice);
		Ybbob->equip(ice2);
		Ybbob->equip(cure);
		Ybbob->equip(cure2);
		Ybbob->equip(cure3);
		AMateria *tmp;
		tmp = Materias->createMateria("Unknown");
		Ybbob->unequip(0);
		Ybbob->equip(tmp);
		Ybbob->equip(ice);
		for (int i = 0; i < 4; i++)
			Ybbob->use(i, *Bobby);
		delete Materias;
		delete Ybbob;
		delete Bobby;
		delete cure3;
		std::cout << "\n";
	}
	{
		std::cout << "MeteriaSource test" << std::endl;
		IMateriaSource *Materias = new MateriaSource();
		AMateria *tmp;
		AMateria *ice = new Ice();
		AMateria *cure = new Cure();
		tmp = Materias->createMateria("ice");
		delete tmp;
		tmp = Materias->createMateria("cure");
		delete tmp;
		Materias->learnMateria(ice);
		Materias->learnMateria(cure);
		tmp = Materias->createMateria("ice");
		delete tmp;
		tmp = Materias->createMateria("cure");
		delete tmp;
		delete Materias;
		std::cout << "\n";
	}
	return 0;
}
