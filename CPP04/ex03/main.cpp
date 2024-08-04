#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

//Checks all protection of learnMateria 
// - full list 
// - NULL Pointer

void testcase1()
{
    IMateriaSource *src = new MateriaSource();
    ICharacter *dest = new Character();
    AMateria* uselessCatcher[10];

    for (int i = 0; i < 10; i++)
    {
        uselessCatcher[i] = NULL;
    }
    if(uselessCatcher[0]) //Check if Default Constructor is NULL! 
        delete uselessCatcher[0];

    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    src->learnMateria(NULL); 
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    
    dest->equip(src->createMateria("ice")); //Valid
    dest->equip(src->createMateria("Ice")); //Invalid
    dest->equip(src->createMateria("hot")); //Invalid!!
    dest->equip(src->createMateria("cure")); //Valid
    dest->equip(src->createMateria("ice")); //Valid
    dest->equip(src->createMateria("cure")); //Valid
    dest->equip(src->createMateria("ice")); //Valid -> Overflow!

    uselessCatcher[0] = ((Character *)(dest))->getMemAdr(3);
    dest->unequip(3);
    if (uselessCatcher[0] != NULL)
        delete uselessCatcher[0];
    uselessCatcher[0] = NULL;

    dest->equip(src->createMateria("cure")); //Equiped idx 3;
    
    uselessCatcher[1] = ((Character *)(dest))->getMemAdr(0);
    dest->unequip(0);
    if (uselessCatcher[1] != NULL)
        delete uselessCatcher[1];
    uselessCatcher[1] = NULL;

    dest->equip(src->createMateria("ice")); //Equiped idx 0; 

    uselessCatcher[1] = ((Character *)(dest))->getMemAdr(8); //Check if idx are protected!!
    dest->unequip(9);
    if (uselessCatcher[1] != NULL)
        delete uselessCatcher[1];
    uselessCatcher[1] = NULL;

    ICharacter *flori = new Character("Flori");
    ICharacter *nicooo = new Character("Nicooo"); 


    dest->use(0, *flori); // ice
    dest->use(1, *nicooo); // cure

    delete flori;
    delete nicooo;
    delete src;
    delete dest;
}

void    testnico()
{
    AMateria* uselessCatcher[10];

    for (int i = 0; i < 10; i++)
    {
        uselessCatcher[i] = NULL;
    }
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n===Extra===\n" << std::endl;

    me->equip(NULL);
    me->use(2, *bob);

    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    uselessCatcher[0] = ((Character *)(me))->getMemAdr(0);
    me->unequip(0);
    if (uselessCatcher[0] != NULL)
        delete uselessCatcher[0];
    uselessCatcher[0] = NULL;

    uselessCatcher[0] = ((Character *)(me))->getMemAdr(0);
    me->unequip(0);
    if (uselessCatcher[0] != NULL)
        delete uselessCatcher[0];
    uselessCatcher[0] = NULL;

    uselessCatcher[0] = ((Character *)(me))->getMemAdr(0);
    me->unequip(0);
    if (uselessCatcher[0] != NULL)
        delete uselessCatcher[0];
    uselessCatcher[0] = NULL;

    uselessCatcher[0] = ((Character *)(me))->getMemAdr(0);
    me->unequip(0);
    if (uselessCatcher[0] != NULL)
        delete uselessCatcher[0];
    uselessCatcher[0] = NULL;

    uselessCatcher[0] = ((Character *)(me))->getMemAdr(0);
    me->unequip(0);
    if (uselessCatcher[0] != NULL)
        delete uselessCatcher[0];
    uselessCatcher[0] = NULL;

    uselessCatcher[0] = ((Character *)(me))->getMemAdr(1);
    me->unequip(1);
    if (uselessCatcher[0] != NULL)
        delete uselessCatcher[0];
    uselessCatcher[0] = NULL;

    uselessCatcher[0] = ((Character *)(me))->getMemAdr(2);
    me->unequip(2);
    if (uselessCatcher[0] != NULL)
        delete uselessCatcher[0];
    uselessCatcher[0] = NULL;

    uselessCatcher[0] = ((Character *)(me))->getMemAdr(3);
    me->unequip(3);
    if (uselessCatcher[0] != NULL)
        delete uselessCatcher[0];
    uselessCatcher[0] = NULL;


    delete src;
    src = new MateriaSource();

    tmp = src->createMateria("ice");
    src->learnMateria(new Ice());
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    tmp = src->createMateria("blah");

    ICharacter* copy = new Character(*static_cast<Character *>(me));
    delete me;

    IMateriaSource* matcopy = new MateriaSource(*static_cast<MateriaSource *>(src));
    delete src;

    tmp = matcopy->createMateria("lllll");
    tmp = matcopy->createMateria("ice");
    copy->equip(tmp);
    copy->use(0, *bob);
    copy->use(1, *bob);
    uselessCatcher[0] = ((Character *)(copy))->getMemAdr(3);
    copy->unequip(2);
    if (uselessCatcher[0] != NULL)
        delete uselessCatcher[0];
    uselessCatcher[0] = NULL;

    delete bob;
    delete copy;
    delete matcopy;
}

