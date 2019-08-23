#include <iostream>


struct Entity
{
	// Todo metodos non-static siempre tienen una instancia de su clase como parametro (hidden) el quan hacen referencia para acceder a su data de la clase 
private:
	int x, y;

public:
	void Print() {
		std::cout << x << "," << y << std::endl;
	}
};

struct StaticEntity
{
	// Key: Los metodos static realmente no tienen class instances! Es decir, es como si no pertenecieran a la clase. No tienen ese parametro instancia hidden que referencia a toda la data de la clase. Por eso no pueden acceder a variables non-static pero porque si a las static? porque esas variables no requieren de un parametro instancia de esa clase para referenciarlas!

	//Uso: proposito organizativo, te interesa tener entre instancias propiedades comunes entre ellas (static data)

	//Resumen: Tienen el mismo efecto que las variables globales, que se linkan externamente por todos los cpp, es decir, al crean variables static en clases o structs, haces como que sean variables globales accesibles a todas las instancias que generes

	static int x, y; //Pueden ser accesibles desde una función non-static y static

	static void Print() { //Funciones static solo pueden acceder a variables static
		std::cout << x << "," << y << std::endl;
	}
};
/*static void Print(Entity e) {   //non-static class methods when its compiled looks like this. Cuando añadimos el static es como si le quitaramos el paremtro escondido y por lo tanto el compilador no sabria que es "e.x y e.y"

	std::cout << e.x << "," << e.y << std::endl;
}*/

int StaticEntity::x;
int StaticEntity::y;

int main() {

	/*Entity e;
	e.x = 2;
	e.y = 3;

	Entity e1 = { 5,8 };

	e.Print();
	e1.Print();
	*/

	
	StaticEntity::x = 2;
	StaticEntity::y = 3;

	
	StaticEntity::x = 5;
	StaticEntity::y = 8;

	StaticEntity::Print();
	

	std::cin.get();
}