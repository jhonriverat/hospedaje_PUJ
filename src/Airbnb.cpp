#include "Airbnb.h"
#include <limits>

void Airbnb::menu() {
    int opcion;
    do{
        std::cout<<" "<<std::endl;
        std::cout<<"| Bienvenido al Airbnb!        |"<<std::endl;
        std::cout<<"| 1. Registrar Persona         |"<<std::endl;
        std::cout<<"| 2. Listar personas inscritas |"<<std::endl;
        std::cout<<"| 3. Crear reserva             |"<<std::endl;
        std::cout<<"| 4. Mostrar reservas          |"<<std::endl;
        std::cout<<"| 5. Eliminar reserva          |"<<std::endl;
        std::cout<<"| 6. Crear evaluacion          |"<<std::endl;
        std::cout<<"| 7. Ver evaluaciones          |"<<std::endl;
        std::cout<<"| 0. Salir                     |"<<std::endl;
        std::cout<<"Respuesta: "<<std::endl;
        std::cin>>opcion;

        switch(opcion)
        {
            case 1:
                registro();
                break;
            case 2:
                listarPersonas();
                break;
            case 3:
                crearReserva();
                break;
            case 4:
                listarReservas();
                break;
            case 5:
                liberarReserva();
                break;
            case 6:
                evaluar();
                break;
            case 7:
                listarEvaluaciones();
                break;
            case 8:
                std::cout<<"Adios."<<std::endl;
                break;
            default:
                std::cout<<"Opcion no valida"<<std::endl;
                break;
        }

    }while(opcion != 0);
}

void Airbnb::registro() {
    int opcion = 0;

    while(opcion < 1 || opcion > 2){
        std::cout<<"--------------|REGISTRO|------------"<<std::endl;
        std::cout<<"| 1. Registrar Propietario         |"<<std::endl;
        std::cout<<"| 2. Registrar Huesped             |"<<std::endl;
        std::cout<<"------------------------------------"<<std::endl;

        std::cin>>opcion;
        switch(opcion)
        {
            case 1:
                try {
                    registrarPropietario();
                }catch (std::invalid_argument ex)
                {
                    std::cout<<ex.what()<<std::endl;
                    return;
                }
                catch (std::out_of_range ex)
                {
                    std::cout<<ex.what()<<std::endl;
                    return;
                }
                break;
            case 2:
                try {
                    registrarHuesped();
                }catch (std::invalid_argument ex)
                {
                    std::cout<<ex.what()<<std::endl;
                    return;
                }
                catch (std::out_of_range ex)
                {
                    std::cout<<ex.what()<<std::endl;
                    return;
                }
                break;
            default:
                std::cout<<"Opcion no valida"<<std::endl;
                break;
        }
    }
}
void Airbnb::registrarPropietario() {
    int documento;
    std::string nombre, genero, nacimiento;

    std::cout << "Digite el id del propietario: "<<std::endl;
    std::cin>> documento;

    if (std::cin.fail())
    {
        //limpiar el cin
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::invalid_argument("El documento debe ser un numero");
    }else{
        std::cout << std::endl;
    }

    int limiteCaracteres = 20;

    std::cout << "Escriba el nombre del propietario: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, nombre);

    if (nombre.length() > limiteCaracteres)
    {
        throw std::out_of_range("El nombre es demasiado largo");
    }

    std::cout << std::endl;


    std::cout << "Escriba el genero del propietario: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, genero);

    if (genero.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para el genero");
    }

    std::cout << std::endl;


    std::cout << "Escriba la fecha de nacimiento del propietario: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, nacimiento);

    if (nacimiento.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para la fecha de nacimiento");
    }

    std::cout << "-|Informacion del hogar|-"<<std::endl;

    std::string direccion;
    int camas;
    int bebes;
    std::string opinion;

    std::cout << "Escriba la direccion de la casa: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, direccion);

    if (direccion.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para la direccion");
    }


    std::cout << "Escriba el numero de camas disponibles en la casa: "<<std::endl;
    std::cin >> camas;
    if (std::cin.fail())
    {
        //limpiar el cin
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::invalid_argument("La cantidad de camas debe ser un numero");
    }else{
        std::cout << std::endl;
    }


    std::cout << "Permiten bebes en la casa?: " << std::endl;
    std::cout << "1. Si." << std::endl;
    std::cout << "2. No." << std::endl;
    std::cin >> bebes;
    if (std::cin.fail())
    {
        //limpiar el cin
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::invalid_argument("Opcion no valida");
    }else{
        std::cout << std::endl;
    }


    std::cout<<"Escriba una opinion sobre la casa: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, opinion);

    if (opinion.length() > 25)
    {
        throw std::out_of_range("Demasiados caracteres para la opinion");
    }


    Vivienda hogarPropietario = Vivienda(direccion, camas, bebes<2, opinion);

    Propietario * propietario = new Propietario(documento, nombre, genero, nacimiento, hogarPropietario);
    this->listPropietario.push_back(propietario);

    std::cout<<"Propietario creado con exito."<<std::endl;

}

