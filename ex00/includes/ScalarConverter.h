#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <cstdlib>
#include <limits>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define PINK "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define BOLD "\x1b[1m"
#define UNDER "\x1b[4m"
#define END "\x1b[0m"

class ScalarConverter
{
	public:
		static void	convert(std::string num);

	private:
		ScalarConverter();
		ScalarConverter( const ScalarConverter & s );
		~ScalarConverter();

		ScalarConverter & operator=( ScalarConverter & s );
};


#endif
