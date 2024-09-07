#include "../includes/ASerializer.h"


int main(void)
{
	try
	{
		Data d;
		d.dt = 42;
		d.name = "Four..tytou";

		std::cout << std::endl;

		std::cout << "Data: " << d.dt << " | Name: " << d.name << std::endl << std::endl;

		uintptr_t ptr = ASerializer::serialize(&d);
		Data *n;
		n = ASerializer::deserialize(ptr);

		std::cout << std::endl << "Data: " << n->dt << " | Name: " << n->name << std::endl;

		std::cout << std::endl;


	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
