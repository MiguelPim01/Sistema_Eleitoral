#if !defined(PARTIDO_H)
#define PARTIDO_H

#include "candidato.h"

class Partido
{
    /* Variaveis */
    /* -- HashMap de candidatos */
    /* -- Lista de candidatos */
    int nr_partido;
    string sg_partido;
    int votos_nominais;
    int votos_de_legenda;
    int qtd_cd_eleitos;

public:
    Partido();

    int get_nr_partido() const;
    string get_sg_partido()  const;
    int get_votos_nominais()  const;
    int get_votos_de_legenda()  const;
    int get_qtd_cd_eleitos()  const;

    ~Partido();
};


#endif // PARTIDO_H
