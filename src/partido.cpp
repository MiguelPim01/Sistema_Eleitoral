#include "../headers/partido.h"

Partido::Partido(int nr_partido, string &sg_partido) : nr_partido(nr_partido), sg_partido(sg_partido)
{
    this->votos_nominais = 0;
    this->votos_de_legenda = 0;
    this->qtd_cd_eleitos = 0;
}

map<int, Candidato *> Partido::get_candidatos() const
{
    return this->candidatos;
}

vector<Candidato *> Partido::get_array_candidatos() const
{
    return this->array_candidatos;
}

int Partido::get_nr_partido() const
{
    return this->nr_partido;
}

string Partido::get_sg_partido()  const
{
    return this->sg_partido;
}

int Partido::get_votos_nominais()  const
{
    return this->votos_nominais;
}

int Partido::get_votos_de_legenda()  const
{
    return this->votos_de_legenda;
}

int Partido::get_qtd_cd_eleitos()  const
{
    return this->qtd_cd_eleitos;
}

Partido::~Partido()
{
    
}