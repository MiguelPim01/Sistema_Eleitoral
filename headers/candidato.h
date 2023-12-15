#if !defined(CANDIDATO_H)
#define CANDIDATO_H

#include <string>
#include "enums.h"

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
    int cd_sit_tot_turno;
    Genero cd_genero;
    string nm_tipo_destinacao_votos;
    int votos_nominais;

public:
    Candidato(const int cd_cargo, const int cd_situacao_candidato_tot, const int nr_candidato, const string &nm_urna_candidato, Partido &p,
                 const int nr_federacao, const int cd_sit_tot_turno, const Genero &cd_genero, const string &nm_tipo_destinacao_votos);
    
    int get_cd_cargo()  const;
    int get_cd_situacao_cadidato_tot()  const;
    int get_nr_candidato()  const;
    const string &get_nm_urna_candidato()  const;
    int get_nr_federacao()  const;
    int get_cd_sit_tot_turno()  const;
    const Genero &get_cd_genero()  const;
    const string &get_nm_tipo_destinacao_votos()  const;
    int get_votos_nominais()  const;

    Partido& get_partido() const;

    void inc_votos_nominais(int qtd_votos);
    bool is_eleito(int cargo) const;
    bool is_federado() const;

    bool operator<(const Candidato &c) const;
    bool operator==(const Candidato &c) const;

    ~Candidato();
};


#endif // CANDIDATO_H
