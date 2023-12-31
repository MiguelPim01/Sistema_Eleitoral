#include "../headers/partido.h"

bool compara_candidatos(Candidato *c1, Candidato *c2)
{
    return ((*c2) < (*c1));
}

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

void Partido::cria_lista_ordenada_candidatos()
{
    for (std::map<int, Candidato *>::iterator it = this->candidatos.begin(); it != this->candidatos.end(); it++) {
        if ((*it->second).get_nm_tipo_destinacao_votos().compare("Válido (legenda)")) {
            this->array_candidatos.push_back(it->second);
        }
    }

    std::sort(this->array_candidatos.begin(), this->array_candidatos.end(), compara_candidatos);
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
    return *this->array_candidatos.back();
}

Candidato &Partido::get_candidato_menos_votado() const
{
    return *this->array_candidatos.front();
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

bool Partido::operator<(const Partido &p) const
{
    if (this->get_votos_totais() == p.get_votos_totais()) {
        return (this->nr_partido - p.nr_partido) < 0;
    }
    return (p.get_votos_totais() - this->get_votos_totais()) < 0;
}

Partido::~Partido()
{
    
}