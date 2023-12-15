#include "../headers/output.h"

#include <iostream>

int get_indice(vector<Candidato> &candidatos, const Candidato &c)
{
    int i = 0;
    for (const Candidato &cand : candidatos) {
        if (cand == c) {
            return i;
        }
        i++;
    }

    return -1;
}

// Relatorio 1: (numero de vagas)
void numero_de_vagas(int num)
{
    cout << "Número de vagas: " << num << endl << endl;
}

// Relatorio 2: (candidatos eleitos)
void candidatos_que_foram_eleitos(vector<Candidato> &candidatos_eleitos, int cargo)
{
    if (cargo == 6) { // Federal
        cout << "Deputados federais eleitos:" << endl;
    }
    else if (cargo == 7) { // Estadual
        cout << "Deputados estaduais eleitos:" << endl;
    }

    int i = 1;
    for (const Candidato &c : candidatos_eleitos) {
        if (c.is_federado()) {
            cout << i << " - " << "*" << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
        }
        else {
            cout << i << " - " << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
        }
        i++;
    }
    cout << endl;
}

// Relatorio 3: (candidatos mais votados)
void candidatos_mais_votados(int qdt_vagas, vector<Candidato> &candidatos)
{
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    int i = 1;

    for (const Candidato &c : candidatos) {
        if (i > qdt_vagas) { break; }

        if (c.is_federado()) {
            cout << i << " - " << "*" << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
        }
        else {
            cout << i << " - " << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
        }
        i++;
    }
    cout << endl;
}

// Relatorio 4: (candidatos nao eleitos)
void candidatos_que_nao_foram_eleitos(int qtd_vagas, vector<Candidato> &candidatos, vector<Candidato> &candidatos_nao_eleitos)
{
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;

    // guarda a quantidade de votos do candidato na posicao limite do numero de vagas
    int votos_min = candidatos[qtd_vagas-1].get_votos_nominais();

    int i = 0, id;

    for (const Candidato &c : candidatos) {

        if (candidatos_nao_eleitos[i].get_votos_nominais() < votos_min) { continue; }

        if (c.get_votos_nominais() <= candidatos_nao_eleitos[i].get_votos_nominais()) {
            id = 1 + get_indice(candidatos, c);

            if (c.is_federado()) {
                cout << id << " - " << "*" << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
            }
            else {
                cout << id << " - " << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
            }
            i++;
        }
    }
    cout << endl;
}

// Relatorio 5: ()

void output_saidas(Eleicao &e, const string &data_eleicao, int flag_cargo)
{
    // ordenar lista de candidatos:
    e.ordena_lista_candidatos(flag_cargo);

    // listas de candidatos:
    vector<Candidato> candidatos, candidatos_eleitos, candidatos_nao_eleitos;

    candidatos = e.get_candidatos_ordenados();
    e.create_candidatos_eleitos(candidatos_eleitos, flag_cargo);
    e.create_candidatos_nao_eleitos(candidatos_nao_eleitos, flag_cargo);

    int qtd_vagas = candidatos_eleitos.size();


    // Relatorios:

    numero_de_vagas(qtd_vagas);
    candidatos_que_foram_eleitos(candidatos_eleitos, flag_cargo);
    candidatos_mais_votados(qtd_vagas, candidatos);
    candidatos_que_nao_foram_eleitos(qtd_vagas, candidatos, candidatos_nao_eleitos);
}