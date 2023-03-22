#include "Vivienda.h"
Vivienda::Vivienda(std::string direccion, int camas, bool bebes, std::string descripcion){
    this->direccion = direccion;
    this->camas = camas;
    this->bebes = bebes;
    this->descripcion = descripcion;
}
std::string Vivienda::getDireccion() {
    return direccion;
}
int Vivienda::getCamas() {
    return this->camas;
}
bool Vivienda::getBebes() {
    return this->bebes;
}
std::string Vivienda::getDescripcion() {
    return this->descripcion;
}
