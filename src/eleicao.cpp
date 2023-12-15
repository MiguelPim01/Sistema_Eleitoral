#include "../headers/eleicao.h"

Eleicao::Eleicao()
{

}

void Eleicao::insere_candidato(int key, Candidato &c)
{
    this->candidatos.insert(pair<int, Candidato>(key, c));
}

void Eleicao::insere_partido(int key, Partido &p)
{
    this->partidos.insert(pair<int, Partido>(key, p));
}

void Eleicao::ordena_lista_candidatos(int cargo)
{
    for (map<int, Candidato>::iterator it = this->candidatos.begin(); it != this->candidatos.end(); it++) {
        this->candidatos_ordenados.push_back(it->second);
    }

    sort(this->candidatos_ordenados.begin(), this->candidatos_ordenados.end());
}

const map<int, Candidato> &Eleicao::get_candidatos() const
{
    return this->candidatos;
}

const map<int, Partido> &Eleicao::get_partidos() const
{
    return this->partidos;
}

const vector<Candidato> &Eleicao::get_candidatos_ordenados() const
{
    return this->candidatos_ordenados;
}

const vector<Partido> &Eleicao::get_partidos_ordenados() const
{
    return this->partidos_ordenados;
}

Partido &Eleicao::get_partido(int key)
{
    return this->partidos.at(key);
}

Candidato &Eleicao::get_candidato(int key)
{
    return this->candidatos.at(key);
}

void Eleicao::create_candidatos_eleitos(vector<Candidato> &candidatos, int cargo)
{
    vector<Candidato>::iterator it;

    for (it = this->candidatos_ordenados.begin(); it < this->candidatos_ordenados.end(); it++) {
        if ((*it).is_eleito(cargo)) {
            candidatos.push_back(*it);
        }
    }
}

void Eleicao::create_candidatos_nao_eleitos(vector<Candidato> &candidatos, int cargo)
{
    vector<Candidato>::iterator it;

    for (it = this->candidatos_ordenados.begin(); it < this->candidatos_ordenados.end(); it++) {
        if (!((*it).is_eleito(cargo))) {
            candidatos.push_back(*it);
        }
    }
}

bool Eleicao::has_partido(int key) const
{
    return (this->partidos.find(key) != this->partidos.end());
}

bool Eleicao::has_candidato(int key) const
{
    return (this->candidatos.find(key) != this->candidatos.end());
}

Eleicao::~Eleicao()
{
    
}