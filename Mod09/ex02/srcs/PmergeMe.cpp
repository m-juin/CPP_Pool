
#include "PmergeMe.hpp"
#include <ctime>
#include <sys/time.h>

/******************************************************************************************/
/*                                                                                        */
/*                                         Vector                                         */
/*                                                                                        */
/******************************************************************************************/

long long PmergeMe::sortVector()
{
    struct timeval time_now;
    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1000000) + (time_now.tv_usec);
	std::vector<Pair> pairvector;
	int last = -1;
	if (this->_vector.size() % 2 != 0)
	{
		last = this->_vector[this->_vector.size() - 1];
		_vector.pop_back();
	}
	for (size_t i = 0; i < this->_vector.size(); i += 2)
		pairvector.push_back(Pair(this->_vector[i], this->_vector[i + 1], i / 2));
	sortPairMax(&pairvector, pairvector.size());
	_vector.clear();
	for (size_t i = 0; i < pairvector.size(); i++)
		_vector.push_back(pairvector[i].getMax());
	insertSort(pairvector);
	if (last != -1)
		BinaryInsertVector(last, 0, _vector.size());
    struct timeval time_now2;
    gettimeofday(&time_now2, NULL);
    time_t msecs_time2 = (time_now2.tv_sec * 1000000) + (time_now2.tv_usec);
	return (msecs_time2 - msecs_time);
}

void PmergeMe::sortPairMax(std::vector<Pair> *pairvector, size_t size)
{
	if (size <= 1)
		return;
	sortPairMax(pairvector, size - 1);
	int pos;
	Pair value = (*pairvector)[size - 1];
	for (pos = size - 2; pos >= 0 && ((*pairvector)[pos]).getMax() > value.getMax(); pos--)
	{
		(*pairvector)[pos + 1] = (*pairvector)[pos];
		(*pairvector)[pos + 1].setIndex((pos + 1));
	}
	(*pairvector)[pos + 1] = value;
	(*pairvector)[pos + 1].setIndex((pos + 1));
}

void PmergeMe::insertSort(std::vector<Pair> pairvector)
{
	_vector.insert(_vector.begin(), pairvector[0].getMin());
	for (size_t y = 0; y < pairvector.size(); y++)
	{
		pairvector[y].setIndex(pairvector[y].getIndex() + 1);
	}
	unsigned int sequencePrevious1 = 0;
	unsigned int sequencePrevious2 = 0;
	unsigned int sequenceSize;
	if (pairvector.size() == 2)
		sequenceSize = 1;
	else
		sequenceSize = 2;
	size_t ElementNumber = pairvector.size() - 1;
	unsigned int cur_element = 0;
	while (cur_element != ElementNumber)
	{
		for (size_t i = 0; i < sequenceSize && cur_element < ElementNumber; i++)
		{
			BinaryInsertVector(pairvector[cur_element + sequenceSize - i].getMin(), 0, (pairvector[cur_element + sequenceSize - i].getIndex()));
			for (size_t y = cur_element; y < pairvector.size(); y++)
			{
				if (pairvector[cur_element + sequenceSize - i].getMin() <= pairvector[y].getMax())
					pairvector[y].setIndex(pairvector[y].getIndex() + 1);
			}
		}
		cur_element += sequenceSize;
		sequencePrevious1 = sequencePrevious2;
		sequencePrevious2 = sequenceSize;
		sequenceSize = sequencePrevious2 + (2 * sequencePrevious1);
		if (cur_element + sequenceSize > ElementNumber)
			sequenceSize = ElementNumber - cur_element;
	}
}

void PmergeMe::BinaryInsertVector(unsigned int element, unsigned int min, unsigned int max)
{
	if (min + 1 == max)
	{
		if (_vector[min] < element && _vector[max] >= element)
			_vector.insert(_vector.begin() + (min + 1), element);
		else
			_vector.insert(_vector.begin() + (min), element);
	}
	else if (min == max)
		_vector.insert(_vector.begin() + (min + 1), element);
	else
	{
		if (_vector[min + ((max - min) / 2)] > element)
			BinaryInsertVector(element, min, max - ((max - min) / 2));
		else
			BinaryInsertVector(element, min + ((max - min) / 2), max);
	}
}

