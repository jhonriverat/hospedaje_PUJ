//
// Created by usuario on 21/03/2023.
//

#ifndef HOSPEDAJE_PUJ_HUESPEDES_H
#define HOSPEDAJE_PUJ_HUESPEDES_H
#include <iostream>

class huespedes {
private:
    //informacion
    int documento;
    std::string nombre, sexo, nacimiento;
    int puntos;

    //Info familiar
    std:: string nombreClinica;
    std::string ubicacionFamiliar;
public:
    huespedes() { documento = 0; nombre = "", sexo = "", nacimiento = "", puntos = 4, nombreClinica = "", ubicacionFamiliar = ""; }
    huespedes(int documento, std::string nombre, std::string sexo, std::string nacimiento, std::string nombreClinica, std::string ubicacionFamiliar);

    //get
    std::string getNombre();

    //logica
    void infoMostrar();
};


#endif //HOSPEDAJE_PUJ_HUESPEDES_H
