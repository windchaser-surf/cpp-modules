#include "Base.hpp"
#include "AClass.hpp"
#include "BClass.hpp"
#include "CClass.hpp"

///////////////////////Exception messages////////////////////////

const char* Base::ClassNotFound::what() const throw() {

	return "Non of these 3 three classes are identified!";
}


//////////////////////Member functions///////////////////////////

Base* Base::generate() {

	int random; 

	std::srand(std::time(0));
	random = std::rand() % 3;
	
	if (random == 0) {
		
		std::cout << "AClass will generate" << std::endl;
		return (new AClass());
	}
	else if (random == 1){
		
		std::cout << "BClass will generate" << std::endl;
		return (new BClass());
	}
	else{

		std::cout << "CClass will generate" << std::endl;
		return (new CClass());
	}
}

void Base::identify(Base* p) {


	if (p == NULL)
		throw ClassNotFound();
	else if (dynamic_cast <AClass*> (p))
		std::cout << "AClass identified!" << std::endl;
	else if (dynamic_cast <BClass*> (p))
		std::cout << "BClass identified!" << std::endl;
	else if (dynamic_cast <CClass*> (p))
		std::cout << "CClass identified!" << std::endl;
	else 
		throw ClassNotFound();
}

void Base::identify(Base& p) {

	Base ret;
	
	try {
		ret = dynamic_cast <AClass &> (p);
		std::cout << "AClass identified with dynamic_cast to a reference!" << std::endl;
		return ;
	}
	catch (std::exception& e) {

		std::cerr << "Identify AClass failed!" << std::endl;
	}

	try {
		ret = dynamic_cast <BClass &> (p);
		std::cout << "BClass identified with dynamic_cast to a reference!" << std::endl;
		return ;
	}
	catch (std::exception& e) {

		std::cerr << "Identify BClass failed!" << std::endl;
	}

	try {
		ret = dynamic_cast <CClass &> (p);
		std::cout << "CClass identified with dynamic_cast to a reference!" << std::endl;
		return;
	}
	catch (std::exception& e) {

		std::cerr << "Identify BClass failed!" << std::endl;
	}

}

Base::~Base() {

	std::cout << "Base deleted" << std::endl; 
}

