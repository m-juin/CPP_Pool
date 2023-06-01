#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain&src);
		~Brain();
		Brain &operator=(const Brain&);
		std::string getIdea(const int index) const;
		void setIdea(const int index, std::string str);
	private:
		std::string ideas[100];
};

#endif