#include "../headers/output.h"

#include <iostream>

void output_saidas(Eleicao &e, const string &data_eleicao, int flag_cargo)
{
    cout << "Candidatos:" << endl;
    for (auto [nr_candidato, candidato] : e.get_candidatos()) {
        cout << "Numero: " << nr_candidato << " Nome: " << candidato.get_nm_urna_candidato() << endl;
    }

    cout << "Partidos:" << endl;
    for (auto [nr_partido, partido] : e.get_partidos()) {
        cout << "Numero: " << nr_partido << " Nome: " << partido.get_sg_partido() << endl;
    }
}