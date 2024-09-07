#include "../includes/ScalarConverter.h"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &s)
{
	(void)s;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter &s)
{
	(void)s;
	return *this;
}

bool	is_digit(std::string str)
{
	short	nb_fp = 0;
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i + 1] == 0 && str[i] == 'f')
			return true;
		if ((str[i] < 48 || str[i] > 57) && str[i] != '.')
			return false;
		if (str[i] == '.')
			nb_fp++;
		if (nb_fp > 1)
			return false;
		i++;
	}
	return true;
}

void	convertChar(std::string num)
{
	char res;
	if (is_digit(num))
	{
		double numD = atof(num.c_str());
		res = static_cast<char>(numD);
		if (numD < std::numeric_limits<char>::min() || numD > std::numeric_limits<char>::max())
			std::cout << "char: overflow" << std::endl;
		else if (res < 32 || res > 126)
			std::cout << "char: non-displayable" << std::endl;
		else
		{
			std::cout << "char: \'" << res << "\'" << std::endl;
		}
	}
	else if (num.length() == 3 && num[0] == '\'' && num[2] == '\'')
	{
		res = num[1];
		if (res < std::numeric_limits<char>::min() || res > std::numeric_limits<char>::max())
			std::cout << "char: impossible" << std::endl;
		else if (res < 32 || res > 126)
			std::cout << "char: non-displayable" << std::endl;
		else
		{
			std::cout << "char: \'" << res << "\'" << std::endl;
		}
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void	convertInt(std::string num)
{
	int	res;
	double numD = atof(num.c_str());
	if ((numD == 0 && num != "0" && num != "0.0" && num != "0.0f") || !is_digit(num))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (numD < std::numeric_limits<int>::min() || numD > std::numeric_limits<int>::max())
	{
		std::cout << "int: overflow" << std::endl;
		return ;
	}
	res = static_cast<int>(numD);
	std::cout << "int: " << res << std::endl;
}

void	convertFloat(std::string num)
{
	float res;
	if (num == "nan" || num == "nanf")
	{
		res = std::numeric_limits<float>::quiet_NaN();
		std::cout << "float: " << res << "f" << std::endl;
		return ;
	}
	if (num == "+inf" || num == "+inff")
	{
		res = std::numeric_limits<float>::infinity();
		std::cout << "float: " << res << "f" << std::endl;
		return ;
	}
	if (num == "-inf" || num == "-inff")
	{
		res = std::numeric_limits<float>::infinity();
		res *= -1;
		std::cout << "float: " << res << "f" << std::endl;
		return ;
	}
	double numD = atof(num.c_str());
	if ((numD == 0 && num != "0" && num != "0.0" && num != "0.0f") || !is_digit(num))
	{
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	if (numD < -std::numeric_limits<float>::max() || numD > std::numeric_limits<float>::max())
	{
		std::cout << "float: overflow " << std::numeric_limits<float>::min() << std::endl;
		return ;
	}
	res = static_cast<float>(numD);
	if (res == (int)res)
		std::cout << "float: " << res << ".0f" << std::endl;
	else
		std::cout << "float: " << res << "f" << std::endl;
}

void	convertDouble(std::string num)
{
	double res;
	if (num == "nan" || num == "nanf")
	{
		res = std::numeric_limits<double>::quiet_NaN();
		std::cout << "double: " << res << std::endl;
		return ;
	}
	if (num == "+inf" || num == "+inff")
	{
		res = std::numeric_limits<double>::infinity();
		std::cout << "double: " << res << std::endl;
		return ;
	}
	if (num == "-inf" || num == "-inff")
	{
		res = std::numeric_limits<double>::infinity();
		res *= -1;
		std::cout << "double: " << res << std::endl;
		return ;
	}
	res = atof(num.c_str());
	if ((res == 0 && num != "0" && num != "0.0" && num != "0.0f") || !is_digit(num))
	{
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (res < -std::numeric_limits<double>::max() || res > std::numeric_limits<double>::max())
	{
		std::cout << "double: overflow " << std::numeric_limits<double>::min() << std::endl;
		return ;
	}
	if (res == (int)res)
		std::cout << "double: " << res << ".0" << std::endl;
	else
		std::cout << "double: " << res << std::endl;
}

void ScalarConverter::convert(std::string num)
{
	convertChar(num);
	convertInt(num);
	convertFloat(num);
	convertDouble(num);
}



