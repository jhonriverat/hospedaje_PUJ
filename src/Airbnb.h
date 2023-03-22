#ifndef HOSPEDAJE_PUJ_AIRBNB_H
#define HOSPEDAJE_PUJ_AIRBNB_H
#include "Propietario.h"
#include "Reserva.h"
#include "Vivienda.h"
#include "Evaluar.h"
#include <list>

class Airbnb {
private:
    std::list<Propietario*> listPropietario;
    std::list<huespedes*> listHuespedes;
    std::list<Reserva*> reservas;
    std::list<Evaluar*> evaluaciones;

    void infoPropietarios();
    void infoHuespedes();
public:
    Airbnb()=default;

    void menu();
    void registro();
    void registrarPropietario();
    void registrarHuesped();
    void agregarListaPropietarios(Propietario * p);
    void agregarListaHuespedes(huespedes * h);


    void listarPersonas();
    void listarReservas();
    void listarEvaluaciones();
    void crearReserva();
    void liberarReserva();
    void evaluar();
};


#endif //HOSPEDAJE_PUJ_AIRBNB_H
