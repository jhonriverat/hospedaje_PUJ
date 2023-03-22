#ifndef HOSPEDAJE_PUJ_EVALUAR_H
#define HOSPEDAJE_PUJ_EVALUAR_H
#include <iostream>
#include "Propietario.h"
#include "huespedes.h"

class Evaluar {
private:
    Propietario * propietario;
    huespedes * huesped;
    std::string fecha, opinion;
    float puntaje;
public:
    Evaluar()=default;
    Evaluar(huespedes * huesped, Propietario * propietario, std::string fecha, std::string opinion, float puntaje);

    //Logica
    void infoMostrar();
};


#endif //HOSPEDAJE_PUJ_EVALUAR_H
