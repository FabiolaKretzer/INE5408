//  Copyright 2017 <Fabíola Maria Kretzer>
#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint>   // std::size_t
#include <stdexcept>   // C++ Exceptions
/*!Estrutura de dados do tipo Fila,
  que organiza os elementos na forma
  o primeiro a entrar é o primeiro a sair!!!
*/
namespace structures {
/*!Parâmetro genérico para templates.
*/
template<typename T>
class ArrayQueue {
 public:
/*!Construtor sem parametros
*/
    ArrayQueue() {
        max_size_ = DEFAULT_SIZE;
        contents = new T[max_size_];
        size_ = -1;
    }
/*!Construtor com parametros
*/
    explicit ArrayQueue(std::size_t max) {
        max_size_ = max;
        contents = new T[max_size_];
        size_ = -1;
    }
/*!Destrutor
*/
    ~ArrayQueue() {
        delete[] contents;
    }
/*! Colocar elementos na fila
*/
    void enqueue(const T& data) {
         if (full())
            throw std::out_of_range("ERRO FILA CHEIA!!!");
        size_ = size_ + 1;
        contents[size_] = data;
    }
/*! Retirar o primeito elemento da fila
*/
    T dequeue() {
        if (empty())
            throw std::out_of_range("ERRO FILA VAZIA!!!");
        T temp = contents[0];
        for (int i = 0; i < size_ ; i++) {
                contents[i] = contents[i + 1];
        }
        size_ = size_ - 1;
        return temp;
    }
/*! Elementos da fila
\retorna uma referencia
*/
    T& back() {
        if (empty())
            throw std::out_of_range("ERRO FILA VAZIA!!!");
        return contents[size_];
    }
/*! Retirar todos os elementos, deixando a fila vazia da fila
*/
    void clear() {
        size_ =  -1;
    }
/*! Inicializaçao da variavel generica size
*/
    std::size_t size() {
        return size_ + 1;
    }
/*! Inicializaçao da variavel generica max_size
*/
    std::size_t max_size() {
        return max_size_;
    }
/*! Testa se a fila está vazia
*/
    bool empty() {
        return size_ == -1;
    }
/*! Testa se a fila está cheia
*/
    bool full() {
        return size_ == max_size_ - 1;
    }
 private :
    T* contents;
/*!Dados inseridos na fila */
    std::size_t size_;
/*!Indice do elemento topo da fila*/
    std::size_t max_size_;
/*!Tamanho maximo da fila*/
    static const auto DEFAULT_SIZE = 10u;
/*static variable, contante usanda como tamanho da pilha*/
};
}/*!namespace structures */

#endif  /*! STRUCTURES_ARRAY_QUEUE_H */
