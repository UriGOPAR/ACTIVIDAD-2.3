#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <vector>
#include <ctime>
#include <iostream>

class Registro{
private:
    std::string mes;
    std::string dia;
    std::string hora;
    std::string minuto;
    std::string seg;
    std::string ip;
    std::string puerto;
    std::string msg;
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    struct tm dateStruct;
    time_t date;

public:
    Registro();
    Registro(std::string mes, std::string dia, std::string hora, std::string minuto, std::string seg);
    Registro(std::string mes, std::string dia, std::string hora, std::string minuto, std::string seg, std::string ip, std::string puerto, std::string msg);
    std::string getAll();
    bool operator >(const Registro&) const;
    bool operator <(const Registro&) const;
    bool operator ==(const Registro&) const;
    bool operator <=(const Registro&) const;
    bool operator !=(const Registro&) const;
};

#endif // REGISTRO_H