// Copyright 2017 Fabíola Maria Kretzer
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
/*!Na lista encadeada cada elemento de lista referencia o próximo e só é
alocado dinamicamente quando necessário;
Para referenciar o primeiro elemento utilizamos um objeto
cabeça de lista.
*/

namespace structures {
/*!Parametro generico para templates*/
template<typename T>
class LinkedList {
 public:
/*!Construtor sem parametros, ja contém os valores inicializados*/
    LinkedList() {}  // construtor padrão
/*!Destrutor*/
    ~LinkedList() {  // destrutor
        clear();
    }
/*!Retira todos os elementos, deixando a lista vazia */
    void clear() {  // limpar lista
        while (!empty())
            pop_front();
    }
/*!Insere dado na ultima posição*/
    void push_back(const T& data) {  // inserir no fim
        if (empty())  /*!Se lista vazia, use insere na primeira posição*/
            push_front(data);
        else
        insert(data, size());   /*!Senão insere na proxima posição vazia*/
    }
/*!Insere dado na primeira posição*/
    void push_front(const T& data) {  // inserir no início
        Node *novo = new Node(data);  //   Variável auxiliar.
        if (novo == nullptr)
            throw std::out_of_range("ERRO LISTA CHEIA!!!");
        novo-> next(head);
        head = novo;
        size_++;
    }
/*!Insere dado na  posição desejada*/
    void insert(const T& data, std::size_t index) {  // inserir na posição
        if (index > size_|| index < 0)
            throw std::out_of_range("ERRO NA POSIÇÃO!!!");
        if (index == 0) {
            push_front(data);
        } else {
            Node *novo, *anterior;  //   auxiliares
            novo = new Node(data);
            if (novo == nullptr)
                throw std::out_of_range("ERRO LISTA CHEIA!!!");
            anterior = head;
            for (int  i = 1; i < index; i++)
                anterior = anterior -> next();
            novo -> next(anterior -> next());
            anterior -> next(novo);
            size_++;
        }
    }
/*!Insere o dado em ordem na lista encadeada*/
    void insert_sorted(const T& data) {  //  inserir em ordem
        Node *atual;  //  Variável para caminhar.
        std::size_t posicao;  //  Posicao de Insercao.
        if (empty()) {
            push_front(data);
        } else {
            atual = head;
            posicao = 0;
            while (atual -> next() != NULL && data > atual -> data()) {
                atual = atual -> next();
                posicao++;
            }
            if (data > atual -> data())  //  Parou porque acabou a lista.
                insert(data, posicao + 1);
            else
                insert(data, posicao);
        }
    }
/*!Acessa a posição do elemento desejado*/
    T& at(std::size_t index) const {  //  acessar um elemento na posição index
        if (index >= size())
           throw std::out_of_range("POSIÇÃO INVÁLIDA!!!");
        auto posicao = head;
        for (auto i = 0; i < index; ++i) {
            posicao = posicao->next();
        }
        return posicao->data();
    }
/*!Retira dado na  posição desejada*/
    T pop(std::size_t index) {  //  retirar da posição
        if (empty())
            throw std::out_of_range("LISTA VAZIA!!!");
        if (index >= size() || index < 0)
            throw std::out_of_range("ERRO NA POSIÇÃO!!!");
        if (index == 0)
            return pop_front();
        Node *anterior = pegar_index(index);
        Node *eliminar = anterior -> next();
        T volta = eliminar -> data();
        anterior -> next(eliminar -> next());
        size_--;
        delete eliminar;
        return volta;
    }
/*!Chama o método pop para retirar o elemento da ultima posição*/
    T pop_back() {  //  retirar do fim
        return pop(size() - 1);
    }

/*!Retira dado na primeira posição*/
    T pop_front() {  //  retirar do início
        if (empty())
            throw std::out_of_range("ERRO LISTA CHEIA");
        auto saiu = head;
        T volta = saiu -> data();
        head = saiu -> next();
        size_--;
        delete saiu;
        return volta;
    }
/*! Retira o dado especifico*/
    void remove(const T& data)  {   //   remover específico
        pop(find(data));
    }
/*!Testa se a lista está vazia*/
    bool empty() const {   //   lista vazia
        return size() == 0;
    }
/*!Percorre toda a lista e verifica se tem o dado
como data é um elemento privado temos que puxar do método*/
    bool contains(const T& data) const {   //   contém
        return find(data) != size();
    }
/*!Posição de um elemento do template
\return temporario
*/
    std::size_t find(const T& data) const {  //  posição do dado
        std::size_t temp = 0;
        Node *posicao = head;
        while (temp < size()) {
            if (posicao->data() == data)
                break;
            posicao = posicao->next();
            temp++;
        }
        return temp;
    }
/*! Inicializaçao da variavel generica size*/
    std::size_t size() const {   //  tamanho da lista
        return size_;
    }
 protected :
/*!Classe Node*/
class Node {  //  Elemento
 public :
/*!Contrutor da classe Node*/
        explicit Node(const T& data):
            data_{data}
        {}
/*!Contrutor da classe Node*/
        explicit Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}
/*!Getter dado*/
        T& data() {  // getter: dado
            return data_;
        }
/*!Getter dado da forma const*/
        const T& data() const {  // getter const: dado
            return data_;
        }
/*!Getter proximo*/
        Node* next() {  // getter: próximo
            return next_;
        }
/*!Getter proximo da forma const*/
        const Node* next() const {  // getter const: próximo
            return next_;
        }
/*!Setter proximo*/
        void next(Node* node) {  // setter: próximo
            next_ = node;
        }
 private :
        T data_;
        Node* next_{nullptr};
};
/*! último nodo da lista*/
    Node* end() {  //  último nodo da lista
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }
/*! último nodo da lista(posição)*/
    Node* pegar_index(std::size_t index) {  //  último nodo da lista(posição)
        auto it = head;
        for (auto i = 1u; i < index; ++i) {
            it = it->next();
        }
        return it;
    }
/*!elemento topo da lista*/
    Node* head{nullptr};
/*!Indice do elemento topo da lista*/
    std::size_t size_{0u};
};

}  //  namespace structures

#endif  //  STRUCTURES_LINKED_LIST_H
