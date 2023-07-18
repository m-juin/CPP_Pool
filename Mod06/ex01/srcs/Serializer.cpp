#include <Serializer.hpp>

Serializer::Serializer()
{
}


Serializer::~Serializer()
{
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
