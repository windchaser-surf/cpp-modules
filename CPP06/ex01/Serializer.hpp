#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <iostream>
#include "DataStructure.hpp"
		
typedef unsigned long uintptr_t;

class Serializer {

	private:

		Serializer();
		Serializer(const Serializer& old);
		Serializer& operator=(const Serializer& old);
		~Serializer();
	
	public: 

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
