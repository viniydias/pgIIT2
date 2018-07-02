#include <iostream>
#include <vector>

using namespace std;

class Plano
{
private:

    int entrada;
    int saida;

    void calcPlano();
    void calcPagam();

public:
    int matricula;
    string plan;
    int tempo;
    int diap;
    int mesp;
    int anop;

    int getTempoDia();
    int getTempoMes();
    int getTempoAno();
};


class professores
{
public:
    vector<string> v2;
    string nome;

    void loadProf();
    void showProf();
    void findProf();
};
