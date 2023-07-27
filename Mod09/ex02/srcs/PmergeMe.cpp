#include "../includes/PmergeMe.hpp"
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}



float PmergeMe::sortDeque()
{
	clock_t startTV = clock();
	std::deque<Pair> pairdeque;
	int last = -1;
	if (this->_deque.size() % 2 != 0)
		last = this->_deque[this->_deque.size() - 1];
	for (size_t i = 0; i < this->_deque.size(); i += 2)
		pairdeque.push_back(Pair(this->_deque[i], this->_deque[i + 1], i / 2));
	sortPairMax(pairdeque);
	return ((float)(clock() - startTV)/CLOCKS_PER_SEC);
}

float PmergeMe::sortVector()
{
	clock_t startTV = clock();

	return ((float)(clock() - startTV)/CLOCKS_PER_SEC);
}

void PmergeMe::sortPairMax(std::deque<Pair> pairdeque, size_t size)
{
	if (size <= 1)
		return ;
	int pos;

	for (pos = size - 2; pos >= 0 && ((*pairdeque)[pos]).getMin() > nl; pos--)
	{
		(*pairdeque)[pos + 1] = (*pairdeque)[pos];
		(*pairdeque)[pos + 1]
	}
	
}

void PmergeMe::printValue(std::string message)
{
	std::vector<unsigned int>::iterator it2 = _vector.end();
	std::cout << message;
	for (std::vector<unsigned int>::iterator it = _vector.begin() ; it != it2; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

PmergeMe::PmergeMe(int arg_count, char **av)
{
	for (int i = 1; i <= arg_count; i++)
	{
		int y = -1;
		while (av[i][++y] != '\0')
		{
			if (y == 0 && ((av[i][y] == '-' || av[i][y] == '+') && isdigit(av[i][y + 1])))
				continue;
			if (isdigit(av[i][y]) == false)
				throw std::runtime_error("Error ! Non number argument in list");
		}
		if (y == 0)
			throw std::runtime_error("Error ! Empty argument in list");
		long int atoied = std::strtol(av[i], NULL, 10);
		if (errno == ERANGE)
			throw std::runtime_error("Error ! An argument in list may cause an overflow");
		else if (atoied < 0)
			throw std::runtime_error("Error ! Negative argument in list");
		else if (atoied > 2147483647)
			throw std::runtime_error("Error ! An argument in list is superior to int max");
		_deque.push_back(atoied);
		_vector.push_back(atoied);
	}
	printValue("Before =");
	float t_vector = sortVector();
	float t_deque = sortDeque();
	printValue("After =");
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << std::fixed << t_deque << " s\n";
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << std::fixed << t_vector << " s\n";
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this == &src)
		return (*this);
	this->_deque = src._deque;
	this->_vector = src._vector;
	return (*this);
}

PmergeMe::Pair::Pair(int min, int max, size_t index)
{
	this->_min = (min < max) ? min : max;
	this->_max = (min <= max) ? max : min;
	this->_index = index;
}

long int PmergeMe::Pair::getMax()
{
    return this->_max;
}

long int PmergeMe::Pair::getMin()
{
    return this->_min;
}

void PmergeMe::Pair::setIndex()
{
}
