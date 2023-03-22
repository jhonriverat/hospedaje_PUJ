#ifndef HOSPEDAJE_PUJ_VIVIENDA_H
#define HOSPEDAJE_PUJ_VIVIENDA_H
#include <iostream>

class Vivienda {
private:
    std::string direccion;
    int camas;
    bool bebes;
    std::string descripcion;
public:
    Vivienda() = default;
    Vivienda(std::string direccion, int camas, bool bebes, std::string descripcion);

    std::string getDireccion();

    int getCamas();
    bool getBebes();
    std::string getDescripcion();
};


#endif //HOSPEDAJE_PUJ_VIVIENDA_H
