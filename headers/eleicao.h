#if !defined(ELEICAO_H)
#define ELEICAO_H

#include "partido.h"

class Eleicao
{
    /* Variaveis */
    map<int, Candidato> candidatos;
    map<int, Partido> partidos;
    vector<Candidato> candidatos_ordenados;
    vector<Partido> partidos_ordenados;
    string data_da_eleicao;
    
public:
    Eleicao(const string &data_da_eleicao);

    void insere_candidato(int key, Candidato &c);
    void insere_partido(int key, Partido &p);
    void ordena_lista_candidatos(int cargo);
    void ordena_lista_partidos();

    const map<int, Candidato> &get_candidatos() const;
    const map<int, Partido> &get_partidos() const;
    const vector<Candidato> &get_candidatos_ordenados() const;
    const vector<Partido> &get_partidos_ordenados() const;

    void create_candidatos_eleitos(vector<Candidato> &candidatos, int cargo);
    void create_candidatos_nao_eleitos(vector<Candidato> &candidatos, int cargo);

    Partido &get_partido(int key);
    Candidato &get_candidato(int key);
    int get_quantidade_partidos() const;
    const string &get_data_eleicao() const;

    bool has_partido(int key) const;
    bool has_candidato(int key) const;

    ~Eleicao();
};


#endif // ELEICAO_H
