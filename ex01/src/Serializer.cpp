#include "../includes/ASerializer.h"

ASerializer::ASerializer()
{
	std::cout << "ASerializer : Default constructor" << std::endl;
}

ASerializer::ASerializer( const ASerializer & b )
{
	(void)b;
	std::cout << "ASerializer : Copy constructor" << std::endl;
}

ASerializer::~ASerializer()
{
	std::cout << "ASerializer : Destructor" << std::endl;
}

ASerializer &ASerializer::operator=(const ASerializer &s)
{
	(void)s;
	return *this;
}

uintptr_t	ASerializer::serialize(Data *ptr)
{
	std::cout << "ASerializer: serializing.." << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*ASerializer::deserialize(uintptr_t raw)
{
	std::cout << "ASerializer: deserializing.." << std::endl;
	return reinterpret_cast<Data*>(raw);

}