/******************************************************************************************/
/*                                                                                        */
/*                                         Deque                                          */
/*                                                                                        */
/******************************************************************************************/

long long PmergeMe::sortDeque()
{
    struct timeval time_now;
    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1000000) + (time_now.tv_usec);
	std::deque<Pair> pairdeque;
	int last = -1;
	if (this->_deque.size() % 2 != 0)
	{
		last = this->_deque[this->_deque.size() - 1];
		_deque.pop_back();
	}
	for (size_t i = 0; i < this->_deque.size(); i += 2)
		pairdeque.push_back(Pair(this->_deque[i], this->_deque[i + 1], i / 2));
	sortPairMax(&pairdeque, pairdeque.size());
	_deque.clear();
	for (size_t i = 0; i < pairdeque.size(); i++)
		_deque.push_back(pairdeque[i].getMax());
	insertSort(pairdeque);
	if (last != -1)
		BinaryInsertDeque(last, 0, _deque.size() + 1);
    struct timeval time_now2;
    gettimeofday(&time_now2, NULL);
    time_t msecs_time2 = (time_now2.tv_sec * 1000000) + (time_now2.tv_usec);
	return (msecs_time2 - msecs_time);
}

void PmergeMe::sortPairMax(std::deque<Pair> *pairdeque, size_t size)
{
	if (size <= 1)
		return;
	sortPairMax(pairdeque, size - 1);
	int pos;
	Pair value = (*pairdeque)[size - 1];
	for (pos = size - 2; pos >= 0 && ((*pairdeque)[pos]).getMax() > value.getMax(); pos--)
	{
		(*pairdeque)[pos + 1] = (*pairdeque)[pos];
		(*pairdeque)[pos + 1].setIndex((pos + 1));
	}
	(*pairdeque)[pos + 1] = value;
	(*pairdeque)[pos + 1].setIndex((pos + 1));
}

void PmergeMe::insertSort(std::deque<Pair> pairdeque)
{
	_deque.push_front(pairdeque[0].getMin());
	for (size_t y = 0; y < pairdeque.size(); y++)
	{
			pairdeque[y].setIndex(pairdeque[y].getIndex() + 1);
	}
	unsigned int sequencePrevious1 = 0;
	unsigned int sequencePrevious2 = 0;
	unsigned int sequenceSize;
	if (pairdeque.size() == 2)
		sequenceSize = 1;
	else
		sequenceSize = 2;
	size_t ElementNumber = pairdeque.size() - 1;
	unsigned int cur_element = 0;
	while (cur_element != ElementNumber)
	{
		for (size_t i = 0; i < sequenceSize && cur_element < ElementNumber; i++)
		{
			BinaryInsertDeque(pairdeque[cur_element + sequenceSize - i].getMin(), 0, (pairdeque[cur_element + sequenceSize - i].getIndex()));
			for (size_t y = cur_element; y < pairdeque.size(); y++)
			{
				if (pairdeque[cur_element + sequenceSize - i].getMin() <= pairdeque[y].getMax())
					pairdeque[y].setIndex(pairdeque[y].getIndex() + 1);
			}
		}
		cur_element += sequenceSize;
		sequencePrevious1 = sequencePrevious2;
		sequencePrevious2 = sequenceSize;
		sequenceSize = sequencePrevious2 + (2 * sequencePrevious1);
		if (cur_element + sequenceSize > ElementNumber)
			sequenceSize = ElementNumber - cur_element;
	}
}

void PmergeMe::BinaryInsertDeque(unsigned int element, unsigned int min, unsigned int max)
{
	if (min + 1 == max)
	{
		if (_deque[min] < element && _deque[max] >= element)
			_deque.insert(_deque.begin() + (min + 1), element);
		else
			_deque.insert(_deque.begin() + (min), element);
	}
	else if (min == max)
		_deque.insert(_deque.begin() + (min + 1), element);
	else
	{
		if (_deque[min + ((max - min) / 2)] > element)
			BinaryInsertDeque(element, min, max - ((max - min) / 2));
		else
			BinaryInsertDeque(element, min + ((max - min) / 2), max);
	}
}

