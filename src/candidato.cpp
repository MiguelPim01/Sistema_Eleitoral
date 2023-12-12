#include "../headers/candidato.h"
#include <iostream>

Candidato::Candidato(const int cd_cargo, const int cd_situacao_candidato_tot, const int nr_candidato, const string &nm_urna_candidato, Partido &p,
                 const int nr_federacao, const int cd_sit_tot_turno, const int cd_genero, const string &nm_tipo_destinacao_votos, const string &data_nascimento) : 
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

int Candidato::get_idade(const string& data_eleicao) const {
    int dia_eleicao = stoi(data_eleicao.substr(0,2));
    int mes_eleicao = stoi(data_eleicao.substr(3,5));
    int ano_eleicao = stoi(data_eleicao.substr(6,10));

    int dia_nascimento = stoi(this->get_data_nascimento().substr(0,2));
    int mes_nascimento = stoi(this->get_data_nascimento().substr(3,5));
    int ano_nascimento = stoi(this->get_data_nascimento().substr(6,10));


    int idade = ano_eleicao - ano_nascimento;

    if(mes_nascimento > mes_eleicao){
        idade--;
    }else if (mes_nascimento == mes_eleicao){
        if (dia_nascimento >= dia_eleicao){
            idade++;
        }
    }

    return idade;
}

const string &Candidato::get_data_nascimento() const {
    return this->data_nascimento;
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

Partido &Candidato::get_partido()
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

bool Candidato::operator<(const Candidato &c) const
{
    if (this->votos_nominais == c.get_votos_nominais()) {
        return this->is_mais_velho(c);
    } 
    return (this->votos_nominais < c.get_votos_nominais());
}

bool Candidato::is_mais_velho(const Candidato &c) const
{
    int dia_nasc_1 = stoi(this->get_data_nascimento().substr(0,2));
    int mes_nasc_1 = stoi(this->get_data_nascimento().substr(3,5));
    int ano_nasc_1 = stoi(this->get_data_nascimento().substr(6,10));

    int dia_nasc_2 = stoi(c.get_data_nascimento().substr(0,2));
    int mes_nasc_2 = stoi(c.get_data_nascimento().substr(3,5));
    int ano_nasc_2 = stoi(c.get_data_nascimento().substr(6,10));

    if (ano_nasc_1 == ano_nasc_2) {
        if (mes_nasc_1 == mes_nasc_2) {
            return dia_nasc_1 < dia_nasc_2;
        }
        return mes_nasc_1 < mes_nasc_2;
    }
    return ano_nasc_1 < ano_nasc_2;
}

int Candidato::compara_idades(const Candidato &c) const
{
    int dia_nasc_1 = stoi(this->get_data_nascimento().substr(0,2));
    int mes_nasc_1 = stoi(this->get_data_nascimento().substr(3,5));
    int ano_nasc_1 = stoi(this->get_data_nascimento().substr(6,10));

    int dia_nasc_2 = stoi(c.get_data_nascimento().substr(0,2));
    int mes_nasc_2 = stoi(c.get_data_nascimento().substr(3,5));
    int ano_nasc_2 = stoi(c.get_data_nascimento().substr(6,10));

    if (ano_nasc_1 == ano_nasc_2) {
        if (mes_nasc_1 == mes_nasc_2) {
            return dia_nasc_2 - dia_nasc_1;
        }
        return mes_nasc_2 - mes_nasc_1;
    }
    return ano_nasc_2 - ano_nasc_1;
}

ostream &operator<<(ostream &os, const Candidato &c)
{
    if (c.get_nr_federacao() == -1) {
        os << c.get_nm_urna_candidato();
    }
    else {
        os << "*" << c.get_nm_urna_candidato();
    }

    return os;
}

int compara_candidatos(const Candidato *c1, const Candidato *c2)
{
    if (c1->votos_nominais == c2->votos_nominais) {
        return c1->compara_idades(*c2);
    }
    return c1->votos_nominais - c2->votos_nominais;
}

Candidato::~Candidato()
{
    
}