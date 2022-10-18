#ifndef BITACORA_H
#define BITACORA_H
#include <fstream>
#include <sstream>
#include "DoubleLinkedList.h"


#include "Registro.h"

class Bitacora{
private:
    // vector de objetos Registro (cada celda es un renglón de bitacora.txt)
    DoubleLinkedList<Registro>listaRegistros;
    Registro Rf1; //Registro mas viejo (Registro de la fecha 1)
    Registro Rf2; //Registro mas nuevo (Registro de la fecha 2)


public:
    Bitacora();
    ~Bitacora();
    void lecturaDatos(std::string fileName);
    void print();
    void print(int i);
    // ordenamiento y búsqueda
    void sort();
    DLLNode<Registro>* lookUp(Registro key);
    DoubleLinkedList<Registro> getList(); 


    void setUpRf1();
    void setUpRf2();
    Registro getRf1();
    Registro getRf2();

    void writeSearchReslt(std::string arch);
    void writeSortReslt(std::string arch);

};

#endif // BITACORA_H