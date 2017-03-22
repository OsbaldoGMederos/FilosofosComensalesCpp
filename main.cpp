/* Creado por Osbaldo Garcia Mederos
 * el día 8 de marzo de 2017*/

#include <iostream>
#include <thread>
#include <vector>
#include <array>
#include <cstdlib>

#include "filosofo.h"
#include "tenedor.h"


using namespace std;

mutex miMutex;

int main() {

	array<Tenedor, 5> tenedores;
	array<Filosofo,5> filosofos{{
		{"Daniela", miMutex, tenedores[0], tenedores[1]},
		{"Marco", miMutex, tenedores[1], tenedores[2]},
		{"Sunny", miMutex, tenedores[2], tenedores[3]},
		{"Maribel",miMutex, tenedores[3], tenedores[4]},
		{"Desiree", miMutex, tenedores[4], tenedores[0]},

	}};

	return 0;
}