void Airbnb::registrarHuesped() {
    int documento;
    std::string nombre, genero, nacimiento;
    std::string nombreClinica;
    std::string ubicacionFamiliar;

    std::cout<<"Digite el id del huesped: ";
    std::cin>>documento;
    if (std::cin.fail())
    {
        //limpiar el cin
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        throw std::invalid_argument("El documento debe ser un numero");
    }else{
        std::cout << std::endl;
    }

    int limiteCaracteres = 20;

    std::cout << "Escriba el nombre del huesped: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, nombre);

    if (nombre.length() > limiteCaracteres)
    {
        throw std::out_of_range("El nombre es demasiado largo");
    }

    std::cout << std::endl;


    std::cout << "Escriba el genero del huesped: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, genero);

    if (genero.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para el genero");
    }

    std::cout << std::endl;


    std::cout << "Escriba la fecha de nacimiento del huesped: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin, nacimiento);

    if (nacimiento.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para la fecha de nacimiento");
    }


    std::cout<<"Escriba el nombre de la clinica donde esta el paciente: ";
    std::cin.ignore();
    std::getline(std::cin, nombreClinica);

    if (nombreClinica.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para el nombre de la clinica");
    }


    std::cout<<"Escriba donde esta siendo atendido el paciente: "<<std::endl;
    std::cout<<"(ciudad/municipio/corregimiento de origen): ";
    std::cin.ignore();
    std::getline(std::cin, ubicacionFamiliar);

    if (ubicacionFamiliar.length() > limiteCaracteres)
    {
        throw std::out_of_range("Demasiados caracteres para la ubicacion del paciente");
    }

    huespedes * huesped = new huespedes(documento, nombre, genero, nacimiento, nombreClinica, ubicacionFamiliar);
    listHuespedes.push_back(huesped);

    std::cout<<"Huesped creado con exito."<<std::endl;

}

void Airbnb::crearReserva() {
    infoHuespedes();

    std::cout<<"Seleccione un huesped para la reserva: ";
    int seleccion = 0;
    std::cin>>seleccion;

    std::list<huespedes*>::iterator huespedIterator = listHuespedes.begin();
    std::advance(huespedIterator, seleccion-1);


    bool seleccionado = false;

    std::list<Propietario*>::iterator propietarioIterator;

    while(!seleccionado)
    {
        infoPropietarios();

        std::cout<<"Seleccione un propietario para la reserva: ";
        std::cin>>seleccion;

        propietarioIterator = listPropietario.begin();
        std::advance(propietarioIterator, seleccion-1);

        if ((*propietarioIterator)->getRecibeHuespedes())
        {
            seleccionado = true;
        }else{
            std::cout<<"---------El propietario "<<seleccion<<" no esta disponible-----------"<<std::endl;
        }
    }

    std::string fechaInicio, fechaFin;

    Reserva * reserva = new Reserva(*propietarioIterator, *huespedIterator, fechaInicio, fechaFin);
    reservas.push_back(reserva);
    std::cout<<"Reserva creada con exito";
}

