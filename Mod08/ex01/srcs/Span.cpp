#include <Span.hpp>

Span::Span()
{
	_max = 0;
}

Span::Span(unsigned int size)
{
	_max = size;
}

Span::Span(const Span &src)
{
	(*this) = src;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &src)
{
	if (this == &src)
		return (*this);
	this->_max = src._max;
	this->_list = src._list;
	return (*this);
}

void Span::addNumber(int number)
{
	if (_list.size() >= _max)
		throw TooMuchNumberException();
	_list.push_back(number);
}

int Span::shortestSpan()
{
	long span = 4294967295;
	if (_list.size() < 2)
		throw TooFewNumberException();
	std::vector<int>::iterator it;
	it = _list.begin();
	while (std::distance(it, _list.end()) > 1)
	{
		long size = (long)*it - (long)*++it;
		if (size < 0)
			size *= -1;
		if (size > 2147483647)
			throw OverflowException();
		if (size < span)
			span = size;
	}
	return (span);
}

int Span::longestSpan()
{
	int span = 0;
	if (_list.size() < 2)
		throw TooFewNumberException();
	std::vector<int>::iterator it;
	it = _list.begin();
	while (std::distance(it, _list.end()) > 1)
	{
		long size = (long)*it - (long)*++it;
		if (size < 0)
			size *= -1;
		if (size > 2147483647)
			throw OverflowException();
		if (size > span)
			span = size;
	}
	return (span);
}

void Span::displaySpan()
{
	std::vector<int>::iterator it;
	it = _list.begin();
	int i = 0;
	for (it = _list.begin(); it != _list.end(); it++)
	{
		std::cout << "_list[" << i << "] = " << *it << std::endl;
		i++;
	}
}

void Span::addRange(size_t amount)
{
	std::vector<int>::iterator it = _list.end();
	std::vector<int>::iterator it_end = _list.end();
	while (amount > 0)
	{
		++it_end;
		amount--;
	}
	while (it != it_end)
	{
		if (_list.size() == _max)
			throw TooFewNumberException();
		_list.push_back(rand());
		it++;
	}
	
	//std::for_each(_list.end(), it, _list.push_back(rand()));
}

const char *Span::TooMuchNumberException::what() const throw()
{
	return ("Span is already at the max size !");
}

const char *Span::TooFewNumberException::what() const throw()
{
	return ("To few number to find a span !");
}

const char *Span::OverflowException::what() const throw()
{
	return ("Span too big for an int !");
}
