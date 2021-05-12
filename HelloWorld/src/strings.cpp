//#include <iostream>
//#include <string> //stl string class
//#define LOG(x) std::cout << x << std::endl
//
//int main()
//{
//	// strings in c++ are are an array of characters terminated by a null character i.e. '\0'
//	const char* name = "olaamigo";
//	// Since strings are automaticaly terminated by a null character we directly log string to console because the termination point is known.
//
//	LOG(name);
//
//	// If we contruct strings manually we will have to explicitally specify the terminating null character. For eg
//
//	char str[6] = { 'h', 'e', 'l', 'l', 'o', 's'}; // not adding null termination cause bunch of garbage printed
//
//	char str2[7] = { 'h', 'e', 'l', 'l', 'o', 's', '\0' }; // wit null termination hellos prints fine as expected
//
//	std::string newstr = "Hello"; //newstr gets lot of methods thanks to the string stl class
//
//	//std::string str3 = "Hello " + "World"; // this doesn't work because "Hello " and "World" are still const char* pointer type. We can overcome this issue and concatenate strings with the overloaded + using the following 2 ways
//
//	std::string str3 = "Hello ";
//	str3 += "World"; // works fine because now str3 is an actual std::string type instead of const char*
//
//	std::string str4 = std::string("Hello ") + "World"; // This also works fine because std::string constructor creates a new string on the fly and thus we can use + to concatenate;
//
//	LOG(newstr);
//	LOG(str3);
//	LOG(str4);
//
//	LOG(str);
//	LOG(str2);
//
//	//name[2] = 'g'; // not allowed as name is const type. The compiler won't even compile if the name isn't const type.
//	std::cin.get();
//	return 0;
//}