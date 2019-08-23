#include <iostream>

//Resumen: un Constructor se usa para inicializar variables de una clase y se alocate los valores a memoria en el momento que se instancia un objeto para que no haya problemas cuando se haga una llamada a esas variables.

class Entity
{
public:
	float X, Y;

	Entity() { //Si no defines el constructor, realmente sigue teniendo un constructor por default pero con el body empty

		X = 0.0f;
		Y = 0.0f;
	}

	Entity(float x, float y) { //Puedes definir tantos constructores quieras siempre y cuando sean versiones diferentes por su numero de parametros. Algo parecido con los metodos y sus overload metodos
		X = x;
		Y = y;
	}
	void Init() {

		X = 0.0f;
		Y = 0.0f;
	}

	void Print()
	{
		std::cout << X << " , "
			<< Y << std::endl;
	}

};

class Log { //IMPORTANTE: un constructor no se define si no se instancia un objeto de esa clase. Por lo tanto si tratamos con metodos static de una clase, los cuales no requieren de instancias para llamarlas, el constructor no se define!

private:
	Log() {} //hacemos el constructor privado para que sea inaccesible y no pueda crear obj
public:
	Log() = delete; //Le decimos al compiler que no se defina el constructor por defecto
	static void Write() {

	}
};

int main()
{
	Log::Write(); //de esta manera no se generan obj y por lo tanto tampoco sus constructores

	//Log l; //Un objeto no porá ser instanciado si no puede ejecutar su constructor. En el caso que quieras bloquear instancias puedes hacer diferentes estrategias que se explican en la clase Log. Un caso concreto en no querer usar instancias es el de solo tener una clase con vars y metodos static

	Entity e(10.0f, 20.0f);

	// e.Init(); // Soluciona el problema pero aáde extra code. Pro cada instancia necesitas llamar a esta función. La solución son los constructors
	std::cout << e.X << " , " //Error porque no se han inicializado las variables
		<< e.Y << std::endl;
	e.Print(); //No crashea pero se inicializan con valores random en memoria
	std::cin.get();
}