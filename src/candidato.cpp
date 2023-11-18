#include "../headers/candidato.h"

Candidato::Candidato()
{

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

Candidato::~Candidato()
{
    
}