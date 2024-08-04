#include "Base.hpp"

int main () {

	Base gen;
	Base *base1 = NULL;

	try {

		base1 = gen.generate();
		base1->identify(base1);
		base1->identify(*base1);
	}
	catch (std::exception& e) {

		std::cerr << e.what() << std::endl;
	}

	delete base1;

	return (0);
}
