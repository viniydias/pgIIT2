#include "abc.h"        //corrigir para => "Plano.h"
using namespace std;

void abc::calcPlano()   //corrigir para => Plano::calcPagam()
{
    if (plano == "mensal")
    {
        tempo=30;
    }
    else if (plano == "semestral")
    {
        tempo=180;
    }
    else
    {
        tempo=365;
    }

}

void abc::calcPagam()   //corrigir para => Plano::calcTempo()
{
    entrada = ( diap + (mesp*30) + (anop*365));
    saida = entrada + tempo; //total dias
}

int abc::getTempoAno()  //corrigir para => Plano::calcTempoAno()
{
    calcPagam();
    return tempo / 365;
}

int abc::getTempoMes()  //corrigir para => Plano::calcTempoMes()
{
    calcPagam();
    return (tempo % 365) / 30;
}

int abc::getTempoDia()  //corrigir para => Plano::calcTempoDia()
{
    calcPagam();
    return (tempo % 365) % 30;
}




