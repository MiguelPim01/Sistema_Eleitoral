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
    // data da eleicao
    
public:
    Eleicao();

    void insere_candidato(int key, Candidato &c);
    void insere_partido(int key, Partido &p);
    void ordena_lista_candidatos(int cargo);

    const map<int, Candidato> &get_candidatos() const;
    const map<int, Partido> &get_partidos() const;
    const vector<Candidato> &get_candidatos_ordenados() const;
    const vector<Partido> &get_partidos_ordenados() const;

    Partido &get_partido(int key);
    Candidato &get_candidato(int key);

    bool has_partido(int key) const;

    ~Eleicao();
};


#endif // ELEICAO_H
