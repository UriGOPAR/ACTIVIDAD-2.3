#include <iostream>
#include "Bitacora.h"
#include "DoubleLinkedList.h"
#include "sstream"

Bitacora::Bitacora(){
    listaRegistros;
}

Bitacora::~Bitacora(){
    listaRegistros.clearMemory();
}

void Bitacora::lecturaDatos(std::string fileName){
    std::string month, day, hour, minute, second, ipAdd, port, message;
    std::ifstream inputFile(fileName);
    if(!inputFile.good()){
        inputFile.close();
        throw std::invalid_argument("File not found");
    }
    else{
        while(!inputFile.eof()){
                // to-do validar que la longitud de month sea mayor a cero
                std::getline(inputFile, month, ' ');
                std::getline(inputFile, day, ' ');
                std::getline(inputFile, hour, ':');
                std::getline(inputFile, minute, ':');
                std::getline(inputFile, second, ' ');
                std::getline(inputFile, ipAdd, ':');
                std::getline(inputFile, port, ' ');
                std::getline(inputFile, message,'\n');
                // crear un objeto de la clase Registro
                Registro tmpReg(month, day, hour, minute, second, ipAdd, port, message);
                // agregar el objeto al vector
                listaRegistros.addLast(tmpReg);
                // std::cout<<listaRegistros.getNumElements()<<std::endl;
                // NOTA: Asegurate de que el .txt no tenga ningun renglon de mas, podria generar Registros fantasma sin mes :)
        }
            

    }
    inputFile.close();
}

void Bitacora::sort(){
   listaRegistros.sort();
}

// Buscamos la key en nustra listaRegistros
DLLNode<Registro>* Bitacora::lookUp(Registro key){
    return listaRegistros.binarySearch(listaRegistros.getHead(),key);
}
// Queremos imprimir un registro en espesifico
void Bitacora::print(int i){
    listaRegistros.getData(i).getAll();
}
void Bitacora::print(){
    DLLNode<Registro>* p=listaRegistros.getHead();
    while (true)
    {
        std::cout<<p->data.getAll()<<std::endl;
        p=p->next;
        if (p==listaRegistros.getTail())
        {
            break;
        }

        
    }
}
DoubleLinkedList<Registro> Bitacora::getList(){
    return listaRegistros;
}

void Bitacora::setUpRf1(){
    std::string month, day, hour, minute, second;
    std::getline(std::cin, month, ' ');// la idea original era usar el espacio, pero por alguna razon no toma en cuenta el segundo token y pierde toda la información, (Preguntar al profe por que pasa eso)
    std::getline(std::cin, day, ' ');
    std::getline(std::cin, hour, ':');
    std::getline(std::cin, minute, ':');
    std::getline(std::cin, second);
    // crear un objeto de la clase Registro
    Registro tmpReg(month, day, hour, minute, second);
    Rf1=tmpReg;
}
void Bitacora::setUpRf2(){
    std::string month, day, hour, minute, second;
    std::getline(std::cin, month, ' ');
    std::getline(std::cin, day, ' ');
    std::getline(std::cin, hour, ':');
    std::getline(std::cin, minute, ':');
    std::getline(std::cin, second);
    // crear un objeto de la clase Registro
    Registro tmpReg(month, day, hour, minute, second);
    Rf2=tmpReg;
}

Registro Bitacora::getRf1(){
    return Rf1;
}
Registro Bitacora::getRf2(){
    return Rf2;
}

void Bitacora::writeSearchReslt(std::string arch){
        // Aqui guardamos el registro final
    DoubleLinkedList<Registro> regFinal;
    DLLNode<Registro>* fin=lookUp(Rf2);
    DLLNode<Registro>* inicio=lookUp(Rf1);
    while (true)
    {
        regFinal.addLast(inicio->data);
        inicio=inicio->next;
        if (inicio==fin)
        {
            break;
        }
        
    }
    inicio=regFinal.getHead();
    std::ofstream archivo(arch);
    if (!archivo.is_open()){
        std::cout<<"Error al abrir"<<std::endl;
        exit(EXIT_FAILURE);
    }
    while (inicio)
    {
        archivo<<inicio->data.getAll()<<std::endl;
        inicio=inicio->next;
    }

}

void Bitacora::writeSortReslt(std::string arch ){
    sort();
    DLLNode<Registro>* inicio=listaRegistros.getHead();
    //Escribimos nuestro txt
    std::ofstream archivo(arch);
    if (!archivo.is_open()){
        std::cout<<"Error al abrir"<<std::endl;
        exit(EXIT_FAILURE);
    }
    while (inicio)
    {
        archivo<<inicio->data.getAll()<<std::endl;
        inicio=inicio->next;
    }

}