/******************************************************************************************/
/*                                                                                        */
/*                                         Common                                         */
/*                                                                                        */
/******************************************************************************************/

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
	printValue("Before =", 0, false);
	float t_vector = sortVector();
	float t_deque = sortDeque();
	printValue("After =", 0, false);
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << t_deque << " µs.\n";
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << t_vector << " µs.\n";
	Verify();
}

void PmergeMe::printValue(std::string message, int Container = 0, bool all = true)
{
	if (Container != 0 && Container != 1)
		return;
	if (Container == 0)
	{
		std::vector<unsigned int>::iterator it2;
		if (all == false && _vector.size() >= 4)
		{
			it2 = _vector.begin();
			std::advance(it2, 4);
		}
		else
			it2 = _vector.end();
		std::cout << message;
		std::vector<unsigned int>::iterator it;
		for (it = _vector.begin(); it != it2; it++)
			std::cout << " " << *it;
		if (it != _vector.end())
			std::cout << " [...]";
		std::cout << std::endl;
	}
	else
	{
		std::deque<unsigned int>::iterator it2;
		if (all == false && _vector.size() >= 4)
		{
			it2 = _deque.begin();
			std::advance(it2, 4);
		}
		else
			it2 = _deque.end();
		std::cout << message;
		std::deque<unsigned int>::iterator it;
		for (it = _deque.begin(); it != it2; it++)
			std::cout << " " << *it;
		if (it != _deque.end())
			std::cout << " [...]";
		std::cout << std::endl;
	}
}

void PmergeMe::Verify()
{
	unsigned int previous = 0;
	for (size_t i = 0; i < _deque.size(); i++)
	{
		if (i == 0)
		{
			previous = _deque[i];
			continue;
		}
		if (previous <= _deque[i])
		{
			previous = _deque[i];
			continue;
		}
		else
		{
			std::cout << "\033[1;31m" << "Error in Element " << i << "of deque" << "\033[0m" << std::endl;
			return ;
		}
	}
	for (size_t i = 0; i < _vector.size(); i++)
	{
		if (i == 0)
		{
			previous = _vector[i];
			continue;
		}
		if (previous <= _vector[i])
		{
			previous = _vector[i];
			continue;
		}
		else
		{
			std::cout << "\033[1;31m" << "Error in Element " << i << "of vector" << "\033[0m" << std::endl;
			return ;
		}
	}
	std::cout << "\033[1;32m" << "All is good for both container" << "\033[0m" << std::endl;
}

/******************************************************************************************/
/*                                                                                        */
/*                                   Custom Constructor                                   */
/*                                                                                        */
/******************************************************************************************/

PmergeMe::Pair::Pair(int min, int max, size_t index)
{
	this->_min = (min < max) ? min : max;
	this->_max = (min <= max) ? max : min;
	this->_index = index;
}

/******************************************************************************************/
/*                                                                                        */
/*                                     Canonical Form                                     */
/*                                                                                        */
/******************************************************************************************/

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this == &src)
		return (*this);
	this->_deque = src._deque;
	this->_vector = src._vector;
	return (*this);
}

PmergeMe::Pair::Pair() {}

PmergeMe::Pair::~Pair() {}

PmergeMe::Pair::Pair(const Pair &src)
{
	*this = src;
}

PmergeMe::Pair &PmergeMe::Pair::operator=(const PmergeMe::Pair &src)
{
	if (this == &src)
		return (*this);
	this->_index = src._index;
	this->_max = src._max;
	this->_min = src._min;
	return (*this);
}

/******************************************************************************************/
/*                                                                                        */
/*                                     Getter / Setter                                    */
/*                                                                                        */
/******************************************************************************************/

long int PmergeMe::Pair::getMax()
{
	return this->_max;
}

long int PmergeMe::Pair::getMin()
{
	return this->_min;
}

unsigned int PmergeMe::Pair::getIndex()
{
	return this->_index;
}

void PmergeMe::Pair::setIndex(size_t index)
{
	this->_index = index;
}
