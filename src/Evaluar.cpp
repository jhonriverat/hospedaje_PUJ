#include "Evaluar.h"
Evaluar::Evaluar(huespedes * huesped, Propietario * propietario, std::string fecha, std::string opinion, float puntaje){
    this->huesped = huesped;
    this->propietario = propietario;
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->opinion = opinion;
}

void Evaluar::infoMostrar() {
    std::cout<<"Fecha de hospedaje: "<<fecha<<std::endl;
    std::cout<<"Evaluacion de"<<huesped->getNombre()<<" para "<<propietario->getNombre()<<std::endl;
    std::cout<<"Opiniones: "<<std::endl<<opinion<<std::endl;
    std::cout<<"Puntaje final: "<<puntaje<<std::endl;
}
