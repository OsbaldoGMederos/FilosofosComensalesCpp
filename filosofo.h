#ifndef FILOSOFO_H_
#define FILOSOFO_H_

#include <string>
#include <thread>
#include <random>
#include <chrono>
#include <mutex>
#include <iostream>
#include <ctime>

#include "tenedor.h"



class Filosofo{
private:



	const std::string nombre;
	std::mutex& bloqueoCout;
	Tenedor& tenedorIzquierdo;
	Tenedor& tenedorDerecho;
	int contador= 0;


	std::thread trabajador;

public:
	Filosofo(std::string n, std::mutex& bloqueo, Tenedor& i, Tenedor& d)
		: nombre(n), bloqueoCout(bloqueo), tenedorIzquierdo(i), tenedorDerecho(d), trabajador(&Filosofo::iniciar, this){}

	~Filosofo();

	std::string getNombre() const;

	void iniciar();
	void comer();
	void pensar();

	int getContador();

};




#endif /* FILOSOFO_H_ */
