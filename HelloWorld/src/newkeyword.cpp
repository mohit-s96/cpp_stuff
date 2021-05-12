#include <iostream>
#define LOG(x) std::cout << x << std::endl;

class Example
{
public:
	Example()
		: x(0), y(0) {
		LOG("Called");
	}
	~Example()
	{
		LOG("Destroyed");
	}
	void logSomething()
	{
		LOG(x);
	}
	void logSomething(int a)
	{
		LOG(a);
	}

private:
	int x, y;
};

int main()
{
	Example e; // This allocates memory on the stack. Instance e gets memory of size "sizeof(Example)" allocated to on the stack. 
			   // Its faster than allocating on the heap with the new keyword or malloc.
			   // It calls the constructor automatically.
			   // Shouldn't be used for large classes where a lot of memory is to be allocated because stack size is ususally small (like 1mb or 2).
			   // Doesn't need to be freed up because its deleted once the stack frame is done executing
	e.logSomething(); // e.logSomething() works fine because e is an actual instance of Example rather than being a pointer to a memory						// location
	Example* e1 = new Example();
			   // This allocate memory on the heap. The new keyword looks up memory to find contigous chunk of "sizeof(Example)" bytes of memory and returns a pointer which points to the first byte of the allocated memory.
			   // The lookup takes some time so its slower than allocating on the stack.
			   // Calls the Class contructor automatically.
			   // Can be used to allocate large chunks of memory.
			   // Memory needs to be freed up manually using delete/
			   // In most compilers new keyword (which is an operator) calls the C - Language malloc() under the hood.
			   // So it can be like Example e1 = (Example*)malloc(sizeof(Example))
			   // The difference is that malloc doesnt automatically call the class constructor so in most of the situations it should be avoided.
			   // e1.logSomething() will not work because e1 is a pointer to memory allocated by new
			   // to use methods with e1 we do the following
	(*e1).logSomething(); 
			   // Here we dereference the pointer e1 so we can access the contents of the memory address it points to.
			   // This works fine but a nicer way of doing the same thing is with the arrow operator
	e1->logSomething();
			   // This has the same effect as the dereferencing methond but its easier to read and has cleaner syntax.


			   //-----------------------------------------------------------------------------------------------------------------------

			   // Apart from Class intances we can also allocated primitives on the heap. For eg
	int* x = new int; // allocates 4 bytes on heap (usually depending on the application nad compiler)
			   // x points to the memory address of the int allocated by new. Just like classes this also needs to be freed manually.

	int* y = new int[50]; // 200 bytes on the heap
			  // y points to the starting byte of the contigous block of memory allocated by new.

			  // we can also make array of Object instances
	Example* e2 = new Example[50];
			  // Allocates space equivalent of (50*sizeof(Example)) on the heap and returns a pointer to the starting byte.

			  // It should be noted that new for allocating single data type for eg. new Example or new int is different from new[] for allocating array types like new int[50], new Example[50]

			  //--------------------------------------------------------------------------------------------------------------------------

			  // Example to check memory allocated on heap
	
	//LOG(sizeof(Example));
	//for (int i = 0; i < 50; i++)
	//{
	//	e2[i].logSomething((int)&e2[i]); // we can see here that contigous 8 bytes memory is allocated for e2 since e2 is 2 ints(4 + 4)bytes
	//}


			  // Freeing up memory
	delete x;
	delete e1;
			 // This clears / frees up the heap memory allocated by the new keyword.
			 // Automatically calls the destructor method of the class.
			 // Uses C- Language free() function under the hood.

	delete[] y;
	delete[] e2;
			// Just like new and new[] are slightly different, so is delete and delete[]. One should always use delete[] when freeing a memory block allocated as an array by new.
		
	return 0;
}