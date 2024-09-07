#include "../includes/Base.h"

#include <iostream>
#include <cstdlib>
#include "../includes/A.h"
#include "../includes/B.h"
#include "../includes/C.h"

Base * generate(void)
{
	static	int rounds = 0;
	int		nb;

	rounds++;
	std::srand(time(0));
	int i = -1;
	while (++i < rounds)
		nb = rand();
	if (nb % 3 == 1)
		return new A();
	else if (nb % 3 == 2)
		return new B();
	else
		return new C();
}

void	identify(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class given is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class given is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class given is C" << std::endl;
}

void	identify(Base & p)
{
	Base truc;

	try
	{
		truc =dynamic_cast<A&>(p);
		std::cout << "Class given is A" << std::endl;
	}
	catch (std::exception & e)
	{
	}
	try
	{
		truc =dynamic_cast<B&>(p);
		std::cout << "Class given is B" << std::endl;
	}
	catch (std::exception & e)
	{
	}
	try
	{
		truc =dynamic_cast<C&>(p);
		std::cout << "Class given is C" << std::endl;
	}
	catch (std::exception & e)
	{
	}
}

int main(void)
{
	std::cout << std::endl << "\x1b[1;36m############### TEST 1 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Base *ptr;
		for(int i = 0; i < 10; i++)
		{
			ptr = generate();
			identify(ptr);
			delete ptr;
		}
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "\x1b[1;36m############### TEST 2 ###############\x1b[0m" << std::endl << std::endl;
	try
	{
		Base *ptr;
		for(int i = 0; i < 10; i++)
		{
			ptr = generate();
			identify(*ptr);
			delete ptr;
		}
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
