#include <PmergeMe.hpp>

PmergeMe::PmergeMe()
{

}

void PmergeMe::InsertSort(std::deque<unsigned int> *dequeB)
{
	std::deque<unsigned int>::iterator it2 = (*dequeB).end();
	
	for (size_t i = 0; i < _deque.size() - 1; i += 2)
	{
		std::deque<unsigned int>::iterator it = (*dequeB).begin();
		while (it != it2 && *it > _deque[i])
		{
			it++;
		}
		(*dequeB).insert(it, _deque[i]);
	}
}

void PmergeMe::RecursiveSort(std::deque<unsigned int> *dequeB, int size)
{
	if (size < 2)
		return ;
	RecursiveSort(dequeB, size - 1);
	unsigned int nl = (*dequeB)[size - 1];
	unsigned int nl1;
	for (nl1 = size - 2; nl1 != 0 && (*dequeB)[nl1] <= nl; nl1--)
	{
		(*dequeB)[nl1 + 1] = (*dequeB)[nl1];
	}
	(*dequeB)[nl1 + 1] = nl;
}

float PmergeMe::sortDeque()
{
	clock_t startTV = clock();
	std::deque<unsigned int> dequeB;	
	int						last = -1;

	if (_deque.size() % 2 != 0)
		last = _deque[_deque.size() - 1];
	for (size_t i = 0; i < _deque.size(); i += 2)
	{
		if (_deque[i] > _deque[i + 1])
			std::swap(_deque[i], _deque[i + 1]);
	}
	for (size_t i = 1; i < _deque.size(); i += 2)
	{
		dequeB.push_back(_deque[i]);
	}
	if (last != -1)
		dequeB.push_back(last);
	RecursiveSort(&dequeB, dequeB.size());
	InsertSort(&dequeB);
	std::reverse(dequeB.begin(), dequeB.end());
	_deque = dequeB;
	return ((float)(clock() - startTV)/CLOCKS_PER_SEC);
}

void PmergeMe::InsertSort(std::vector<unsigned int> *vectorB)
{
	std::vector<unsigned int>::iterator it2 = (*vectorB).end();
	
	for (size_t i = 0; i < _vector.size() - 1; i += 2)
	{
		std::vector<unsigned int>::iterator it = (*vectorB).begin();
		while (it != it2 && (*it) > _vector[i])
		{
			it++;
		}
		(*vectorB).insert(it, _vector[i]);
	}
}

void PmergeMe::RecursiveSort(std::vector<unsigned int> *vectorB, int size)
{
	if (size < 2)
		return ;
	RecursiveSort(vectorB, size - 1);
	unsigned int nl = (*vectorB)[size - 1];
	unsigned int nl1;
	for (nl1 = size - 2; nl1 != 0 && (*vectorB)[nl1] <= nl; nl1--)
	{
		(*vectorB)[nl1 + 1] = (*vectorB)[nl1];
	}
	(*vectorB)[nl1 + 1] = nl;
}

float PmergeMe::sortVector()
{
	clock_t startTV = clock();
	std::vector<unsigned int> vectorB;	
	int						last = -1;

	if (_vector.size() % 2 != 0)
		last = _vector[_vector.size() - 1];
	for (size_t i = 0; i < _vector.size(); i += 2)
	{
		if (_vector[i] > _vector[i + 1])
			std::swap(_vector[i], _vector[i + 1]);
	}
	for (size_t i = 1; i < _vector.size(); i += 2)
	{
		vectorB.push_back(_vector[i]);
	}
	if (last != -1)
		vectorB.push_back(last);
	RecursiveSort(&vectorB, vectorB.size());
	InsertSort(&vectorB);
	std::reverse(vectorB.begin(), vectorB.end());
	_vector = vectorB;
	return ((float)(clock() - startTV)/CLOCKS_PER_SEC);
}

void PmergeMe::printValue(std::string message)
{
	std::deque<unsigned int>::iterator it2 = _deque.end();
	std::cout << message;
	for (std::deque<unsigned int>::iterator it = _deque.begin() ; it != it2; it++)
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
		int atoied = std::atoi(av[i]);
		if (atoied < 0)
			throw std::runtime_error("Error ! Negative argument in list");
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
