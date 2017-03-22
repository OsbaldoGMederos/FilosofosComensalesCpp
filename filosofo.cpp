/*
 * filosofo.cpp
 *
 *  Created on: 08/03/2017
 *      Author: osbaldo
 */

#include "filosofo.h"

//aqui defino los colores para la console de UNIX|Linux|Mac
//la utilidad de los colores son para el seguimiento más sencillo de los hilos
#define INICIO_ROJO "\033[1;31m"
#define FIN_ROJO "\033[0m"
#define INICIO_VERDE "\033[1;32m"
#define FIN_VERDE "\033[0m"
#define INICIO_AMARILLO "\033[1;33m"
#define FIN_AMARILLO "\033[0m"
#define INICIO_CYAN "\033[1;36m"
#define FIN_CYAN "\033[0m"
#define INICIO_MAGENTA "\033[1;35m"
#define FIN_MAGENTA "\033[0m"

using namespace std;

// bool continuar = true;


//El destructor de la clase para la unificación de cada hilo
//al finalizar la ejecución con la instrucción Join()
Filosofo::~Filosofo() {
	trabajador.join();
	lock_guard<mutex> bloqueoConsola(bloqueoCout);
	cout << nombre << " se fue a dormir." << endl;
}



string Filosofo::getNombre() const {
	return nombre;
}

//este es el proceso que hace un Filosofo durante su existencia
//es un ciclo infinito
void Filosofo::iniciar() {
	lock(tenedorIzquierdo.m, tenedorDerecho.m);
	while (contador < 1) {

		comer();
		pensar();
	}
}

//Primeramente se bloquean ambos tenedores a utilizar,
//para el bloqueo primeramente deben de estar desbloqueados dichos tenedores
//de lo contrario esperarán hasta que estén disponibles ya que los tenedores
//son recibidos por referencia.
void Filosofo::comer() {
	lock_guard<mutex> bloqueoIzquierdo(tenedorIzquierdo.m, adopt_lock);
	lock_guard<mutex> bloqueoDerecho(tenedorDerecho.m, adopt_lock);

	string inicio;
	string fin;

	if(nombre == "Sunny"){
		inicio = INICIO_ROJO;
		fin = FIN_ROJO;
	}
	else if(nombre == "Maribel"){
		inicio = INICIO_CYAN;
		fin = FIN_CYAN;
	}else if(nombre == "Desiree"){
		inicio = INICIO_MAGENTA;
		fin = FIN_MAGENTA;
	}else if(nombre == "Marco"){
		inicio = INICIO_AMARILLO;
		fin = FIN_AMARILLO;
	}else{
		inicio = INICIO_VERDE;
		fin = FIN_VERDE;
	}

	if (true) {
		lock_guard<mutex> bloqueoConsola(bloqueoCout);
		cout << inicio << nombre << " empezo a comer" << fin <<endl;
	}
	for (int i = 0; i < 3; i++) {
		this_thread::sleep_for(chrono::seconds(1));
		lock_guard<mutex> bloqueoConsola(bloqueoCout);
		cout << inicio << nombre << " sigue comiendo" << fin << endl;
	}

	this_thread::sleep_for(chrono::seconds(1));
	lock_guard<mutex> bloqueoConsola(bloqueoCout);
	contador++;
	cout << inicio << nombre << " dejó de comer " << contador << " veces "<< fin << endl;

}

void Filosofo::pensar(){
	srand(time(0));
	int numeroAleatorio = rand() %100;

	string inicio;
	string fin;

	if(nombre == "Sunny"){
		inicio = INICIO_ROJO;
		fin = FIN_ROJO;
	}
	else if(nombre == "Maribel"){
		inicio = INICIO_CYAN;
		fin = FIN_CYAN;
	}else if(nombre == "Desiree"){
		inicio = INICIO_MAGENTA;
		fin = FIN_MAGENTA;
	}else if(nombre == "Marco"){
		inicio = INICIO_AMARILLO;
		fin = FIN_AMARILLO;
	}else{
		inicio = INICIO_VERDE;
		fin = FIN_VERDE;
	}

	bloqueoCout.lock();
	cout << inicio << nombre << " comenzó a pensar en el significado de la vida" << fin << endl;
	bloqueoCout.unlock();
	this_thread::sleep_for(chrono::milliseconds(numeroAleatorio) * 100);

	lock_guard<mutex> bloqueoConsola(bloqueoCout);
	cout << inicio << nombre << " está hambriento otra vez." << fin << endl;
}


int Filosofo::getContador(){
	return contador;
}
