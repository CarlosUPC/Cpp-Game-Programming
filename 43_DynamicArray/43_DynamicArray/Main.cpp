#include <iostream>
#include <string>
#include <vector>


//STD: lib filled with containers data
struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

void Function(const std::vector<Vertex>& vertices)//iterator must be refer to avoid copying data
{

}

int main()
{
	Vertex s_vertices[5]; //can't resize data
	Vertex* h_vertices = new Vertex[5]; //can't resize data
	std::vector<Vertex> d_vertices; //can resize dynamically data


	d_vertices.push_back({1,2,3});
	d_vertices.push_back({ 4,5,6 });


	Function(d_vertices);

	for (int i = 0; i < d_vertices.size(); i++)
		std::cout << d_vertices[i] << std::endl;

	for(Vertex& v : d_vertices) //interator must be ref to avoid copying
		std::cout << v << std::endl;


	d_vertices.erase(d_vertices.begin() + 1); //clean up one element

	d_vertices.clear(); //clean up data


	std::cin.get();
}