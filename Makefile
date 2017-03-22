all:
	g++ -std=c++11 -pthread -Wall -Wextra filosofo.h tenedor.h filosofo.cpp main.cpp -o main
