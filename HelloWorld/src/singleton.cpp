//#include <iostream>
//#define LOG(x) std::cout << x << std::endl;
//
//
////Normally using Singleton requires more code and weird initializaition. 
//
//class Singleton
//{
//private:
//	static Singleton s_Instance;
//	int x = 5;
//public:
//	static Singleton& Get() { return s_Instance; } //returning Singleton& means we return the same s_Instance on very call of Get().
//	int Hi() { return ++x; }
//};
//// Some sort of namespace error if this isn't done...TODO - find more about this
//Singleton Singleton::s_Instance;
//
////-----------------------------------------------------------------------------------------------
//
//// Using static to prolong life of the Singleton intance S gives us the same behaviour as above but with lesser / cleaner code
//
//class Singleton2
//{
//private:
//	int x = 10;
//public:
//	static Singleton2& Get()
//	{
//		static Singleton2 S;
//		return S;
//	}
//	int Hi() { return ++x; }
//};
//int main()
//{
//	int n = Singleton::Get().Hi();
//	LOG(n);
//	n = Singleton::Get().Hi();
//	LOG(n);
//
//	int m = Singleton2::Get().Hi();
//	LOG(m);
//	m = Singleton2::Get().Hi();
//	LOG(m);
//
//	return 0;
//}