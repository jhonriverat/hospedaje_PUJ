#ifndef HOSPEDAJE_PUJ_PROPIETARIO_H
#define HOSPEDAJE_PUJ_PROPIETARIO_H
#include <iostream>
#include "Vivienda.h"

class Propietario {
private:
    //Informacion
    int documento;
    std::string nombre, sexo, nacimiento;
    float puntos;
    Vivienda vivienda;

    bool recibeHuespedes;
public:
    Propietario() { documento = 0; nombre = "", sexo = "", nacimiento = "", puntos = 5, recibeHuespedes = true; }
    Propietario(int documento, std::string nombre, std::string sexo, std::string nacimiento, Vivienda vivienda);

    //get
    std::string getNombre();
    bool getRecibeHuespedes();
    float getPuntos();
    Vivienda getVivienda();

    //set
    void setPuntos(float puntos);
    void setRecibeHuespedes(bool b);

    //logica
    void infoMostrar();

};


#endif //HOSPEDAJE_PUJ_PROPIETARIO_H
