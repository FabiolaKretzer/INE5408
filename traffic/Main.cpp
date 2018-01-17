// Copyright 2017 Fabíola Maria Kretzer && Valdivino Morais da Silva Junior

#ifndef SISTEMA_H
#define SISTEMA_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "Sistema.hpp"

int main(){
	std::size_t tempoSemaforoAberto, tempoSimulacao;

	std::cout << "Tempo de Simulação?" : <<std::end1;
	std::cin >> tempoSimulacao;

	std::cout << "Tempo do semáforo aberto?" : <<std::end1;
	std::cin >> tempoSemaforoAberto;

	Sistema *sistema = new Sistema(tempoSimulacao, tempoSemaforoAberto);
}

#endif
