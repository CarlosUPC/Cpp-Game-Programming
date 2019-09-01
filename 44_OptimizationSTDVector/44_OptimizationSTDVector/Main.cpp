#include <iostream>
#include <string>
#include <vector>


//HOW TO USE VECTOR SDT IN A MORE OPTIMAL WAY

//create a vector, push elements, if the mem allocated of vector isnt enough, it reallocates a new mem with enough size and copy old data and spot it in the new location and deletes old location

//id capacity runs out, it performs the resizing. that is a slow operation
struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		:x(x),y(y),z(z)
	{

	}

	Vertex(const Vertex& vertex)
		:x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied!" << std::endl;
	}
};



int main()
{
	//Performance Mistakes std vector does:

	//1: Copying objects constructed on main function stackframe to mem allocated from vector oject

	//2: Resize at runtime capacity of allocate object elements on vector. that means reallocation of new vector with enough mem and copying old and new pushed elements to new allocation and then clean up old allocation

	//HIT: 2 copies in a row when we push back new element 

	std::vector<Vertex> vertices;

	//Copied once
	/*vertices.push_back({ 1, 2, 3 });
	vertices.push_back({ 4, 5, 6 });
	vertices.push_back({ 7, 8, 9 });*/

	std::cout << "=============="<< std::endl;

	//Copied Twice
	/*vertices.push_back(Vertex(1,2,3));
	vertices.push_back(Vertex(4,5,6));
	vertices.push_back(Vertex(7,8,9));*/

	//Optimization tricks:

	//Reserve()
	vertices.reserve(3); //add enough mem that avoid resize in runtime before using push back

	//Emplace_back() --> passing the parameters to construct vertexobject inside mem from vector
	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(7, 8, 9);

	std::cin.get();
}