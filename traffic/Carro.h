// Copyright 2017 Fabíola Maria Kretzer && Valdivino Morais da Silva Junior

#ifndef CAR_H
#define CAR_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

/*!Características do carro para o sistema */
class Carro {
public:
/*!Construtor*/
	Carro() {
		tamanhoCarro();
	}
/*!Gera o tamnho do carro através de uma função randomica*/
	void tamanhoCarro() {
			tamanho_ = (size_t) (rand()%5) + 1 + 2;
	}
/*!Retorna tamanho do carro*/
	std::size_t tamanho() const {
			return tamanho_;
	}
protected:
	/*!Tamanho do carro*/
		std::size_t tamanho_;
}

#endif
