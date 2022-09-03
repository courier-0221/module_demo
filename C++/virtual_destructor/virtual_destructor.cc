#include <iostream>

namespace noVirtualDtor
{
class Base
{
public:
    Base() { std::cout << "Base constructor" << std::endl; _arr = new int[10]; }
    ~Base() { std::cout << "Base decstructor" << std::endl; delete[] _arr; }
private:
    int* _arr;
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived constructor" << std::endl; _strarr = new char[10]; }
    ~Derived() { std::cout << "Derived decstructor" << std::endl; delete[] _strarr; }
private:
    char* _strarr;
};

void test(void)
{
    Base* base = new Base();
    delete base;
    std::cout << "------------------------\n";
    Derived* derived = new Derived();
    delete derived;
    std::cout << "------------------------\n";
    Base* tmp = new Derived();  //memory leak -- Derived dtor no call
    delete tmp;
}
}

namespace hasVirtualDtor
{
class Base
{
public:
    Base() { std::cout << "Base constructor" << std::endl; _arr = new int[10]; }
    virtual ~Base() { std::cout << "Base decstructor" << std::endl; delete[] _arr; }
private:
    int* _arr;
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived constructor" << std::endl; _strarr = new char[10]; }
    ~Derived() { std::cout << "Derived decstructor" << std::endl; delete[] _strarr; }
private:
    char* _strarr;
};

void test(void)
{
    Base* base = new Base();
    delete base;
    std::cout << "------------------------\n";
    Derived* derived = new Derived();
    delete derived;
    std::cout << "------------------------\n";
    Base* tmp = new Derived();
    delete tmp;
}
}


int main(void)
{
    //noVirtualDtor::test();
    hasVirtualDtor::test();
	return 0;
}
