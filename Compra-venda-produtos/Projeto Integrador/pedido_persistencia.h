#ifndef PEDIDO_PERSISTENCIA_H
#define PEDIDO_PERSISTENCIA_H
#include"pedido.h"
#include<QStringList>

class pedido_persistencia
{
private:
    Caio::LLDE<tp2::Pedido> *listaDePedidos;
public:
    pedido_persistencia();
    void lerArquivo();
    void salvarArquivo();
};

#endif // PEDIDO_PERSISTENCIA_H
