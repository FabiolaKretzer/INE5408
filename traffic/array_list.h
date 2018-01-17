// Copyright 2017 Fabíola Maria Kretzer && Valdivino Morais da Silva Junior

#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
/*!Lista é um conjunto de dados dispostos e/ou acessáveis
em uma sequência determinada.
*/

namespace structures {
/*!Parametro generico para templates*/
template<typename T>
class ArrayList {
 public :
/*!Construtor sem parametros*/
    ArrayList() {
        max_size_ = DEFAULT_MAX;
        contents = new T[max_size_];
        size_ = 0;
    }
/*!Construtor com parametros*/
    explicit ArrayList(std::size_t max_size) {
        max_size_ = max_size;
        contents = new T[max_size_];
        size_ = 0;
     }
/*!Destrutor*/
    ~ArrayList() {
        delete[] contents;
    }
/*!Retita todos os elementos, deixando a lista vazia */
    void clear() {
        size_ = 0;
    }
/*!Insere dado na ultima posição*/
    void push_back(const T& data) {
        insert(data, size());
    }
/*!Insere dado na primeira posição*/
    void push_front(const T& data) {
        insert(data, 0);
    }
/*! Insere  dado na posição indicada*/
    void insert(const T& data, std::size_t index) {
        size_t atual;
        if (full())
            throw std::out_of_range("ERRO LISTA CHEIA!!!");
        if (index > size_ || index < 0)
            throw std::out_of_range("POSIÇÃO INVÁLIDA!!!");
        atual = size_;
        while (atual > index) {
            contents[atual] = contents[atual - 1];
            atual--;
        }
        size_++;
        contents[index] = data;
    }
/*! Insere dado em ordem*/
    void insert_sorted(const T& data) {
        size_t atual;
        if (full())
            throw std::out_of_range("ERRO LISTA CHEIA!!!");
        atual = 0;
        while (atual < size_ && data > contents[atual]) {
            atual++;
        }
        insert(data, atual);
    }
/*! Retira o dado na posição indicada*/
    T pop(std::size_t index) {
        size_t atual;
        T valor;
        if (index >= size_ || index < 0)
            throw std::out_of_range("POSIÇÃO INVÁLIDA!!!");
        if (empty())
            throw std::out_of_range("ERRO LISTA VAZIA!!!");
        size_--;
        valor = contents[index];
        atual = index;
        while (atual <= size_) {
            contents[atual] = contents[atual + 1];
            atual++;
        }
        return valor;
    }
/*! Retira o dado na ultima posição*/
    T pop_back() {
        return pop(size_ - 1);
    }
/*! Retira o dado na primeira posição*/
    T pop_front() {
        return pop(0);
    }
/*! Retira o dado especifico*/
    void remove(const T& data) {
        if (empty())
            throw std::out_of_range("ERRO LISTA VAZIA!!!");
        for (int i = 0; i < size_; i++)
            if (contents[i] == data)
                pop(i);
    }
/*!Testa se a lista está cheia*/
    bool full() const {
        return size_ == max_size_;
    }
/*!Testa se a lista está vazia*/
    bool empty() const {
        return size_ == 0;
    }
/*!Booleano*/
    bool contains(const T& data) const {
        bool estado = false;
        for (int i = 0; i < size_; i++)
            if (contents[i] == data)
                estado = true;
        return estado;
    }
/*!Posição de um elemento do template*/
    std::size_t find(const T& data) const {
        size_t valor = size_;
        if (empty())
            throw std::out_of_range("ERRO LISTA VAZIA!!!");
        for (int i = 0; i <= size_; i++)
           if (contents[i] == data)
                valor = i;
        return valor;
    }
/*! Inicializaçao da variavel generica size*/
    std::size_t size() const {
        return size_;
    }
/*! Inicializaçao da variavel generica max_size*/
    std::size_t max_size() const {
        return max_size_;
    }
/*!Faz comparação se o vetor está ou não dentro dos limites*/
    T& at(std::size_t index) {
        if (empty())
            throw std::out_of_range("ERRO LISTA VAZIA!!!");
        if (index >= size_)
            throw std::out_of_range("POSIÇÃO INVÁLIDA!!!");
        return contents[index];
    }
/*!Acessa direto sem verificar os indices do vetor*/
    T& operator[](std::size_t index) {
        return contents[index];
    }
/*!Faz comparação se o vetor está ou não dentro dos limites*/
    const T& at(std::size_t index) const {
        if (empty())
            throw std::out_of_range("ERRO LISTA VAZIA!!!");
        if (index >= size_)
            throw std::out_of_range("POSIÇÃO INVÁLIDA!!!");
        return contents[index];
    }
/*!Acessa direto sem verificar os indices do vetor*/
    const T& operator[](std::size_t index) const {
        return contents[index];
    }

 private :
    T* contents;
/*!Dados inseridos na lista */
    std::size_t size_;
/*!Indice do elemento topo da lista*/
    std::size_t max_size_;
/*!Tamanho maximo da lista*/
    static const auto DEFAULT_MAX = 10u;
/*static variable, contante usanda como tamanho da pilha*/
};
}/*!namespace structures */

#endif  /*! STRUCTURES_ARRAY_LIST_H */
