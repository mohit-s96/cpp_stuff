#include <iostream>
#include <array>
#define log(x) std::cout << x << std::endl


class entity
{
public:
	int arr[5]; // this array resides inside the memory space for the entity class objet.
	int* newarr = new int[5]; // this causes memory indirection as what newarr actually is is a pointer to another block of memory allocated on the heap. thus to access the actual array we jump around memory which causes a performance hit.
	entity()
	{
		for (int i = 0; i < 5; i++)
		{
			arr[i] = i;
		}
	}
};

int main()
{
	int arr[5]; // stack allocated
	int* ptr = arr;	// arrays are pointers to a contigous block of memory so this is a valid expression
	int* newarr = new int[5]; // heap allocated so  they won't be destroyed with scope and have to be freed with delete[]
	
	//---------------------------------------------------------------------------------------------------------------------------

	// c++ doesn't maintain the size of arrays. we either have to use the builtin array type or we have to maintain the size ourselves.

	const int size = 5; // const because array size must be known at compile time
	int another[size];

	// using the array class provided by c++ stl (must include array)

	std::array<int, 5> safearray; // creates an array on the stack of int type and size 5. keeps check of memory access violations and keeps track of the size of the array

	for (int i = 0; i < safearray.size(); i++) // .size() is one of the many methods provided by the std::array class.
	{
		safearray[i] = i;
	}

	entity e;
	
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i;
	}

	arr[2] = 69; // this expression takes the arr pointer. offsets it by 2*4(see below for reasoning) and the dereferences it to change the value to 69

	*(ptr + 2) = 420; // same operation as above but we offset the pointer explicitally. since arr is int type the offset bytes are calclulated using (index * sizeof(int) and thus ptr get 8 bytes offset and then writes to memory after the 8 bytes). we can get more precise byte level control using typecasting as shown below.

	*(int*)((char*)ptr + 8) = 8; // we cast ptr to a be a pinter to a char type thus when calculating offset it will use (8 * sizeof(char)) and since sizeof char is 1, we get byte level control. we offset 8 bytes from the start then cast back the char pointer back to int pointer and dereference it to chane the value. same effect as above but with more fine grained control.

	delete[] newarr;

	log(arr);
	std::cin.get();
	return 0;
}