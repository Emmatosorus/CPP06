#include "../includes/ScalarConverter.h"


int main(int ac, char **argv)
{
	try
	{
		if (ac > 2)
			throw std::invalid_argument("Program needs only 1 (one) argument");
		if (ac < 2)
			throw std::invalid_argument("Program needs 1 (one) argument");
		ScalarConverter::convert(argv[1]);
	}
	catch(std::exception & e)
	{
		std::cout << BOLD << RED << e.what() << END << std::endl;
	}
}
