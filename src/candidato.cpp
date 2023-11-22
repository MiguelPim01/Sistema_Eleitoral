#include "../headers/candidato.h"

Candidato::Candidato(int cd_cargo, int cd_situacao_candidato_tot, int nr_candidato, string &nm_urna_candidato, Partido &p, int nr_federacao,
                int cd_sit_tot_turno, int cd_genero, string &nm_tipo_destinacao_votos) : cd_cargo(cd_cargo), 
                                                                                         cd_situacao_candidato_tot(cd_situacao_candidato_tot),
                                                                                         nr_candidato(nr_candidato),
                                                                                         nm_urna_candidato(nm_urna_candidato),
                                                                                         p(&p),
                                                                                         nr_federacao(nr_federacao),
                                                                                         cd_sit_tot_turno(cd_sit_tot_turno),
                                                                                         cd_genero(cd_genero),
                                                                                         nm_tipo_destinacao_votos(nm_tipo_destinacao_votos)
{
    this->votos_nominais = 0;
}

int Candidato::get_cd_cargo()  const
{
    return this->cd_cargo;
}

int Candidato::get_cd_situacao_cadidato_tot()  const
{
    return this->cd_sit_tot_turno;
}

int Candidato::get_nr_candidato()  const
{
    return this->nr_candidato;
}

string Candidato::get_nm_urna_candidato()  const
{
    return this->nm_urna_candidato;
}

Partido& Candidato::get_partido()  const
{
    return *(this->p);
}

int Candidato::get_nr_federacao()  const
{
    return this->nr_federacao;
}

int Candidato::get_cd_sit_tot_turno()  const
{
    return this->cd_sit_tot_turno;
}

int Candidato::get_cd_genero()  const
{
    return this->cd_genero;
}

string Candidato::get_nm_tipo_destinacao_votos()  const
{
    return this->nm_tipo_destinacao_votos;
}

int Candidato::get_votos_nominais()  const
{
    return this->votos_nominais;
}

void Candidato::inc_votos_nominais(int qtd_votos)
{
    this->votos_nominais += qtd_votos;
}

bool Candidato::is_eleito(int cargo) const
{
    return (this->cd_sit_tot_turno == 2 || this->cd_sit_tot_turno == 3 && this->cd_cargo == cargo) ? true : false;
}

Candidato::~Candidato()
{
    
}