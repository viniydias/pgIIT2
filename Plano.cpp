#include "Plano.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//FUNÇÕES ALUNOS

void Plano::calcPlano()
{
    if (plan == "mensal")
    {
        tempo=30;
    }
    else if (plan == "semestral")
    {
        tempo=180;
    }
    else
    {
        tempo=360;
    }

}

void Plano::calcPagam()
{
    calcPlano();
    entrada = (diap + (mesp*30) + (anop*360));
    saida = entrada + tempo; //total dias
}

int Plano::getTempoAno()
{
    calcPagam();
    return saida / 360;
}

int Plano::getTempoMes()
{
    calcPagam();
    return (saida % 360) / 30;
}

int Plano::getTempoDia()
{
    calcPagam();
    return (saida % 360) % 30;
}


//FUNÇÕES PROFESSORES

void professores::loadProf()
{
    ifstream arquivo;
    arquivo.open("professor.txt");
    while (!arquivo.eof())
    {
        if (arquivo.eof())
            break;
        arquivo >> nome;
        v2.push_back(nome);
    }
    arquivo.close();
}

void professores::showProf()
{
    int i = 1;
    vector<string>::iterator names;
    cout << "Relacao de Professores:" << endl;
    for (names = v2.begin(); names < v2.end(); names++)
    {
        cout << i << " : " << *names << endl;
        i++;
    }
    cout << endl;
}

void professores::findProf()
{
    int h=1;
    cout << "Insira a matricula para consultar o professor: ";
    cin >> h;
    cout << v2[h-1] << endl;
}

