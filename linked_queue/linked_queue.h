// Copyright 2017 Fabíola Maria Kretzer
#ifndef STRUCTURES_LINKED_QUEUE_H
#define STRUCTURES_LINKED_QUEUE_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "./linked_list.h"

namespace structures {
/*!Parametro generico para templates*/
template<typename T>
class LinkedQueue:LinkedList<T> {
 public:
/*!Construtor*/
    LinkedQueue():LinkedList<T>::LinkedList() {}
/*!Destrutor*/
    ~LinkedQueue() {
        LinkedList<T>::clear();
    }
/*!Esvazia a fila*/
    void clear() {  //  limpar
        LinkedList<T>::clear();
    }
/*!Coloca um elemento na fila*/
    void enqueue(const T& data) {  //  enfilerar
        Node *novo = new Node(data);
        if (novo == nullptr)
            throw std::out_of_range("LISTA CHEIA");
        if (empty()) {
            LinkedList<T>::head = novo;
            tail = novo;
        } else {
            tail -> next(novo);
            tail = novo;
        }
         LinkedList<T>::size_++;
    }
/*!Retira um elemento na fila*/
    T dequeue() {  // desenfilerar
//        T aux = LinkedList<T>::pop_front();
//        if (empty())
//            tail = nullptr;
//        return aux;
    return LinkedList<T>::pop_front();
    }
/*!Retorna o primeiro dado*/
    T& front() const {  //  primeiro dado
        return LinkedList<T>::at(0);
    }
/*!Retorna o ultimo dado*/
    T& back() const {  //  último dado
        if (empty())
            throw std::out_of_range("LISTA VAZIA!!!");
        return tail -> data();
    }
/*!Booleano de fila vazia*/
    bool empty() const {  //  fila vazia
        return LinkedList<T>::empty();
    }
/*!Retorna o tamanho da fila*/
    std::size_t size() const {  //  tamanho
        return LinkedList<T>::size();
    }
 private :
/*!Node que indica fim*/
    typedef typename LinkedList<T>::Node Node;
    Node* tail{nullptr};  //  nodo-fim
};

}  //  namespace structures

#endif  //  STRUCTURES_LINKED_QUEUE_H
