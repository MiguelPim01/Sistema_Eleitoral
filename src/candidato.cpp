#include "../headers/candidato.h"

Candidato::Candidato(const int cd_cargo, const int cd_situacao_candidato_tot, const int nr_candidato, const string &nm_urna_candidato, Partido &p,
                 const int nr_federacao, const int cd_sit_tot_turno, const Genero &cd_genero, const string &nm_tipo_destinacao_votos, const string &data_nascimento) : 
                                                                                         cd_cargo(cd_cargo), 
                                                                                         cd_situacao_candidato_tot(cd_situacao_candidato_tot),
                                                                                         nr_candidato(nr_candidato),
                                                                                         nm_urna_candidato(nm_urna_candidato),
                                                                                         p(&p),
                                                                                         nr_federacao(nr_federacao),
                                                                                         cd_sit_tot_turno(cd_sit_tot_turno),
                                                                                         cd_genero(cd_genero),
                                                                                         nm_tipo_destinacao_votos(nm_tipo_destinacao_votos),
                                                                                         data_nascimento(data_nascimento)
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

const string &Candidato::get_nm_urna_candidato()  const
{
    return this->nm_urna_candidato;
}

Partido &Candidato::get_partido() const
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

const Genero &Candidato::get_cd_genero()  const
{
    return this->cd_genero;
}

const string &Candidato::get_nm_tipo_destinacao_votos()  const
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
    return ((this->cd_sit_tot_turno == 2 || this->cd_sit_tot_turno == 3) && this->cd_cargo == cargo);
}

bool Candidato::is_federado() const
{
    return this->nr_federacao != -1;
}

bool Candidato::operator<(const Candidato &c) const
{
    if (this->votos_nominais == c.get_votos_nominais()) {
        // comparar as datas de nascimento (devem ser comparadas na força bruta com o tipo string)
    }
    return (c.votos_nominais < this->votos_nominais);
}

bool Candidato::operator==(const Candidato &c) const
{
    return this->nr_candidato == c.nr_candidato;
}

Candidato::~Candidato()
{
    
}