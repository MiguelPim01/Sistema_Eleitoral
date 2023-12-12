#include "../headers/partido.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>


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

    sort(this->array_candidatos.begin(), this->array_candidatos.end(), [](const Candidato *c1, const Candidato *c2)
                                                                            {
                                                                                return *c1 < *c2;
                                                                            });
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
    return (this->candidatos.find(key) != this->candidatos.end());
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

const string Partido::toString(){
    // if (this->get_votos_totais() == 1 || this->get_votos_totais() == 0) {

    //   if (this->get_votos_nominais() == 1 || this->get_votos_nominais() == 0) {

    //     if (this->get_qtd_cd_eleitos() == 1 || this->get_qtd_cd_eleitos() == 0) {
    //       return this->get_sg_partido() + " - " + (string)this->get_nr_partido() + ", " + (this->get_votos_totais()) << " voto (" + (this->get_votos_nominais())
    //         + " nominal e " + (this->get_votos_de_legenda()) + " de legenda), " + this->get_qtd_cd_eleitos() + " candidato eleito";
    //     }
    //     else {
    //       return this->get_sg_partido() + " - " + this->get_nr_partido() + ", " + this->get_votos_totais() + " voto (" + (this->get_votos_nominais())
    //         + " nominal e " + (this->get_votos_de_legenda()) + " de legenda), " + this->get_qtd_cd_eleitos() + " candidatos eleitos";
    //     }
    //   }
    //   else {
    //     if (this->get_qtd_cd_eleitos() == 1 || this->get_qtd_cd_eleitos() == 0) {
    //       return this->get_sg_partido() + " - " << this->get_nr_partido() + ", " + (this->get_votos_totais()) + " voto (" + (this->get_votos_nominais())
    //         + " nominais e " + (this->get_votos_de_legenda()) + " de legenda), " + this->get_qtd_cd_eleitos() + " candidato eleito";
    //     }
    //     else {
    //       return this->get_sg_partido() + " - " << this->get_nr_partido() + ", " + (this->get_votos_totais()) + " voto (" + (this->get_votos_nominais())
    //         + " nominais e " + (this->get_votos_de_legenda()) + " de legenda), " + this->get_qtd_cd_eleitos() + " candidatos eleitos";
    //     }
    //   }
    // }
    // else {
    //   if (this->get_votos_nominais() == 1 || this->get_votos_nominais() == 0) {

    //       if (this->get_qtd_cd_eleitos() == 1 || this->get_qtd_cd_eleitos() == 0) {
    //         return this->get_sg_partido() + " - " << this->get_nr_partido() + ", " + (this->get_votos_totais()) + " votos (" + (this->get_votos_nominais())
    //           + " nominal e " + (this->get_votos_de_legenda()) + " de legenda), " + this->get_qtd_cd_eleitos() + " candidato eleito";
    //       }
    //       else {
    //         return this->get_sg_partido() + " - " + this->get_nr_partido() + ", " + (this->get_votos_totais()) + " votos (" + (this->get_votos_nominais())
    //           + " nominal e " + (this->get_votos_de_legenda()) + " de legenda), " + this->get_qtd_cd_eleitos() + " candidatos eleitos";
    //       }
    //   }
    //   else {
    //     if (this->get_qtd_cd_eleitos() == 1 || this->get_qtd_cd_eleitos() == 0) {
    //       return this->get_sg_partido() + " - " + this->get_nr_partido() + ", " + (this->get_votos_totais()) + " votos (" + (this->get_votos_nominais())
    //         + " nominais e " + (this->get_votos_de_legenda()) + " de legenda), " + this->get_qtd_cd_eleitos() + " candidato eleito";
    //     }
    //     else {
    //       return this->get_sg_partido() + " - " + this->get_nr_partido() + ", " + (this->get_votos_totais()) + " votos (" + (this->get_votos_nominais())
    //         + " nominais e " + (this->get_votos_de_legenda()) + " de legenda), " + this->get_qtd_cd_eleitos() + " candidatos eleitos";
    //     }
    //   }
    // }
    return "S";
}

Partido::~Partido()
{
    
}