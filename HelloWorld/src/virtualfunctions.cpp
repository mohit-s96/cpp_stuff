#include <iostream>
#define LOG(x) std::cout << x << std::endl

// Virtual functions and interfaces

class Card
{
public:
	// Here we declare that Card class has a pure virtual method called getCardType. This means all the sub-types (inherited) classes from Card must implement the getCardType method to be able to instantiate objects from them.
	virtual const char* getCardType() = 0;
};

class Buildings : public Card
{
public:
	// we define the getCardType function in the class Building which is an implementation on the interface class 'Card'
	// override keyword isn't needed but its good practice
	const char* getCardType() override
	{
		return "building";
	}
};

// Defensive doesn't need to implement getCardType because its inheriting from Buildings which has already implemented getCardTypes. 
// But if we don't implement it here we will get the "building as the ouput of print instead of Defensive building"

class Defensive : public Buildings
{
public:
	const char* getCardType() override
	{
		return "Defensive Building";
	}
};

// This function takes a pointer of type Card and logs the result of the getCardTypes method on that pointer object. Since getCardType in Card is a pure virtual function, we can be assured that any pointer instance passed to PrintCardTypes will definitely have the getCardType method.

void PrintCardType(Card* c)
{
	LOG(c->getCardType());
}

int main()
{
	Buildings* b = new Buildings();
	Defensive* d = new Defensive();

	PrintCardType(b);
	PrintCardType(d);
}




