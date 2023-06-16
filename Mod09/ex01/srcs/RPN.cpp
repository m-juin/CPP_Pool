#include <RPN.hpp>

RPN::RPN()
{
}

bool RPN::calculate(std::string data)
{
	int pos = -1;

	while (data[++pos] != '\0')
	{
		if (data[pos] == ' ')
			continue;
		else if (data[pos] >= '0' && data[pos] <= '9')
		{
			_value.push(data[pos] - '0');
		}
		else
		{
			if (_value.size() < 2)
			{
				std::cout << "Invalid calcul Format" << std::endl;
				return (false);
			}
			int num1 = _value.top();
			_value.pop();
			int num2 = _value.top();
			_value.pop();
			switch (data[pos])
			{
				case '+':
				{
					_value.push(num2 + num1);
					break;
				}
				case '-':
				{
					_value.push(num2 - num1);
					break;
				}
				case '/':
				{
					if (num1 == 0)
					{
						std::cout << "Division by 0 invalid !" << std::endl;
						return (false);
					}
					_value.push(num2 / num1);
					break;
				}
				case '*':
				{
					_value.push(num2 * num1);
					break;
				}
				default:
				{
					std::cout << "invalid operator \'" << data[pos] << "\'" << std::endl;
					return (false);
				}
			}
		}
	}
	if (_value.size() != 1)
	{
		std::cout << "Invalid calcul Format" << std::endl;
		return (false);
	}
	return (true);
}

int RPN::getTop()
{
	return (_value.top());
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &src)
{
	if (this == &src)
		return (*this);
	_value = src._value;
	return (*this);
}
