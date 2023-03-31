#include <Brain.hpp>

Brain::Brain()
{
	for (size_t i = 0; i < 100; i++)
		ideas[i] = "Bark";
	std::cout << "A Brain is created by default constructor!" << std::endl;
}

Brain::Brain(const Brain &src)
{
	(*this) = src;
	std::cout << "A Brain is created by copy constructor!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain was destroyed!" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	if (this == &src)
		return (*this);
	for (size_t i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	std::cout << "A Brain was created by copy assignement constructor!" << std::endl;
	return (*this);
}

std::string Brain::getIdea(const int index) const
{
	return (ideas[index]);
}

void Brain::setIdea(const int index, std::string str)
{
	if (index < 0 || index > 99)
		return ;
	this->ideas[index] = str;
}
