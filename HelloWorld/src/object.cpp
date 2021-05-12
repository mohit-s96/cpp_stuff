//// Comments go from Point - 1 to Point - 3 
//
//#include <iostream>
//#define LOG(x) std::cout << x << std::endl;
//
//
//class Example
//{
//private:
//	int x;
//public:
//	Example()
//	{
//		LOG("Called");
//		x = 0;
//	}
//	Example(int n)
//	{
//		LOG("Called with value");
//		x = n;
//	}
//};
//
//class Player
//{
//private:
//	int posX, posY;
//	Example e; // Point - 1 ->>>> Declare instance of Example class here. If member list initialixation isn't used, the Example constructor gets called here first when Player instance is created.
//public:
//	Player()
//		// Point - 3 ->>>> Instead we can use member list initialization which prevents the extra call when initializing Example instance.
//		// Note that member list initialization should follow the same order in which the members were declared.
//		// i.e. if in the line below I wrote e(8), posX(0), posY(0), it would be an issue as posX would be assigned value of e 
//		: posX(0), posY(0), e(8) {
//
//		
//		//   e = Example(8);	
//		// Point - 2 ->>>> Initialize Example instance in player constuctor. Since Example constructor is called here once again we have one wasted call and thus a performance issue.
//	}
//	void getPlayerPos()
//	{
//		LOG(posX);
//		LOG(posY);
//	}
//	void setPlayerPos(int x, int y)
//	{
//		posX = x;
//		posY = y;
//	}
//};
//
//int main()
//{
//	Player p;/*
//	p.getPlayerPos();
//	p.setPlayerPos(5, 10);
//	p.getPlayerPos();*/
//	return 0;
//}