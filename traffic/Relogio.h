// Copyright 2017 Fabíola Maria Kretzer && Valdivino Morais da Silva Junior

#ifndef RELOGIO_H
#define RELOGIO_H

//#include "Carro.h"
//#include "Semaforo.h"
//#include "Pista.h"
#include <vector>
#include <memory>
#include <iostream>
#include <string>

/**
 * @brief      Classe que representa os eventos no tempo
 */
class Relogio {
 private:
    const int AberturaLeste = 120;  //  De 0 a 29 aberto para Leste
    const int AberturaNorte = 30;  //  De 30 a 59 aberto Norte
    const int AberturaOeste = 60;  //  De 60 a 89 aberto para Oeste
    const int AberturaSul = 90;  //  De 90 a 119 aberto para Sul
 public:
    Relogio();  // Construtor do relogio
    void newCar();  //  Chegada de um novo carro
    void changeStateSemaphore(int tempo);  // Mudança de estado do semaforo
    void carAtSemaphore();  //  Chegada de carro ao semáforo
    void changeWay();  //  Troca de pista
    bool mudanca_semaforo(int tempo);
    std::vector<int> createCar(int fMin, int aleatorio, int maxTemp);  //  cria um vetor de tempos para inserçã de carros
    };


#endif // RELOGIO_H
