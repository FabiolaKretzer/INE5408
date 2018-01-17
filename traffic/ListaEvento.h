// Copyright 2017 Fabíola Maria Kretzer && Valdivino Morais da Silva Junior

#ifndef LISTAEVENTO_H
#define LISTAEVENTO_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "./array_list.h"
#include "./Evento.h"

class ListaEvento: private ArrayList<Evento>{
public:
  Evento(){
    ArrayList<Evento>::ArrayList();
  }
  ~Evento(){
    ArrayList<Evento>::~ArrayList();
  }
/*!Esvaziar lista*/
  void esvaziar(){
    if (empty())
        throw std::out_of_range("LISTA VAZIA!!!");
    ArrayList<Evento>::clear();
  }
  void adicionar(Evento evento){
    
  }
  Evento retirar(){

  }

protected:

}

#endif
