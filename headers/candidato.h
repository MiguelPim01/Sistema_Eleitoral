#if !defined(CANDIDATO_H)
#define CANDIDATO_H

#include <string>

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
    int cd_genero;
    string nm_tipo_destinacao_votos;
    int votos_nominais;
    string data_nascimento;

public:
    Candidato(const int cd_cargo, const int cd_situacao_candidato_tot, const int nr_candidato, const string &nm_urna_candidato, Partido &p,
                 const int nr_federacao, const int cd_sit_tot_turno, const int cd_genero, const string &nm_tipo_destinacao_votos, const string &data_nascimento);
    
    int get_cd_cargo()  const;
    int get_cd_situacao_cadidato_tot()  const;
    int get_nr_candidato()  const;
    const string &get_nm_urna_candidato()  const;
    int get_nr_federacao()  const;
    int get_cd_sit_tot_turno()  const;
    int get_cd_genero()  const;
    const string &get_nm_tipo_destinacao_votos()  const;
    int get_votos_nominais()  const;
    const string &get_data_nascimento() const;
    int get_idade(const string& data_eleicao) const;

    Partido& get_partido();

    void inc_votos_nominais(int qtd_votos);
    bool is_eleito(int cargo) const;

    bool operator<(const Candidato &c) const;

    ~Candidato();
};


#endif // CANDIDATO_H
