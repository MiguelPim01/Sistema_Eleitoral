#include "../headers/eleicao.h"

Eleicao::Eleicao() : candidatos(*(new map<int, Candidato *>())), partidos(*(new map<int, Partido *>())),
                        candidatos_ordenados(*(new vector<Candidato *>())), partidos_ordenados(*(new vector<Partido *>))
{

}

void Eleicao::insere_candidato(int key, Candidato &c)
{
    this->candidatos.insert(std::make_pair(key, &c));
}

void Eleicao::insere_partido(int key, Partido &p)
{
    this->partidos.insert(std::make_pair(key, &p));
}

void Eleicao::ordena_lista_candidatos(int cargo)
{
    for (std::map<int, Candidato *>::iterator it = this->candidatos.begin(); it != this->candidatos.end(); it++) {
        this->candidatos_ordenados.push_back(it->second);
    }

    std::sort(this->candidatos_ordenados.begin(), this->candidatos_ordenados.end());
}

map<int, Candidato *> Eleicao::get_candidatos() const
{
    return this->candidatos;
}

map<int, Partido *> Eleicao::get_partidos() const
{
    return this->partidos;
}

vector<Candidato *> Eleicao::get_candidatos_ordenados() const
{
    return this->candidatos_ordenados;
}

vector<Partido *> Eleicao::get_partidos_ordenados() const
{
    return this->partidos_ordenados;
}

Partido &Eleicao::get_partido(int key) const
{
    auto search = this->partidos.find(key);

    return *search->second;
}

Eleicao::~Eleicao()
{
    
}