// Copyright 2017 Fabíola Maria Kretzer
#ifndef STRUCTURES_LINKED_STACK_H
#define STRUCTURES_LINKED_STACK_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "./linked_list.h"

namespace structures {
/*!Parametro generico para templates*/
template<typename T>
class LinkedStack: private LinkedList<T>{
 public:
/*!Construtor*/
    LinkedStack():LinkedList<T>::LinkedList() {}
/*!Destrutor*/
    ~LinkedStack() {
        LinkedList<T>::~LinkedList();
    }
/*!Esvazia a pilha*/
    void clear() {  // limpa pilha
        LinkedList<T>::clear();
    }
/*!Coloca um elemento na pilha*/
    void push(const T& data) {  // empilha
        try {
            LinkedList<T>::push_front(data);
        } catch (std::out_of_range erro) {
            throw erro;
        }
    }
/*!Retira o primeiro elemento e vai retirando até acabar*/
    T pop() {  // desempilha
        try {
            return LinkedList<T>::pop_front();
        } catch (std::out_of_range erro) {
            throw erro;
        }
    }
/*!Retorna o dado do topo*/
    T& top() const {  // dado no topo
        try {
        return LinkedList<T>::at(0);
        } catch (std::out_of_range erro) {
            throw erro;
        }
    }
/*!Testa se a lista está vazia*/
    bool empty() const {  // pilha vazia
        return LinkedList<T>::empty();
    }
/*! Inicializaçao da variavel generica size*/
    std::size_t size() const {  // tamanho da pilha
        return LinkedList<T>::size();
    }
};

}  //  namespace structures

#endif  //  STRUCTURES_LINKED_STACK_H
