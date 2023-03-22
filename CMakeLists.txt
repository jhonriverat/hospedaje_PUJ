cmake_minimum_required(VERSION 3.24)
project(hospedaje_PUJ)

set(CMAKE_CXX_STANDARD 17)

add_executable(hospedaje_PUJ src/main.cpp src/huespedes.cpp src/huespedes.h src/Propietario.cpp src/Propietario.h src/Vivienda.cpp src/Vivienda.h src/Reserva.cpp src/Reserva.h src/Evaluar.cpp src/Evaluar.h src/Airbnb.cpp src/Airbnb.h)
