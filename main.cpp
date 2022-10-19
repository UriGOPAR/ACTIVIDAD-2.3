/*
Author: Uri Jared Gopar Morales_A01709413
DATE: 15-10-2022
compilar:
    g++ -std=c++20 -Wall -o main *.cpp
    También otra forma es correrlo en replit
    Para lo cuál deben de sacar los programas de la carpeta
    esto para que el copilador de replit encuentre el main.cpp


*/

#include <iostream>
#include "Bitacora.h"
#include <fstream>

int main(){

    // Creamos la bitacora
    Bitacora myBitacora;
    myBitacora.lecturaDatos("bitacora.txt");
    myBitacora.sort();
    std::cout<<"Dame dos registros los cuales sacalos de la bitacora deben de estar por mes,dia,hora,minuto,segundo; uno adelante de otro"<<std::endl;
    myBitacora.setUpRf1(); // Te pedria un solo string introducelo como este ejemplo:
    myBitacora.setUpRf2(); // Aug 04 19:23:22
                           // mes dia hora:minuto:segundo
    std::cout<<"Registro 1: "<<std::endl;
    std::cout<<myBitacora.getRf1().getAll()<<std::endl;
    std::cout<<"Registro 2: "<<std::endl;
    std::cout<<myBitacora.getRf2().getAll()<<std::endl;

    if(!myBitacora.lookUp(myBitacora.getRf2()) && !myBitacora.lookUp(myBitacora.getRf1())){
        std::cout<<"Los registros buscados se encuentran fuera de rango"<<std::endl;
        exit(EXIT_FAILURE);
    }
    // Escribimos dos archivos con los resultados de la busqueda y los elementos ordenados
    myBitacora.writeSearchReslt("resultado_busqueda.txt");
    myBitacora.writeSortReslt("bitacora_ordenada.txt");


    return 0;
}