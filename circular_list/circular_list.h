// Copyright 2017 Fabíola Maria Kretzer
#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

/*!A lista circular é uma lista encadeada,
 só que o último elento aponta para o primeiro
 */

namespace structures {
/*!Parametro generico para templates*/
template<typename T>
class CircularList {
 public :
    /*!Construtor sem parametros, ja contém os valores inicializados*/
    CircularList() {}
    /*!Destrutor*/
    ~CircularList() {
        clear();
    }
    /*!Retira todos os elementos, deixando a lista vazia */
    void clear() {  //  limpar lista
        while (!empty())
            pop_front();
    }
    /*!Insere dado na ultima posição*/
    void push_back(const T& data) {  //  inserir no fim
        if (empty()) {
            push_front(data);
        } else {
            Node* novo = new Node(head->data(), head->next());
            if (novo == nullptr) {
                throw std::out_of_range("ERRO LISTA CHEIA!!!");
            }
            head->next(novo);
            head->data() = data;
            head = novo;
            size_++;
        }
    }
/*!Insere dado na primeira posição*/
    void push_front(const T& data) {  //  inserir no início
        Node* novo = new Node(data);
        if (novo == nullptr) {
            throw std::out_of_range("ERRO LISTA CHEIA!!!");
        }
        if (empty()) {
            head = novo;
            head->next(head);
        } else {
            novo->data() = head->data();
            novo->next(head->next());
            head->next(novo);
            head->data() = data;
        }
        size_++;
    }
/*!Insere dado na  posição desejada*/
    void insert(const T& data, std::size_t index) {  //  inserir na posição
        if (index > size_|| index < 0) {
            throw std::out_of_range("ERRO NA POSIÇÃO!!!");
        }
        if (index == 0) {
            push_front(data);
        } else if (index == size_) {
            push_back(data);
        } else {
        Node* novo = new Node(data);
            if (novo == nullptr) {
                throw std::out_of_range("Full list!");
            }
            Node* anterior = pega_anterior_do_indice(index);
            Node* next = anterior->next();
            novo->next(next);
            anterior->next(novo);
            size_++;
        }
    }
/*!Insere o dado em ordem na lista circular*/
    void insert_sorted(const T& data) {  //  inserir em ordem
        Node *atual;  //  Variável para caminhar.
        std::size_t posicao;  //  Posicao de Insercao.
        if (empty()) {
            push_front(data);
        } else {
            atual = head;
            posicao = 0;
            while (atual -> next() != head && data > atual -> data()) {
                atual = atual -> next();
                posicao++;
            }
            if (data > atual -> data())  //  Parou porque acabou a lista.
                insert(data, posicao + 1);
            else
                insert(data, posicao);
        }
/*!        if (empty()) {
            push_front(data);
        } else {
            Node* current = head;
            std::size_t posicao = size();
            for (auto i = 0u; i < size(); ++i) {
                if (!(data > current->data())) {
                    posicao = i;
                    break;
                }
                current = current->next();
            }
            if (posicao == 0) {
                push_front(data);
            } else {
                if (posicao == size_) {
                    push_back(data);
                } else {
                    insert(data, posicao+1);
                }
            }
        }*/
    }
/*!Acessa a posição do elemento desejado*/
    T& at(std::size_t index) {
//  acessar em um indice (com checagem de limites)
        if (empty())
            throw std::out_of_range("LISTA VAZIA!!!");
        if (index >= size())
            throw std::out_of_range("POSIÇÃO INVÁLIDA!!!");
        Node* atual = head;
        for (int i = 0; i < index; ++i) {
            atual = atual->next();
        }
        return atual->data();
    }
/*!Acessa a posição do elemento desejado*/
    const T& at(std::size_t index) const {  //  versão const do acesso ao indice
        if (empty())
            throw std::out_of_range("LISTA VAZIA!!!");
        if (index >= size())
            throw std::out_of_range("POSIÇÃO INVÁLIDA!!!");
        Node* atual = head;
        for (int i = 0; i < index; ++i) {
            atual = atual->next();
        }
        return atual->data();
    }
/*!Retira dado na  posição desejada*/
    T pop(std::size_t index) {  //  retirar da posição
        if (empty()) {
            throw std::out_of_range("Empty list");
        }
        if (index >= size()) {
            throw std::out_of_range("Invalid index!");
        }
        if (index == 0) {
            return pop_front();
        }
        Node* anterior_out = pega_anterior_do_indice(index);
        Node* saiu = anterior_out->next();
        T volta = saiu->data();
        anterior_out->next(saiu->next());
        size_--;
        delete saiu;
        return volta;
    }
/*!Chama o método pop para retirar o elemento da ultima posição*/
    T pop_back() {  //  retirar do fim
        return pop(size_ - 1u);
    }
/*!Retira dado na primeira posição*/
    T pop_front() {  //  retirar do início
        if (empty()) {
            throw std::out_of_range("Empty list!");
        }
        Node* saiu;
        T volta = head->data();
        if (size_ == 1) {
            saiu = head;
            head = nullptr;
        } else {
            saiu = head->next();
            head->next(saiu->next());
            head->data() = saiu->data();
        }
        size_--;
        delete saiu;
        return volta;
    }
/*! Retira o dado especifico*/
    void remove(const T& data) {  //  remover dado específico
        pop(find(data));
    }
/*!Testa se a lista está vazia*/
    bool empty() const {  //  lista vazia
        return size() == 0;
    }
/*!Percorre toda a lista e verifica se tem o dado
 como data é um elemento privado temos que puxar do método*/
    bool contains(const T& data) const {  //  lista contém determinado dado?
        return find(data) != size();
    }
/*!Posição de um elemento do template
 \return temporario
 */
    std::size_t find(const T& data) const {  //  posição de um item na lista
        std::size_t index = 0u;
        Node* current = head;
        while (index < size()) {
            if (current->data() == data)
                break;
            current = current->next();
            index++;
        }
        return index;
    }
/*! Inicializaçao da variavel generica size*/
    std::size_t size() const {  //  tamanho da lista
        return size_;
    }
 private :
class Node {  //  Elemento
 public :
    explicit Node(const T& data):
        data_{data}
    {}

    explicit Node(const T& data, Node* next):
        data_{data},
        next_{next}
        {}

    T& data() {  // getter: dado
        return data_;
    }

    const T& data() const {  // getter const: dado
        return data_;
    }

    Node* next() {  // getter: próximo
        return next_;
    }

    const Node* next() const {  // getter const: próximo
        return next_;
    }

    void next(Node* node) {  // setter: próximo
        next_ = node;
    }
 private :
    T data_;
    Node* next_{nullptr};
};
    Node* end() {  //  último nodo da lista
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }
    Node* pega_anterior_do_indice(std::size_t index) const {
// node anterior ao index
        auto it = head;
        for (auto i = 1u; i < index; ++i) {
            it = it->next();
        }
        return it;
    }
    /*!Elemento*/
    Node* head{nullptr};
    /*!Indice do elemento topo da lista*/
    std::size_t size_{0u};
};
}  //  namespace structures

#endif  //  STRUCTURES_CIRCULAR_LIST_H
