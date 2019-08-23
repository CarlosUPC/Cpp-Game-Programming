#include <iostream>

int m_Variable = 5; //Declaración y Definición de una variable

extern int m_Var2; //Declaración de una variable -->Extern keyword = linkaje externo, es decir, es lo mismo con las declaraciones y definiciones de funciones, el linker cuando encuentre una llamada de esa variable buscara en otros cpp EXTERNOS al que se ya llamado para buscar su definición.

//Si su definición es static significará que será invisible externamente porlo que el linker no la encontrará xD, ojo con eso.

int main() {

	std::cout << m_Var2 << std::endl;
	std::cout << m_Variable << std::endl;
	std::cin.get();
}