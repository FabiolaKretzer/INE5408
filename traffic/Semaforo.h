// Copyright 2017 Fabíola Maria Kretzer && Valdivino Morais da Silva Junior

#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "./linked_list.h"
#include "./Pista.h"

/*!Características da pista do sistema */
class Semaforo {
public:
/*!Construtor*/
  Semaforo(){

  }
  Carro* trocaPista(Carro carro){

  }
  bool fechado(){

  }
protected:
  /*!Guarda uma lista das pistas de destino do semaforo */
    LinkedList<Pista> pistaDestino_;
  /*!Guarda a pista controlada pelo semaforo */
    Pista controlada_;
  /*!Tempo que a pista fica aberta */
    std::size_t tempoAberto_;
  /*!Tempo que a pista ficará aberta pela proxima vez */
    std::size_t proximaVez_;
  /*!Verifica se o semaforo está fechado*/
    bool fechado_;
}

#endif
