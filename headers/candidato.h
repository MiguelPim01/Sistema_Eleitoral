#if !defined(CANDIDATO_H)
#define CANDIDATO_H

#include <string>
#include <chrono>

#include "partido.h"

class Partido;

using namespace std;

class Candidato
{
    /* Variaveis */
    int cd_cargo;
    int cd_situacao_candidato_tot;
    int nr_candidato;
    string nm_urna_candidato;
    Partido* p;
    int nr_federacao;
    // data de nascimento
    int cd_sit_tot_turno;
    int cd_genero;
    string nm_tipo_destinacao_votos;
    int votos_nominais;

public:
    Candidato(int cd_cargo, int cd_situacao_candidato_tot, int nr_candidato, string &nm_urna_candidato, Partido &p, int nr_federacao,
                int cd_sit_tot_turno, int cd_genero, string &nm_tipo_destinacao_votos);
    
    int get_cd_cargo()  const;
    int get_cd_situacao_cadidato_tot()  const;
    int get_nr_candidato()  const;
    string get_nm_urna_candidato()  const;
    Partido& get_partido()  const;
    int get_nr_federacao()  const;
    int get_cd_sit_tot_turno()  const;
    int get_cd_genero()  const;
    string get_nm_tipo_destinacao_votos()  const;
    int get_votos_nominais()  const;

    ~Candidato();
};


#endif // CANDIDATO_H