void    testcaseFlori() 
{
    IMateriaSource* src1 = new MateriaSource();
    src1->learnMateria(new Ice());
    src1->learnMateria(new Cure());
    src1->learnMateria(NULL);

    IMateriaSource* src2 = new MateriaSource();
    src1->learnMateria(new Ice());
    src1->learnMateria(new Cure());
    src1->learnMateria(new Cure());
    src1->learnMateria(new Cure());
    src1->learnMateria(new Cure());

    *(MateriaSource *)src2 = *(MateriaSource *)src1;

    ICharacter  *p1 = new Character("player 1");
    std::cout << "Name of p1: '" << p1->getName() << "'" << std::endl;

    p1->unequip(-1);
    p1->unequip(0);
    p1->unequip(4);

    AMateria*   ice = src1->createMateria("ice");
    AMateria*   cure = src1->createMateria("cure");

    AMateria*   ice_wrong = src1->createMateria("Ice");
    AMateria*   cure_wrong = src1->createMateria("Cure");

    if (ice_wrong != NULL || cure_wrong != NULL)
        std::cout << "ERROR" << std::endl;

    p1->use(-1, *p1);
    p1->use(0, *p1);
    p1->use(4, *p1);

    p1->equip(NULL);
    p1->equip(ice);
    p1->equip(cure);

    p1->use(0, *p1); //ice at player1
    p1->use(1, *p1); //cure at player1

    ICharacter  *p2 = new Character("player 2");
    std::cout << "\nName of p2: '" << p2->getName() << "'" << std::endl;

    p2->use(-1, *p2);
    p2->use(0, *p2);
    p2->use(4, *p2);

    AMateria*   cure_2 = src1->createMateria("cure");

    p2->equip(cure_2);

    p2->use(0, *p2); //cure at player2

    *(Character *)p2 = *(Character *)p1;

    ICharacter  *p3 = new Character("player 3");

    p2->use(0, *p2); //ice at player1
    p2->use(1, *p3); //cure at player3
    p2->use(2, *p2);

    delete (p1);
    delete (p2);
    delete (p3);

    delete (src1);
    delete (src2);
}

int main() {

    testcase1();

    std::cout << "\n\n ++++++NICO TESTCASE+++++++\n\n"; 

    testnico();

    std::cout << "\n\n ++++++FLORI TESTCASE+++++++\n\n"; 

    testcaseFlori();
/*     Character bob("bob");
   // Character *jim = new Character("jim");
    bob.equip(new Ice());
    bob.equip(new Cure());
    bob.equip(new Ice());
    bob.equip(new Cure());
    bob.equip(new Ice()); */

/*     IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);



    AMateria*   temporary[10];
    temporary[0] = ((Character *)(me))->getMemAdr(0);
    me->unequip(0);
    delete temporary[0];

    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src; */

    return 0;



    return (0);
}
