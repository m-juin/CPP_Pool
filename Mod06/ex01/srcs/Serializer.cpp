#include <Serializer.hpp>

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
	*this = src;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &src)
{
	if (&src == this)
		return (*this);
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t	converted;
	converted = reinterpret_cast<uintptr_t>(ptr);
	return (converted);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data	*converted;
	converted = reinterpret_cast<Data *>(raw);
	return (converted);
}

Data::Data()
{

}
