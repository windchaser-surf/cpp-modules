#include "Array.hpp"

template <typename T>
void printarray(unsigned int size, Array<T> arr) {
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    
}

#define MAX_VAL 5

int givenMain() {
	
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    printarray(MAX_VAL, numbers);
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "\nprint tmp\n" << std::endl;
        printarray(tmp.size(), tmp);
        
        std::cout << "\nprint test\n" << std::endl;
        printarray(test.size(), test);
        for (size_t i = 0; i < MAX_VAL; i++)
        {
            tmp[i] = rand();
            test[i] = rand();
        }
        std::cout << "\nAfter chaning values: print numbers\n" << std::endl;
        printarray(numbers.size(), numbers);
        
        std::cout << "\nAfter changing values: print tmp\n" << std::endl;
        printarray(tmp.size(), tmp);
        
        std::cout << "\nAfter chaning values: print test\n" << std::endl;
        printarray(test.size(), test);

    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main () {

	if (givenMain())
		std::cerr << "Given main wasn't completed" << std::endl;

}
