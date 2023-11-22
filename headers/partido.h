#if !defined(PARTIDO_H)
#define PARTIDO_H

#include "candidato.h"

#include <map>
#include <vector>
#include <algorithm>

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
    Candidato *cria_candidato(int cd_cargo, int cd_situacao_candidato_tot, int nr_candidato, string &nm_urna_candidato, int nr_federacao,
                int cd_sit_tot_turno, int cd_genero, string &nm_tipo_destinacao_votos);

    void cria_lista_ordenada_candidatos();
    void inc_votos_nominais(int qtd_votos);
    void inc_votos_de_legenda(int qtd_votos);
    bool has_candidato(int key) const;

    Candidato &get_candidato(int key) const;
    Candidato &get_candidato_mais_votado() const;
    Candidato &get_candidato_menos_votado() const;
    int get_votos_totais() const;
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
