#include "Reserva.h"

Reserva::Reserva(Propietario * propietario, huespedes * huespedes, std::string fechaIni, std::string fechaFin) {
    this->propietario = propietario;
    this->huesped = huesped;
    this->fechaIni = fechaIni;
    this->fechaFin = fechaFin;
    propietario->setRecibeHuespedes(false);
}

Reserva:: ~Reserva() {
    this->propietario->setRecibeHuespedes(true);
}

void Reserva::infoMostrar(){
    std::cout<<"Propietario: "<<propietario->getNombre()<<std::endl;
    std::cout<<"Huesped: "<<huesped->getNombre()<<std::endl;
    std::cout<<"Fecha inicio: "<<fechaIni<<std::endl;
    std::cout<<"Fecha fin: "<<fechaFin<<std::endl;
}