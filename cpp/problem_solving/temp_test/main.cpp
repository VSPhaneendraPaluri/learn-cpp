#include <iostream>

class A {
public:
	void Foo() {}
};

class B : public A {
public:

};

int main()
{
	B b;
	A* a = &b;
	a->Foo();
	std::cout << typeid(*a).name() << std::endl;
	return 0;
}