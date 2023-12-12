#if !defined(OUTPUT_H)
#define OUTPUT_H

#include "eleicao.h"
#include "candidato.h"

void output_saidas(Eleicao &e, const string &data_eleicao, int flag_cargo);

const vector<Candidato> retorna_lista_candidatos_eleitos(Eleicao &e, int flag_cargo);

void numero_eleitos(vector<Candidato> lista); 

void candidatos_eleitos(vector<Candidato> lista, int flag_cargo);

void candidatos_mais_votados(int num_vagas, vector<Candidato> lista);

const vector<Candidato> retorna_lista_candidatos_nao_eleitos(Eleicao &e, int flag_cargo);

const int retorna_posicao_candidato(vector<Candidato> lista, Candidato cand);

void candidados_nao_eleitos(int num_vagas, vector<Candidato> lista, vector<Candidato> lista_candidatos);

void candidatos_eleitos_no_sistema_proporcional(int num_vagas, vector<Candidato> lista_candidatos_eleitos, vector<Candidato> lista_candidatos);

void votos_totais(vector<Partido> lista_partidos);

#endif // OUTPUT_H
