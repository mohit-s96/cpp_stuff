#include <iostream>
#include <string>
#define LOG(x) std::cout << x << std::endl


class String
{
private:
	char* mBuffer;
	unsigned int size;
public:
	String(const char* str)
	{
		size = strlen(str);
		mBuffer = new char[size + 1]; // + 1 because we need space for null termination character
		memcpy(mBuffer, str, size);
		mBuffer[size] = 0; // manually terminate the string with null i.e. 0 or '\0'
	}
	~String()
	{
		delete[] mBuffer;
	}
	friend std::ostream& operator<<(std::ostream& stream, const String& string); // making this function friend of String class means that this function can access the private members of this class.
	char& operator[](const int n) // overload for the [] operator for String instances.
	{
		return mBuffer[n];
	}
	String(const String& other) // this is a copy constructor. It takes an instance of the class i.e. the class to be copied from as a parameter. If we don't use this, we will get same pointer mBuffer for any number of instances with create by copying. This causes crashes.
		// But here we explicitally assign mBuffer with new memory and populate that memory manually.
		:size(other.size)
	{
		LOG("Copied string");
		mBuffer = new char[size + 1];
		memcpy(mBuffer, other.mBuffer, size + 1);
	}
};

std::ostream& operator<<(std::ostream& stream, const String& string) // overload << operator to display String class
{
	stream << string.mBuffer;
	return stream;
}
void printString(const String& str)
{
	LOG(str);
}
int main()
{
	String string("msx47");
	String str(string);
	str[2] = 'y';
	printString(string);
	printString(str);
	/*LOG(string);
	LOG(str);*/
	std::cin.get();
	return 0;
}