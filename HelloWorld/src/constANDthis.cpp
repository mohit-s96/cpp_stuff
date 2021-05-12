//#include <iostream>
//#define LOG(x) std::cout << x << std::endl
//
//class ThisExample; // declare class signature...idk why this is needed, throws an error w/o it. -----------TODO-------------
//void PrintThis(ThisExample* e);
//void PrintThis(const ThisExample& e);
//
//
//// NOTE
//// int* x, y only makes x as a pointer and not y, to get y to be a pointer we write it as int* x, *y
//
//
//class Entity
//{
//private:
//	int x = 100, y = 150;
//	mutable int z = 0;
//public:
//	int GetX() const// another use of const is within member functions inside class. When we write it like this we are promising not the modify the class variables.
//	{
//		// x = 5; // doesn't work because w eare modifying a class member
//		z = 6; // this works because "z" is declared as mutable i.e. we can modify it even inside a const method
//		return x;
//	}
//	void setX(int v)
//	{
//		x = v;
//	}
//};
//
//
//
//class ThisExample
//{
//public:
//	int x, y;
//
//	ThisExample(int x, int y)
//	{
//		// x = x; // doesn't works as it takes the parameter x and assigns it it's owen value. Thus to get a reference to member variables x and y we can use the "this" keyword.
//		this->x = x;
//		this->y = y;
//		// OR we can write as below since this is just a pointer to the current object instance of the class
//		(*this).x = x;
//		(*this).y = y;
//	}
//	int getX() const
//	{
//		return x;
//	}
//	void printX()
//	{
//		PrintThis(this); // PrintThis is an external method which takes an object of ThisExample type. Thus to pass the current object we just pass this
//	}
//	void printXRef()
//	{
//		PrintThis(*this);
//	}
//};
//
//// overloaded function PrintThis. One take a this pointer and another takes a const reference. If the getX method isn't marked as const, the 2nd overload throws an error.
//
//void PrintThis(ThisExample* e)
//{
//	LOG(e->getX());
//}
//void PrintThis(const ThisExample& e)
//{
//	LOG(e.getX());
//}
//
//void printVal(const Entity& e) // this means an Entity reference which shouldn't be modified
//{
//	LOG(e.GetX()); // this works because GetX is marked as const so the compiler knows that we aren't changing the Entity object. If the GetX method wasn't const we will get an error here.
//}
//
//int main()
//{
//	int x = 5;
//	x = 4; // works fine no const
//	int y = 10;
//	// y = 4; //doesn't work because y is const
//
//	int* ptr = new int;
//	*ptr = 5; //dereference and assign value
//	LOG(*ptr); // prints 
//	ptr = (int*)&y; // cast &y to an int pointer and it works fine
//	LOG(*ptr);
//	*ptr = 12; // even though we dereference ptr which is pointing to y, we don't change the value of y in the next line. It still prints 10. This can lead to  crash because the compiler stores y as a read only constant.
//	LOG(y);
//
//	const int* p = new int; // means we won't be able to change the content of the address p points to but we can still modify the pinter itself
//
//	// NOTE : (const int* p) can also be written as (int const* p) and it will have the same meaning
//
//	// *p = 5; // doesn't work because we are modifying the contents of the pointer 
//
//	int* const q = new int; // this here means that we can't reassign the pointer itself but can change the value it contains.
//
//	*q = 5; // works fine
//	// q = (int*)&y; // throws an error as the pointer shouldn't be modified
//
//	p = (int*)&y; // works fine as we are reassigning the pointer and not the value it contains
//
//	printVal(Entity());
//
//	ThisExample T(200, 250);
//	T.printX();
//	T.printXRef();
//
//	std::cin.get();
//	return 0;
//
//}