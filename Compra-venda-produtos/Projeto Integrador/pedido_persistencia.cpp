#include "pedido_persistencia.h"

pedido_persistencia::pedido_persistencia()
{
}

void pedido_persistencia::lerArquivo()
{
    string leitura;
    tp2::Pedido pedido;
    QString arquivoProdutos("Lista_De_Pedidos.cvs");
    ifstream arquivo(arquivoProdutos.toStdString().c_str());
    getline(arquivo,leitura);
    if(!arquivoProdutos.isEmpty()){
        QString linha=QString::fromStdString(leitura);
        QStringList list=linha.split(';');
        pedido.setNumero(list[0].toInt());
        pedido.setCliente(list[1]);
        pedido.setData(list[2]);
        pedido.setStatus(list[3]);
        pedido.setValorTotal(list[4].toFloat());
        listaDePedidos->insereFim(pedido);
    }
    arquivo.close();
}
/*
void pedido_persistencia::salvarArquivo()
{
    QString arquivoProdutos("Lista_De_Pedidos.cvs");
    ofstream arquivo(arquivoProdutos.toStdString().c_str());
    for(int i=0;i<listaDePedidos->getQuantidade();i++){
        tp2::Pedido pedido=listaDePedidos->operator[](i);
        arquivo<<produto.getCodigo()<<";"<<produto.getDescricao().toStdString()<<";"<<produto.getPreco()<<";"
              <<produto.getQuantidade()<<"\n";
    }
}
*/
