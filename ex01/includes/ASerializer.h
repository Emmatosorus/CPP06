#ifndef ASERIALIZER_H
#define ASERIALIZER_H

#include <iostream>
#include <stdint.h>
#include "Data.h"

class ASerializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

		ASerializer & operator=( const ASerializer & s);

	private:
		ASerializer();
		ASerializer( const ASerializer & s);
		~ASerializer();

};


#endif
