#include <PmergeMe.hpp>

PmergeMe::PmergeMe()
{

}

float PmergeMe::sortDeque()
{
	clock_t startTV = clock();
	std::deque<unsigned int> dequeA;
	std::deque<unsigned int> dequeB;	
	int						last = -1;

	for (size_t i = 0; i < _deque.size(); i++)
	{
		if (_deque.size() % 2 != 0 && i == _deque.size() - 1)
			last = _deque[i];
		else if (i % 2 == 0)
		{
			dequeA.push_back(_deque[i]);
		}
		else
			dequeB.push_back(_deque[i]);
	}
	for (size_t i = 0; i < dequeA.size(); i++)
	{
		int tmp;
		if (dequeA[i] > dequeB[i])
		{
			tmp = dequeB[i];
			dequeB[i] = dequeA[i];
			dequeA[i] = tmp;
		}
	}
	for (size_t i = 1; i < dequeA.size(); i++)
	{
		if (dequeA[i] < dequeA[i - 1])
		{
			int tmp = dequeA[i - 1];
			dequeA[i - 1] = dequeA[i];
			dequeA[i] = tmp;
			tmp = dequeB[i - 1];
			dequeB[i - 1] = dequeB[i];
			dequeB[i] = tmp;
			i = 0;
		}
	}
	if (last != -1)
		dequeB.push_back(last);
	for (size_t i = 0; i < dequeB.size(); i++)
	{
		std::deque<unsigned int>::iterator it2 = dequeA.end();
		bool inserted = false;
		for (std::deque<unsigned int>::iterator it = dequeA.begin(); it != it2; it++)
		{
			if (dequeB[i] <= *it)
			{
				dequeA.insert(it, dequeB[i]);
				inserted = true;
				break;
			}
		}
		if (inserted == false)
			dequeA.insert(it2, dequeB[i]);
	}
	_deque = dequeA;
	return ((float)(clock() - startTV)/CLOCKS_PER_SEC);
}

float PmergeMe::sortVector()
{
	clock_t startTV = clock();
	std::vector<unsigned int> vectorA;
	std::vector<unsigned int> vectorB;	
	int						last = -1;

	for (size_t i = 0; i < _vector.size(); i++)
	{
		if (_vector.size() % 2 != 0 && i == _vector.size() - 1)
			last = _vector[i];
		else if (i % 2 == 0)
		{
			vectorA.push_back(_vector[i]);
		}
		else
			vectorB.push_back(_vector[i]);
	}
	for (size_t i = 0; i < vectorA.size(); i++)
	{
		int tmp;
		if (vectorA[i] > vectorB[i])
		{
			tmp = vectorB[i];
			vectorB[i] = vectorA[i];
			vectorA[i] = tmp;
		}
	}
	for (size_t i = 1; i < vectorA.size(); i++)
	{
		if (vectorA[i] < vectorA[i - 1])
		{
			int tmp = vectorA[i - 1];
			vectorA[i - 1] = vectorA[i];
			vectorA[i] = tmp;
			tmp = vectorB[i - 1];
			vectorB[i - 1] = vectorB[i];
			vectorB[i] = tmp;
			i = 0;
		}
	}
	if (last != -1)
		vectorB.push_back(last);
	for (size_t i = 0; i < vectorB.size(); i++)
	{
		std::vector<unsigned int>::iterator it2 = vectorA.end();
		bool inserted = false;
		for (std::vector<unsigned int>::iterator it = vectorA.begin(); it != it2; it++)
		{
			if (vectorB[i] <= *it)
			{
				vectorA.insert(it, vectorB[i]);
				inserted = true;
				break;
			}
		}
		if (inserted == false)
			vectorA.insert(it2, vectorB[i]);
	}
	_vector = vectorA;
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
	float t_deque = sortDeque();
	printValue("After =");
	float t_vector = sortVector();
	std::cout << "time for std::deque to sort " << _deque.size() << " elements  = " << std::fixed << t_deque << " s" << std::endl;
	std::cout << "time for std::vector to sort " << _deque.size() << " elements  = " << std::fixed << t_vector << " s" << std::endl;
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