void Airbnb::liberarReserva() {
    listarReservas();
    std::cout<<"Que reserva desea eliminar?: "<<std::endl;
    int opcion;
    std::cin>>opcion;

    std::list<Reserva*>::iterator iterator = reservas.begin();
    std::advance(iterator, opcion-1);
    delete *iterator;

    reservas.erase(iterator);
}
void Airbnb::infoPropietarios() {
    std::cout<<"||Propietarios||"<<std::endl;
    std::list<Propietario*>::iterator propietario;
    int contador=0;
    for(propietario = listPropietario.begin(); propietario != listPropietario.end(); ++propietario)
    {
        contador++;
        std::cout<<contador<<". "<<((*propietario)->getRecibeHuespedes()? "": "[No disponible!] ");
        (*propietario)->infoMostrar();
    }
}
void Airbnb::infoHuespedes() {
    std::cout<<"||Huespedes||"<<std::endl;
    std::list<huespedes*>::iterator huesped;
    int contador = 0;
    for(huesped = listHuespedes.begin(); huesped != listHuespedes.end(); ++huesped)
    {
        contador++;
        std::cout<<contador<<". ";
        (*huesped)->infoMostrar();
    }
}
void Airbnb::listarPersonas() {
    infoPropietarios();
    infoHuespedes();
}
void Airbnb::listarReservas() {
    std::cout<<"||Reservas||"<<std::endl;
    std::list<Reserva*>::iterator reserva;
    int contador=0;
    for(reserva = reservas.begin(); reserva != reservas.end(); ++reserva)
    {
        contador++;
        std::cout<<"----||Reserva #"<<contador<<"||----"<<std::endl;
        (*reserva)->infoMostrar();
    }
}
void Airbnb::listarEvaluaciones() {
    std::cout<<"||Evaluaciones||"<<std::endl;
    std::list<Evaluar*>::iterator eval;
    int contador=0;
    for(eval = evaluaciones.begin(); eval != evaluaciones.end(); ++eval)
    {
        contador++;
        std::cout<<"----||Evaluacion #"<<contador<<"||----"<<std::endl;
        (*eval)->infoMostrar();
    }
}
void Airbnb::evaluar() {
    std::string fecha,opinion;
    float puntaje;

    int huespedID = -1, propietarioID = -1;

    //Huesp
    infoHuespedes();
    std::cout<<"Quien hace la evaluacion?: ";
    std::cin>>huespedID;

    std::list<huespedes*>::iterator huespIter = listHuespedes.begin();
    std::advance(huespIter, huespedID-1);

    //Prop
    infoPropietarios();
    std::cout<<"Hacia quien hace la evaluacion?: ";
    std::cin>>propietarioID;

    std::list<Propietario*>::iterator propIter = listPropietario.begin();
    std::advance(propIter, propietarioID-1);

    std::cout<<"En que fecha se hospedo?: ";
    std::cin>>fecha;

    std::cout<<"Que comentarios tiene?: ";
    std::cin>>opinion;

    std::cout<<"Que puntaje merece?: ";
    std::cin>>puntaje;

    (*propIter)->setPuntos(((*propIter)->getPuntos()+puntaje)/26);
    Evaluar * evaluacion = new Evaluar(*huespIter,*propIter, fecha, opinion, puntaje);
    evaluaciones.push_back(evaluacion);
    std::cout<<"Evaluacion realizada con exito."<<std::endl;
}
void Airbnb::agregarListaHuespedes(huespedes *h) {
    this->listHuespedes.push_back(h);
}
void Airbnb::agregarListaPropietarios(Propietario *p) {
    this->listPropietario.push_back(p);
}