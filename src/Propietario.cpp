#include "Propietario.h"

Propietario::Propietario(int documento, std::string nombre, std::string sexo, std::string nacimiento, Vivienda vivienda) {
    this->documento = documento;
    this->nombre = nombre;
    this->sexo = sexo;
    this->nacimiento = nacimiento;
    this->puntos=5; //Inicia con ese puntaje
    this->recibeHuespedes = true;
    this->vivienda = vivienda;
}

void Propietario::setRecibeHuespedes(bool b) {
    this->recibeHuespedes = b;
}

void Propietario::infoMostrar() {
    std::cout<<"Hola, soy el propietario: "<<nombre<<std::endl;
    std::cout<<"Vivo en: "<<vivienda.getDireccion()<<", "<<vivienda.getCamas()<<" camas disponibles, "<<(vivienda.getBebes() ? "Se" : "No se")<<" admiten bebes."<<std::endl;
    std::cout<<"Descripcion: "<<vivienda.getDescripcion()<<std::endl;
    std::cout<<"Puntaje: "<<puntos<<std::endl;
}

bool Propietario::getRecibeHuespedes() {
    return recibeHuespedes;
}
std::string Propietario::getNombre() {
    return nombre;
}
float Propietario::getPuntos() {
    return puntos;
}
void Propietario::setPuntos(float puntos) {
    this->puntos = puntos;
}
Vivienda Propietario::getVivienda(){
    return vivienda;
}