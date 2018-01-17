#include "Relogio.hpp"
#include <iostream>

Relogio::Relogio() {
}

void Relogio::newCar() {
}

void Relogio::changeStateSemaphore(int tempo) {
    if (mudanca_semaforo(tempo)) {
        if ((tempo%AberturaNorte == 0)&&(tempo%AberturaOeste != 0)&&
                               (tempo%AberturaSul != 0)) {
            Semaphore.setDirection("Norte");
        } else if ((tempo%AberturaNorte != 0)&&(tempo%AberturaOeste == 0)&&
                               (tempo%AberturaSul != 0)) {
            Semaphore.setDirection("Oeste");
        } else if ((tempo%AberturaNorte != 0)&&(tempo%AberturaOeste != 0)&&
                               (tempo%AberturaSul == 0)) {
            Semaphore.setDirection("Sul");
        } else {
            Semaphore.setDirection("Leste");
        }
    }

}
void Relogio::carAtSemaphore() {

}

std::void Relogio::changeWay() {

}

bool Relogio::mudanca_semaforo(int tempo) {
    return ((tempo%AberturaLeste == 0)||(tempo%AberturaNorte == 0)||
                             (tempo%AberturaOeste == 0)||(tempo%AberturaSul == 0));
}


//  Gera um vetor com o tempo de entrada de cada veículo em uma pista-fonte
//  se a frequencia é 10 +-2, fMin = f - aleatorio = 10 -2 = 8
vector<int> Relogio::createCar(int frequencia, int aleatorio, int maxTemp) {
   int fMin = (frequencia - aleatorio);
   int max_car = maxTemp/fMin;
   std::vector<int> carros(max_car + 1);
   int tempo = 0;
   carros[0] = 0;
   for (int i = 1; i <= max_car; i++) {
       tempo = tempo + fMin + rand()%(aleatorio +1);
       carros[i] = carros[i-1] + tempo;
   }
   return carros;
}

#endif
