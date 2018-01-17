// Copyright 2017 Fabíola Maria Kretzer && Valdivino Morais da Silva Junior

#ifndef FILA_CARRO_H
#define FILA_CARRO_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "./array_queue.h"
#include "./Carro.h"

/*!Fila de carros é uma herança da fila vetor */
class FilaCarro: private ArrayQueue<Carro>{
public:
/*!Construtor */
  Fila_Carro(std::size_t max_size, std::size_t espaco, std::size_t id, std::size_t probabilidade, std::size_t funcao, std::size_t t_travessia){
    id_ = id;
    probabilidade_ = probabilidade;
    funcao = funcao;
    travessia = travessia;
    max_size_ = max_size;
    espaco_ = espaco;
    ArrayQueue<Carro>::ArrayQueue();
  }
/*!Destrutor */
  ~Fila_Carro(){
    ArrayQueue<Carro>::ArrayQueue();
  }
/*!Esvaziar fila */
  void esvaziar(){
    if (empty())
        throw std::out_of_range("LISTA VAZIA!!!");
    ArrayQueue<Carro>::clear();
  }
/*!Adicionar elementos na fila(utilizei data porque é um parametro da fila) */
  void adiciona_carro(Carro carro){
    auto i = espaco_;
    i = i + tamanho();
    if(i < tamanhop_)//tamanho da pista, classe pista
      ArrayQueue<Carro>::enqueue(carro);
    throw std::out_of_range("LISTA CHEIA!!!");
  }
  void 
/*!Retira elementos na fila */
  Carro retirar(){
    if (empty())
        throw std::out_of_range("LISTA VAZIA!!!");
    Carro carro = ArrayQueue<Carro>::dequeue();
    return carro;
  }
/*!Retorna primeiro carro */
  Carro primeiro(){
    ArrayQueue<Carro>::front();
  }
  /*!Retorna ultimo carro */
  Carro ultimo(){
    ArrayQueue<Carro>::back();
  }
/*!Verifica se a fila esta vazia */
  bool empty() const {  //  fila vazia
      return ArrayQueue<Carro>::empty();
  }
/*!Verifica se a fila esta cheia */
  bool full() const {  //  fila cheia
      return  tamanho() + espaco_ >= size_;
  }
/*!Retorna o tamanho da fila*/
  std::size_t size() const {  //  tamanho
    return size_;
  }
/*!Retorna o espaco atual da fila*/
  std::size_t espaco() const {  //  tamanho
    return espaco;
  }
/*!Retorna o tamanho da fila*/
  std::size_t max_size() const {  //  tamanho
    return max_size_;
  }
  std::size_t id() const {  //  tamanho
    return id_;
  }
  std::size_t probabilidade() const {  //  tamanho
    return probabilidade_;
  }
  std::size_t funcao() const {  //  tamanho
    return funcao_;
  }
  std::size_t t_travessia() const {  //  tamanho
    return t_travessia_;
  }
  std::size_t frequencia() const {  //  tamanho
    return frequencia_;
  }
protected:
/*!Tamanho da fila*/
  std::size_t size_;
/*!Tamanho da pista*/
  std::size_t espaco_, max_size_;
  std::size_t id_, probabilidade;
  std::size_t funcao_;
  std::size_t t_travessia_, frequencia_;

}
#endif
