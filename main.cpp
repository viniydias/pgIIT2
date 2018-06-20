/*
Escrever um programa em C++ para a catraca de uma academia que lê a matrícula do aluno e avalia a condição atual de pagamento.
O programa deve considerar o tipo de plano do aluno (mensal, semetral ou anual) e calcular o tempo decorrido, gerando uma saída
com a mensagem do tempo restante até o próximo pagamento.

Modelo de entrada:

35879	semestral	04 07 2018
25368	mensal  	15 06 2018
58234	anual	    21 10 2017

*/

#include <fstream>
#include <iostream>
#include "abc.h"

using namespace std;

int main()
{
    ifstream alunos;
    abc a;

    alunos.open("alunos.txt");

    cout << "Academia" << endl;

    while ( ! alunos.eof())
    {
        alunos >> a.matricula;
        if (alunos.eof())
        {
            break;
        }
        alunos >> a.plano;      //plano mensal, semestral ou anual
        alunos >> a.diap;       //dia do ultimo pagamento
        alunos >> a.mesp;       //mes do ultimo pagamento
        alunos >> a.anop;       //ano do ultimo pagamento

        cout << "Proximo pagamento: " << a.getTempoDia() << "/" << a.getTempoMes() << "/" << a.getTempoAno << endl;
    }
    alunos.close();

    return 0;
}
