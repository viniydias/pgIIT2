/*
PROGRAMAÇÃO PARA ENGENHARIA II
TRABALHO 2 - 29.06.18
Douglas Klein, Vinicius Oliveira

Escrever um programa em C++ para a administração de uma academia, o qual coleta a matrícula do aluno e a condição de pagamento.
O programa deve considerar o tipo de plano do aluno (mensal, semetral ou anual) e calcular o tempo, gerando uma saída
com a mensagem de data de próximo pagamento. O programa ainda deve dizer quantos alunos estão matriculados e também
fornecer uma ferramenta para consulta de data de pagamento através da entrada da matrícula. O sistema ainda conta com outra ferramenta,
o qual deve dizer qual o professor quando entrada a matrícula.
***Utilizar conceitos de criação de Classe, Objetos, Funções, leitura de arquivo txt e aplicação de Vector***

Modelo txt 1:
001 semestral  04 07 2018
002 mensal     15 05 2018
003 anual      21 09 2017
004 mensal     12 06 2018
005 semestral  21 04 2018

Modelo txt 2:
Professor1
Professor2
Professor3
Professor4
Professor5

*/

#include <fstream>
#include <iostream>
#include <vector>
#include "Plano.h"

using namespace std;

int main()
{
    vector<Plano> v1;

    //abre arquivo com dados de entrada
    ifstream alunos;
    Plano a;
    professores b;

    alunos.open("aluno.txt");

    cout << "Academia - Controle de Cadastros" << endl;

    int tam = 0;
    while ( ! alunos.eof())
    {
        //leitura do arquivo txt e armazenagem nas variáveis da Classe "Plano" com Objeto "a"
        alunos >> a.matricula;
        if (alunos.eof())
        {
            break;
        }
        alunos >> a.plan;      //plano mensal, semestral ou anual
        alunos >> a.diap;       //dia do ultimo pagamento
        alunos >> a.mesp;       //mes do ultimo pagamento
        alunos >> a.anop;       //ano do ultimo pagamento

        //direciona o objeto "a" no vector
        v1.push_back(a);

        //saída da matrícula com data do próximo pagamento
        cout << "Proximo pagamento da matricula " << a.matricula << ": " << a.getTempoDia() << "/" << a.getTempoMes() << "/" << a.getTempoAno();
        cout << endl;

        tam++;
    }

    //fecha arquivo txt já registrado
    alunos.close();
    cout << endl;

    //saída de quantidade de matriculas lidas
    cout << "Total Alunos Matriculados: " << tam << endl << endl;

    //ferramenta de consulta com vector
    int consulta;
    cout << "Informe a matricula para consulta: ";
    cin >> consulta;

    size_t i;
    for (i = 0; i < v1.size(); i++)
    {
        //se matricula armazenada no vector for igual que digitada, imprime data da respectiva posição de vector
        if(v1[i].matricula == consulta)
        {
            cout << "Data: " << v1[i].getTempoDia() << "/" << v1[i].getTempoMes() << "/" << v1[i].getTempoAno() << endl;
        }
        /*
        if (v1[i].matricula != consulta)    //(i >= v1.size())
        {
            cout << "Matricula inexistente!";
            break;
        }
        */
    }

    cout << endl << endl;

    //funções professores
    b.loadProf();
    b.showProf();
    b.findProf();

    cout << endl;
    cout << "*FIM*";

	return 0;
}
