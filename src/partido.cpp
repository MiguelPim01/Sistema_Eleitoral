#include "../headers/partido.h"

Partido::Partido()
{

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