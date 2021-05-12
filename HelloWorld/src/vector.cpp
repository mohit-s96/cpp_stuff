//#include <iostream>
//#include <vector>
//#define LOG(x) std::cout << x << std::endl
//
//// vector in c++ is a dynamic array. We can assign a new vector array and add elements or delete them whenever we want and it dynamically changes its size. When we exceed an allocated size, vector creates a new array with required size and copies elements from old array to the new array and thus we have dynamic arrays.
//struct Vertex
//{
//	float x, y, z;
//};
//std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
//{
//	stream << vertex.x << vertex.y << vertex.z;
//	return stream;
//}
//int main()
//{
//	//Vertex* vertices = new Vertex[10]; // problem with this is a hard limit of 10. If a user wants to enter more data, they can't. Thus to solve this problem we have the vector class which allows us to create dynamic arrays.
//	std::vector<Vertex> vertices; // this vector contains data of Vertex type. This means we have complete objects of Vertex type in vertices and not the pointers to them. There are cases where storing as object pointers is better and then there are cases where storing it contigously is better. More on this later -----------TODO-----------
//	vertices.push_back({ 1, 2, 3 });
//	vertices.push_back({ 4, 5, 6 });
//	for (unsigned int i = 0; i < vertices.size(); i++)
//		LOG(vertices[i]);
//
//	// OR using range based for loop
//	for (const Vertex& v : vertices)  // read as vor Vertex v in vertices vector
//		// make Vertex a reference to avoid copying for each iteration. What happens is that for every object in vertices, we copy that object into the scope of the for loop thus making a performance issue. So we need to pass it as a reference so that no copies are created
//		LOG(v);
//
//	// Clear the vector
//	//vertices.clear();
//
//	// remove one element
//	vertices.erase(vertices.begin() + 1);
//
//	for (const Vertex& v : vertices)
//		LOG(v);
//
//	std::cin.get();
//	return 0;
//}