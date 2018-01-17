// Copyright 2017 Fabíola Maria Kretzer && Valdivino Morais da Silva Junior

#ifndef PISTA_H
#define PISTA_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "./array_queue.h"
#include "./Carro.h"

/*!Características da pista do sistema */
class Pista:LinkedQueue<Carro> {
public:
/*!Construtor*/
  Pista(size_t velocidade, size_t tamanhop, size_t frequenciaBase, size_t frequenciaV){
    velocidade_ = velocidade;
    tamanhop_ = tamanho;
    frequenciaBase_ = frequenciaBase;
    frequenciaV_ = frequenciaV;
    espacoUsado_ = 0;
    itensAdicionados_ = 0;
    itensExcluidos_ = 0;
    if(frequenciaBase_ == 0) {
      fonte_ = false;
      sumidouro_ = true;
    } else {
      fonte_ = true;
      sumidouro_ = false;
    }
  }
/*!adicionarCarro carro da pista*/
  void adicionarCarro(Carro carro){
    Carro* carro = ArrayList<Carro>::equeue();
    if (fonte())
      itensAdicionados_++;
  }
/*!Retirar carro da pista*/
  Carro* retirarCarro(){
    Carro* carro = ArrayList<Carro>:dequeue();
    if (sumidouro())
      itensExcluidos_++;
    return carro;
  }
  bool pistaCheia(){
    return tamanhop_ < espacoUsado_ + carro->tamanho();
  }
  size_t velocidade(){
    return velocidade_;
  }
  size_t tamanhop(){
    return tamanhop_;
  }
  size_t frequenciaBase(){
    return frequenciaBase_;
  }
  size_t frequenciaV(){
    return frequenciaV_;
  }
  size_t espacoUsado(){
    return espacoUsado_;
  }
  bool sumidouro(){
    return sumidouro_;
  }
  bool fonte(){
    return fonte_;
  }
protected:
  /*!Tamanho da pista */
      std::size_t tamanhop_;
  /*!Velocidade pista */
      std::size_t velocidade_;
  /*!Frequencia da pista*/
      std::size_t frequenciaBase_;
  /*!Variação da frequencia da pista*/
      std::size_t frequenciaV_;
  /*!Carros que foram foram excluidos */
      std::size_t itensExcluidos_;
  /*!Carros que foram foram excluidos */
      std::size_t itensAdicionados_;
  /*!Espaco da pista utilizado pelos carros */
      std::size_t espacoUsado_;
  /*!Booleno se é sumidouro */
      bool sumidouro_;
  /*!Booleno se é fonte */
      bool fonte_;
}

#endif
