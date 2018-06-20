#include <iostream>
using namespace std;

class abc
{
private:
    int entrada;
    int saida;

    void calcPlano();
    void calcPagam();


public:
    string matricula;    //matricula composta por numeros, porem deve ser tratado como elemento invariável
    string plano;
    int tempo;
    int diap;
    int mesp;
    int anop;

    int getTempoDia();
    int getTempoMes();
    int getTempoAno();

};
