#ifndef HOSPEDAJE_PUJ_RESERVA_H
#define HOSPEDAJE_PUJ_RESERVA_H
#include <iostream>
#include "Propietario.h"
#include "huespedes.h"

class Reserva {
private:
    Propietario * propietario;
    huespedes * huesped;
    std::string fechaIni, fechaFin;
public:
    Reserva() = default;
    Reserva(Propietario * propietario, huespedes * huesped, std::string fechaIni, std::string fechaFin);
    ~Reserva();

    //Logica
    void infoMostrar();

};


#endif //HOSPEDAJE_PUJ_RESERVA_H
