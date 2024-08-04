#include "Serializer.hpp"
#include "DataStructure.hpp"

int main () {

	Data data;
	Data *compare;

	data.c = 'A';
	data.i = 10;
	data.d = 10.0;
	data.f = 12.1f;
	data.string = "Excercise 01";

	compare = Serializer::deserialize(Serializer::serialize(&data));
	std::cout << "Char: " << data.c << std::endl;
	std::cout << "Int: " << data.i << std::endl;
    std::cout << "Double: " << data.d << std::endl;
    std::cout << "Float: " << data.f << std::endl;
    std::cout << "String: " << data.string << std::endl;


	if (&data == compare)
		std::cout << "Well done, you can continue with ex02" << std::endl;

	return (0);
}
