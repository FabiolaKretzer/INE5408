// Copyright 2017 Fabíola Maria Kretzer
#ifndef STRUCTURES_DOUBLY_CIRCULAR_LIST_H
#define STRUCTURES_DOUBLY_CIRCULAR_LIST_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

namespace structures {
/*!Parametro generico para templates*/
template<typename T>
class DoublyCircularList {
 public:
/*!Construtor*/
    DoublyCircularList() {}
/*!Destrutor*/
    ~DoublyCircularList() {
        clear();
    }
/*!Esvaziar lista*/
    void clear() {
         while (!empty())
           pop_front();
    }
/*!Inserir dado no fim*/
    void push_back(const T& data) {  //  insere no fim
        insert(data, size_);
    }
/*!Inserir dado no fim*/
    void push_front(const T& data) {  //  insere no início
        Node* novo = new Node(data);
        if (novo == nullptr)
            throw std::out_of_range("ERRO LISTA CHEIA!!!");
        if (empty()) {
            head = novo;
            head->next(head);
            head->prev(head);
        } else {
            novo->next(head);
            novo->prev(head->prev());
            head->prev()->next(novo);
            head->prev(novo);
            head = novo;
        }
        size_++;
    }
/*!Insere o dado na posição desejada*/
    void insert(const T& data, std::size_t index) {  //  insere na posição
        if (index > size())
            throw std::out_of_range("ERRO NA POSIÇÃO!!!");
        if (empty() || index == 0) {
            push_front(data);
        } else {
            Node* novo = new Node(data);
            if (novo == nullptr)
                throw std::out_of_range("ERRO LISTA CHEIA!!!");
            Node* atual = pegar_index(index);
            novo->next(atual);
            novo->prev(atual->prev());
            atual->prev()->next(novo);
            atual->prev(novo);
            size_++;
        }
    }
/*!Insere o dado em ordem*/
    void insert_sorted(const T& data) {  //  insere em ordem
       if (empty()) {
            push_front(data);
        } else {
            Node *atual;  //  Variável para caminhar.
            std::size_t posicao;  //  Posicao de Insercao.
            atual = head;
            posicao = 0;
            while (atual -> next() != head && data > atual -> data()) {
                atual = atual -> next();
                posicao++;
            }
            if (posicao ==0) {  //  Parou porque acabou a lista.
                push_front(data);
            } else {
                Node *novo = new Node(data);
                if (data > atual -> data()) {
                    atual -> next(novo);
                    novo -> prev(atual);
                } else {
                    novo ->prev(atual->prev());
                    novo -> next(atual);
                    atual -> prev() -> next(novo);
                    atual -> prev(novo);
                }
                size_++;
            }
        }
    }
/*!Retira dado na posição desejada*/
    T pop(std::size_t index) {  //  retira da posição
        if (empty())
            throw std::out_of_range("LISTA VAZIA!!!");
        if (index >= size())
            throw std::out_of_range("ERRO NA POSIÇÃO!!!");
        if (index == 0)
            return pop_front();
        auto anterior = pegar_index(index);
        T data = anterior->data();
        anterior->prev()->next(anterior->next());
        anterior->next()->prev(anterior->prev());
        size_--;
        delete anterior;
        return data;
    }
/*!Retira dado do fim*/
    T pop_back() {  //  retira do fim
        return pop(size_ - 1);
/*!        if (empty())
            throw std::out_of_range("LISTA VAZIA!!!");
        Node *anterior = head->prev();
        if (size_ == 1) {
            head->prev(head);
            head->next(head);
        } else {
            anterior->prev()->next(head);
            head->prev(anterior->prev());
        }
        T data = anterior->data();
        size_--;
        delete anterior;
        return data;*/
    }
/*!Retirar dado do inicio*/
    T pop_front() {  //  retira do início
         if (empty())
            throw std::out_of_range("LISTA VAZIA!!!");
        Node *saiu;
        T data = head->data();
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
        return data;
    }
/*!Remove dado especifico*/
    void remove(const T& data) {  //  retira específico
        pop(find(data));
    }
/*!Booleano para lista vazia*/
    bool empty() const {  //  lista vazia
        return size() == 0u;
    }
/*!Booleano que verifica se conte o dado*/
    bool contains(const T& data) const {  //  contém
        return find(data) != size_;
    }
/*!Acessar um elemento verificando os limites da lista*/
    T& at(std::size_t index) {  //  acesso a um elemento (checando limites)
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
/*!Acessar um elemento sem verificar os limites da lista*/
    const T& at(std::size_t index) const {  //  getter constante a um elemento
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
/*!Acessar a posição de um elemento da lista*/
    std::size_t find(const T& data) const {  //  posição de um dado
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
/*!Acessar o tamanho da lista*/
    std::size_t size() const {  //  tamanho
        return size_;
    }
 private :
    class Node {
     public:
        explicit Node(const T& data):
            data_{data}
        {}
        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}
        Node(const T& data, Node* prev, Node* next):
            data_{data},
            prev_{prev},
            next_{next}
        {}
        T& data() {
            return data_;
        }
        const T& data() const {
            return data_;
        }

        Node* prev() {
            return prev_;
        }
        const Node* prev() const {
            return prev_;
        }

        void prev(Node* node) {
            prev_ = node;
        }

        Node* next() {
            return next_;
        }
        const Node* next() const {
            return next_;
        }
        void next(Node* node) {
            next_ = node;
        }
     private :
        T data_;
        Node* prev_{nullptr};
        Node* next_{nullptr};
    };
    Node* head{nullptr};
    std::size_t size_{0u};

    Node* end() {  //  último nodo da lista
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
           it = it->next();
        }
        return it;
    }
    Node* pegar_index(std::size_t index) {  //  último nodo da lista(posição)
        auto it = head;
        for (auto i = 1u; i <= index; ++i) {
           it = it->next();
        }
        return it;
    }
    Node* pegar_anterior(std::size_t index) const {  //   nodo anterior do index
        auto it = head;
        for (auto i = 1u; i < index; ++i) {
           it = it->next();
        }
        return it;
    }
};
}  // namespace structures

#endif  //  STRUCTURES_DOUBLY_CIRCULAR_LIST_H
