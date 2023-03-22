#include "huespedes.h"

huespedes::huespedes(int documento, std::string nombre, std::string sexo, std::string nacimiento, std::string nombreClinica, std::string ubicacionFamiliar) {
    this->documento = documento;
    this->nombre = nombre;
    this->sexo = sexo;
    this->nacimiento = nacimiento;
    this->puntos=4;
    this->nombreClinica = nombreClinica;
    this->ubicacionFamiliar = ubicacionFamiliar;
}

void huespedes::infoMostrar() {
    std::cout<<"Hola, soy un huesped y mi nombre es"<<nombre<<std::endl;
    std::cout<<"El paciente esta en la clinica: "<<nombreClinica<<" en "<<ubicacionFamiliar<<std::endl;
}

std::string huespedes::getNombre() {
    return nombre;
}