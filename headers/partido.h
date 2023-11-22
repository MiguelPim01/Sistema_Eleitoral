#if !defined(PARTIDO_H)
#define PARTIDO_H

#include "candidato.h"

#include <map>
#include <vector>

using namespace std;

class Candidato;

class Partido
{
    /* Variaveis */
    map<int, Candidato *> candidatos;
    vector<Candidato *> array_candidatos;
    int nr_partido;
    string sg_partido;
    int votos_nominais;
    int votos_de_legenda;
    int qtd_cd_eleitos;

public:
    Partido(int nr_partido, string &sg_partido);

    map<int, Candidato *> get_candidatos() const;
    vector<Candidato *> get_array_candidatos() const;
    int get_nr_partido() const;
    string get_sg_partido()  const;
    int get_votos_nominais()  const;
    int get_votos_de_legenda()  const;
    int get_qtd_cd_eleitos()  const;

    ~Partido();
};


#endif // PARTIDO_H
