#include "../headers/partido.h"
#include "partido.h"

Partido::Partido()
{
    
}

Partido::Partido(const int nr_partido, const string &sg_partido) : nr_partido(nr_partido), sg_partido(sg_partido)
{
    this->votos_nominais = 0;
    this->votos_de_legenda = 0;
    this->qtd_cd_eleitos = 0;
}

void Partido::add_candidato(Candidato &c, int cargo)
{
    if (c.is_eleito(cargo)) {
        this->qtd_cd_eleitos++;
    }

    this->candidatos.insert(pair<int, Candidato *>(c.get_nr_candidato(), &c));
}

// Candidato &Partido::cria_candidato(int cd_cargo, int cd_situacao_candidato_tot, int nr_candidato, string &nm_urna_candidato, int nr_federacao,
//                 int cd_sit_tot_turno, int cd_genero, string &nm_tipo_destinacao_votos)
// {
//     Candidato *c = new Candidato(cd_cargo, cd_situacao_candidato_tot, nr_candidato, nm_urna_candidato, *this, nr_federacao,
//                 cd_sit_tot_turno, cd_genero, nm_tipo_destinacao_votos);
    
//     if (c->is_eleito(cd_cargo)) {
//         this->qtd_cd_eleitos++;
//     }

//     this->candidatos.insert(pair<int, Candidato *>(nr_candidato, c));

//     return *c;
// }

void Partido::cria_lista_ordenada_candidatos()
{
    for (std::map<int, Candidato *>::iterator it = this->candidatos.begin(); it != this->candidatos.end(); it++) {
        if ((*it->second).get_nm_tipo_destinacao_votos().compare("Válido (legenda)")) {
            this->array_candidatos.push_back(it->second);
        }
    }

    std::sort(this->array_candidatos.begin(), this->array_candidatos.end());
}

void Partido::inc_votos_nominais(int qtd_votos)
{
    this->votos_nominais += qtd_votos;
}

void Partido::inc_votos_de_legenda(int qtd_votos)
{
    this->votos_de_legenda += qtd_votos;
}

bool Partido::has_candidato(int key) const
{
    return (this->candidatos.find(key) != this->candidatos.end()) ? true : false;
}

Candidato &Partido::get_candidato(int key) const
{
    auto search = this->candidatos.find(key);

    return *search->second;
}

Candidato &Partido::get_candidato_mais_votado() const
{
    return *this->array_candidatos.front();
}

Candidato &Partido::get_candidato_menos_votado() const
{
    return *this->array_candidatos.back();
}

int Partido::get_votos_totais() const
{
    return this->votos_nominais + this->votos_de_legenda;
}

const map<int, Candidato *> &Partido::get_candidatos() const
{
    return this->candidatos;
}

const vector<Candidato *> &Partido::get_array_candidatos() const
{
    return this->array_candidatos;
}

int Partido::get_nr_partido() const
{
    return this->nr_partido;
}

const string &Partido::get_sg_partido()  const
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