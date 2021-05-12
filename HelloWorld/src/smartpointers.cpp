#include <iostream>
#include <memory>
#define LOG(x) std::cout << x << std::endl

class Entity
{
private:
	int x, y;
public:
	Entity()
		: x(5), y(10)
	{
		LOG("Created Entity");
	}
	~Entity()
	{
		LOG("Destroyed Entity");
	}
	int getPosX()
	{
		return x;
	}
};

// smart pointers are used to allocate heap memory but without manually writing new or freeing with delete

int main()
{
	{
		// unique pointers can't be copied
		//std::unique_ptr<Entity> e(new Entity());	// not very safe to exceptions
		//std::unique_ptr<Entity> e1 = std::make_unique<Entity>();	// exception safe
		//// std::unique_ptr<Entity> e2 = e; // doesn't work because copy constructor for unique pointers are deleted
		//LOG(e->getPosX());
		//LOG(e1->getPosX());
	}
	{
		// shared pointers allow copying of pointers. it keeps an internal reference table of the number of references that are still active. Once a reference goes out of scope, it reduces the reference count by one. Once the refrence count reaches zero, it realeases the memory.
		// shared pointers do have a little overhead
		// we should always use "std::make_shared<Entity>" for allocation of shared ptr and not "new Entity()". This is because of the fact that "std::make_shared" allocates the memory needed + the reference count block in one place but if we allocate the memory ourselves using "new Entity()", it will first allocate space for our memory then in another block, the reference count.This is generally less efficient. 
		std::shared_ptr<Entity> e2;
		{
			std::shared_ptr<Entity> e3 = std::make_shared<Entity>(); // reference count => 0 + 1 = 1
			e2 = e3; // copying is allowed also this line increases the reference count by one => 1 + 1 = 2
		} // end of sscope for e2 decreases the reference count by 1 => 2 - 1 = 1
		LOG(e2->getPosX()); // since reference is still not zero, the memory isn't freed and e2 can still access getPosX
	} // reference count decreases by 1 => 1 - 1 = 0
	// thus after the above line the memory for the class is freed up

	{
		// weak pointers are similar to shared pointers in that they can be copied. The difference b/w them is that a weak pointer doesn't increase the reference count.
		std::weak_ptr<Entity> e4;
		{
			std::shared_ptr<Entity> e5 = std::make_shared<Entity>();
			e4 = e5;
		}
		// e4->getPosX(); // throws a compiler error because e4 didn't increase the reference count so after previous line the reference count is 0 and hence the memory is freed.
	}
	std::cin.get();
	return 0;
}