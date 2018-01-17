// Copyright 2017 Fabíola Maria Kretzer && Valdivino Morais da Silva Junior

#ifndef EVENTO_H
#define EVENTO_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
/*!Características iniciais do evento */
class Evento {
public:
  Evento(std::size_t tempo, auto* aux) {
    tempo_ tempo;
    aux = aux_;
  }
  size_t tempo(){
    return tempo_;
  }
  auto* aux(){
    return aux_;
  }
  void nasce_carro(Carro carro){
	if(id.FilaCarro[funcao] == 1){
	    if (!full()){
		adiciona_carro(carro);
		cont_nasce++;
	    }
	}
    }
    void passa_carro(Carro carro){
	if(semaforo_Aberto){
	    escolhe_fila(FilaCarro);
	     if (!full()){
		muda_fila(FilaCarro);
	    }
	}
    }
    size_t escolhe_fila(FilaCarro fila){
	probabilidade_ = (size_t) rand%10;
	if(probabilidade_ = 0)
		direita;
	if(probabilidade_ = 1)
		esquerda;
	central;
    }
    void muda_fila(FilaCarro fila){
	 fila = escolhe_fila(fila);
    }
protected:
/*!Tempo do evento*/
  std::size_t tempo_;
/*!Utimo evento*/
  auto* aux_;
}

#endif
