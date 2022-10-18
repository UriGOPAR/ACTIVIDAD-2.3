/*
Author: Uri Jared Gopar Morales_A01709413
Date: 12-10-2022
PARA COPILAR:
g++ -stc=c++20-wall -o main.cpp
*/
#include <iostream>
#include "Bitacora.h"
#include <fstream>

int main(){

    // Creamos la bitacora
    Bitacora myBitacora;
    // Leemos los datos de la bitacora
    myBitacora.lecturaDatos("bitacora.txt");
    // Ordenamos la bitacora
    myBitacora.sort();
    myBitacora.setUpRf1(); // Te pedria un solo string introducelo como este ejemplo:
    myBitacora.setUpRf2(); // Aug 04 19:23:22
                           // mes dia hora:minuto:segundo
    std::cout<<"Registro 1: "<<std::endl;
    std::cout<<myBitacora.getRf1().getAll()<<std::endl;
    std::cout<<"Registro 2: "<<std::endl;
    std::cout<<myBitacora.getRf2().getAll()<<std::endl;

// Si los nodos no existen
    if(!myBitacora.lookUp(myBitacora.getRf2()) && !myBitacora.lookUp(myBitacora.getRf1())){
        std::cout<<"Los registros buscados se encuentran fuera de rango"<<std::endl;
        exit(EXIT_FAILURE);
    }
    // Escribimos dos archivos con los resultados de la busqueda y los elementos ordenados
    myBitacora.writeSearchReslt("resultado_busqueda.txt");
    myBitacora.writeSortReslt("bitacora_ordenada.txt");


    return 0;
}