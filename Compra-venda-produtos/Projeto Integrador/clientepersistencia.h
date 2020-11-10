#ifndef CLIENTEPERSISTENCIA_H
#define CLIENTEPERSISTENCIA_H
#include <iostream>
#include <QStringList>
#include<fstream>
#include"cliente.h"
#include"llde.h"
#include"pessoafisica.h"
#include"pessoajuridica.h"

class ClientePersistencia
{
private:
    //static Caio::LLDE<Caio::Cliente*> *p1;
    static void armazenarClientes();
    static void resgatarClientes();
public:
    ClientePersistencia();
    //static void armazenarClientes(Caio::LLDE<Caio::Cliente*> *p){ p1=p; armazenarClientes(); }
    //static void resgatarClientes(Caio::LLDE<Caio::Cliente*> *p){ p1=p; resgatarClientes(); }
};

#endif // CLIENTEPERSISTENCIA_H
