#if !defined(ELEICAO_H)
#define ELEICAO_H

#include "partido.h"

class Eleicao
{
    /* Variaveis */
    map<int, Candidato *> candidatos;
    map<int, Partido *> partidos;
    vector<Candidato *> candidatos_ordenados;
    vector<Candidato *> partidos_ordenados;
    /* -- Data da eleicao */
    
public:
    Eleicao();



    ~Eleicao();
};


#endif // ELEICAO_H
