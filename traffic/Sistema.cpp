// Copyright 2017 Fabíola Maria Kretzer && Valdivino Morais da Silva Junior

#ifndef SISTEMA_H
#define SISTEMA_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

/*!Características da pista do sistema */
class Sistema{
    

    Pista N1sul = new Pista(60, 500);
    Pista N1norte = new Pista(60, 500);

    Pista N2sul = new Pista(40, 500);
    Pista N2norte = new Pista(40, 500);

    Pista O1oeste = new Pista(80, 2000);
    Pista O1leste = new Pista(80, 2000);

    Pista C1oeste = new Pista(60, 300);
    Pista C1leste = new Pista(60, 300);

    Pista L1oeste = new Pista(30, 400);
    Pista L1leste = new Pista(30, 400);

    Pista S1sul = new Pista(60, 500);
    Pista S1norte = new Pista(60, 500);

    Pista S2sul = new Pista(40, 500);
    Pista S2norte = new Pista(40, 500);
    return 0;
  }
}

#endif
