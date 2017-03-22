/*
 * tenedor.h
 *
 *  Created on: 07/03/2017
 *      Author: osbaldo
 */

#ifndef TENEDOR_H_
#define TENEDOR_H_

#include <mutex>

class Tenedor{
public:

	std::mutex m;
};




#endif /* TENEDOR_H_ */
