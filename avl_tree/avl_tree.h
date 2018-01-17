//  Copyright 2017 <Fabíola Maria Kretzer>
#ifndef STRUCTURES_AVI_TREE_H
#define STRUCTURES_AVI_TREE_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions
#include "array_list.h"
/*!Implementação da arvore AVL balaceada*/

namespace structures {
/*!Parametro generico para templates*/
template<typename T>
class AVLTree {
public:
/*!Construtor*/
    AVLTree() {}
/*!Destrutor*/
    virtual ~AVLTree() {
        delete root;
        size_ = 0;
    }
/*! Insere dado*/
    void insert(const T& data) {
        if (empty()) {
            root = new Node(data);
        } else {
            root -> insert(data);
        }
        size_++;
    }
/*! Retira o dado especifico*/
    void remove(const T& data) {
        if (empty())
            throw std::out_of_range("ERRO ÁRVORE VAZIA!!!");
        if (contains(data)) {
            size_--;
            root -> remove(data);
        }
    }
/*!Booleano*/
    bool contains(const T& data) const {
        bool temp = false;
        if (!empty())
            temp = root->contains(data);
        return temp;
    }
/*!Testa se a lista está vazia*/
    bool empty() const {
        return size_ == 0;
    }
/*! Inicializaçao da variavel generica size*/
    std::size_t size() const {
        return size_;
    }
/*!Visite a raiz antes das subarvores*/
    ArrayList<T> pre_order() const {
        ArrayList<T> v{size_};
        if (!empty())
            root->pre_order(v);
        return v;
    }
/*!Visite a subarvores*/
    ArrayList<T> in_order() const {
        ArrayList<T> v{size_};
        if (!empty())
            root->in_order(v);
        return v;
    }
/*!Visite a raiz depois das subarvores*/
    ArrayList<T> post_order() const {
        ArrayList<T> v{size_};
        if (!empty())
            root->post_order(v);
        return v;
    }

 private:
    struct Node {
/*!Construtor com parametros*/
        explicit Node(const T& data) : data{data}, left{nullptr}, right{nullptr}
        {}
/*!Dado a ser inserido na arvore*/
        T data;
/*!Altura da arvore*/
        std::size_t height;
/*!Elemento da esquerda*/
        Node* left;
/*!Elemento da direita*/
        Node* right;
/*!Inserir elementos*/
        void insert(const T& data_) {
            Node* novo;
            if (data_ < this->data) {
                if (this->left == nullptr) {
                    novo = new Node(data_);
                    novo->left = nullptr;
                    novo->right = nullptr;
                    this->left = novo;
                } else {
                    left->insert(data_);
                }
            } else {
                if (this->right == nullptr) {
                    novo = new Node(data_);
                    novo->left = nullptr;
                    novo->right = nullptr;
                    this->right = novo;
                } else {
                    right->insert(data_);
                }
            }
        }
/*!Remove o elemento desejado*/
        bool remove(const T& data_) {
            bool temp = false;
            if (data_ == this->data) {
                Node* novo;
                if ((this->left != nullptr) && (this->right != nullptr)) {
                    novo = this->right;
                    while (novo->left != nullptr)
                        novo = novo->left;
                    this->data = novo->data;
                    temp = right -> remove(this->data);
                } else {
                    if (this->right != nullptr) {
                        this->data = right->data;
                        temp = right -> remove(this->data);
                    } else {
                        if (this->left != nullptr) {
                        this->data = left->data;
                        temp = left->remove(this->data);
                        } else {
                            delete this;
                            temp = true;
                        }
                    }
                }
            } else {
            if ((this->left != nullptr) && (data_ < this->data))
                temp = left->remove(data_);
            if ((this->right != nullptr) && (data_ > this->data))
                temp = right->remove(data_);
            }
            return temp;
        }
/*!Contem o elemento desejado?*/
        bool contains(const T& data_) const {
            bool temp = false;
            if (data_ == this->data) {
                temp = true;
            } else {
                if ((this->left != nullptr) && (data_ < this->data)) {
                    temp = left->contains(data_);
                } else if ((this->right != nullptr) && (data_ > this->data)) {
                    temp = right->contains(data_);
                }
            }
            return temp;
        }
/*!Altura da arvore*/
        void updateHeight() {
            if (this->left == nullptr || this->rigth == nullptr)
                return -1;
            this->heigth++;
        }
/*!Girar para a esquerda */
        Node* simpleLeft(Node* k2) {
            Node* k1;
            k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            k2->updateHeight();
            k1->updateHeight();
            return k1;
        }
/*!Girar para a direita */
        Node* simpleRight(Node* k2) {
            Node* k1;
            k1 = k2->right;
            k2->right = k1->left;
            k1->left = k2;
            k2->updateHeight();
            k1->updateHeight();
            return k1;
        }
/*!Girar duas para a esquerda */
        Node* doubleLeft(Node* k3) {
            k3->left = simpleRight(k3->left);
            return simpleLeft(k3);
        }
/*!Girar duas para a esquerda */
        Node* doubleRight(Node* k3) {
            k3->right = simpleLeft(k3->right);
            return simpleRight(k3);
        }
/*!Visite a raiz antes das subarvores*/
        void pre_order(ArrayList<T>& v) const {
            v.push_back(this->data);
            if (this->left != nullptr)
                left->pre_order(v);
            if (this->right != nullptr)
                right->pre_order(v);
        }
/*!Visite a subarvores*/
        void in_order(ArrayList<T>& v) const {
             if (this->left != nullptr)
                left->in_order(v);
            v.push_back(this->data);
            if (this->right != nullptr)
                right->in_order(v);
        }

        void post_order(ArrayList<T>& v) const {
             if (this->left != nullptr)
                left->post_order(v);
            if (this->right != nullptr)
                right->post_order(v);
            v.push_back(this->data);
        }
    };

    Node* root{nullptr};
    std::size_t size_{0u};
};

}  // namespace structures
#endif  /*! STRUCTURES_AVI_TREE_H */
