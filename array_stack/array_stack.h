//  Copyright 2017 <Fabíola Maria Kretzer>
#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions

/*! Estrutura e dados do tipo Pilha,
    que organiza os elementos da forma
   o primeiro à entrar é o ultimo a sair.
 */
namespace structures {

/*!Parâmetro genérico para templates.
*/
template<typename T>
class ArrayStack {
 public:
/*!Contrutor sem parametros
*/
    ArrayStack() {
        max_size_ = DEFAULT_SIZE;
        contents = new T[max_size_];
        top_ = -1;
    }
/*!Contrutor com partametros
*/
    explicit ArrayStack(std::size_t max) {
        max_size_ = max;
        contents = new T[max_size_];
        top_ = -1;
    }
/*!Destrutor
*/
    ~ArrayStack() {
        delete[] contents;
    }
/*!Colocar elementos na pilha
*/
    void push(const T& data) {
         if (full())
            throw std::out_of_range("ERRO PILHA CHEIA!!!");
        top_ = top_ + 1;
        contents[top_] = data;
    }
/*!Retirar elementos da Pilha
*/
    T pop() {
        if (empty())
            throw std::out_of_range("ERRO PILHA VAZIA!!!");
        top_ = top_ - 1;
        return(contents[top_ + 1]);
    }
/*!Elementos da pilha
   retorna  uma referencia
 */
    T& top() {
         if (empty())
            throw std::out_of_range("ERRO PILHA VAZIA!!!");
        return contents[top_];
    }
/*!Retira todos os elementos, deixando a pilha vazia
*/
    void clear() {
         top_ = -1;
    }
/*!Inicialização da variaval generica size
*/
    std::size_t size() {
        return top_ + 1;
    }
/*!Inicialização da vaiavel generica max_size
*/
    std::size_t max_size() {
        return max_size_;
    }
/*!Testa se a pilha está vazia
  \return bool de igualadade
  \top_ indica o indice
  */
    bool empty() {
         return top_ == -1;
    }
/*!Testa se a pilha está cheia
*/
    bool full() {
         return (top_ == static_cast<int>(max_size_) - 1);
    }
 private :
    T* contents;
/*!Dados inseridos na pilha
*/
    int top_;
/*! Indice do elemento topo da pilha
*/
    std::size_t max_size_;
/*!Tamanho maximo da pilha
*/
    static const auto DEFAULT_SIZE = 10u;
/*!static variable, contante usanda como tamanho da pilha, variavel static
*/
};
}  /*!namespace structures */

#endif /*! STRUCTURES_ARRAY_STACK_H */
