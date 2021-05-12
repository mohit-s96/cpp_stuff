#include <iostream>
#include <vector>
#define LOG(x) std::cout << x << std::endl

struct Vertex
{
	int x, y, z;
	Vertex(const Vertex& other)
		: x(other.x), y(other.y), z(other.z)
	{
		LOG("Copied");
	}
	Vertex(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};
int main()
{
	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(1, 2, 3));
	vertices.push_back(Vertex(1, 2, 3));
	vertices.push_back(Vertex(1, 2, 3));
	std::cin.get();
	return 0;
}