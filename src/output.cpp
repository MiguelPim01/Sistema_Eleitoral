#include "../headers/output.h"

#include <iostream>
#include <locale>
#include <iomanip>
#include <sstream>

using namespace std;

string get_formatacao_voto(int qtd_votos)
{
    ostringstream oss;
    oss.imbue(locale("pt_BR.UTF-8"));
    oss << qtd_votos;
    if (qtd_votos > 1)
        return oss.str() + " votos";
    return oss.str() + " voto";
}

string get_formatacao_nominal(int qtd_nominal)
{
    ostringstream oss;
    oss.imbue(locale("pt_BR.UTF-8"));
    oss << qtd_nominal;
    if (qtd_nominal > 1)
        return oss.str() + " nominais";
    return oss.str() + " nominal";
}

string get_formatacao_candidato(int qtd_eleitos)
{
    ostringstream oss;
    oss.imbue(locale("pt_BR.UTF-8"));
    oss << qtd_eleitos;
    if (qtd_eleitos > 1)
        return oss.str() + " candidatos eleitos";
    return oss.str() + " candidato eleito";
}

int get_indice(vector<Candidato> &candidatos, const Candidato &c)
{
    int i = 0;
    for (const Candidato &cand : candidatos) {
        if (cand == c) {
            return i;
        }
        i++;
    }

    return -1;
}

// Relatorio 1: (numero de vagas)
void numero_de_vagas(int num)
{
    cout << "Número de vagas: " << num << endl << endl;
}

// Relatorio 2: (candidatos eleitos)
void candidatos_que_foram_eleitos(vector<Candidato> &candidatos_eleitos, int cargo)
{
    if (cargo == 6) { // Federal
        cout << "Deputados federais eleitos:" << endl;
    }
    else if (cargo == 7) { // Estadual
        cout << "Deputados estaduais eleitos:" << endl;
    }

    int i = 1;
    for (const Candidato &c : candidatos_eleitos) {
        if (c.is_federado()) {
            cout << i << " - " << "*" << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
        }
        else {
            cout << i << " - " << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
        }
        i++;
    }
    cout << endl;
}

// Relatorio 3: (candidatos mais votados)
void candidatos_mais_votados(int qdt_vagas, vector<Candidato> &candidatos)
{
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    int i = 1;

    for (const Candidato &c : candidatos) {
        if (i > qdt_vagas) { break; }

        if (c.is_federado()) {
            cout << i << " - " << "*" << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
        }
        else {
            cout << i << " - " << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
        }
        i++;
    }
    cout << endl;
}

// Relatorio 4: (candidatos nao eleitos)
void candidatos_que_nao_foram_eleitos(int qtd_vagas, vector<Candidato> &candidatos, vector<Candidato> &candidatos_nao_eleitos)
{
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;

    // guarda a quantidade de votos do candidato na posicao limite do numero de vagas
    int votos_min = candidatos[qtd_vagas-1].get_votos_nominais();

    int i = 0, id;

    for (const Candidato &c : candidatos) {

        if (candidatos_nao_eleitos[i].get_votos_nominais() < votos_min) { continue; }

        if (c.get_votos_nominais() <= candidatos_nao_eleitos[i].get_votos_nominais()) {
            id = 1 + get_indice(candidatos, c);

            if (c.is_federado()) {
                cout << id << " - " << "*" << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
            }
            else {
                cout << id << " - " << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
            }
            i++;
        }
    }
    cout << endl;
}

// Relatorio 5: (eleitos no sistema proporcional)
void candidatos_eleitos_pelo_sistema_proporcional(int qtd_vagas, vector<Candidato> &candidatos, vector<Candidato> &candidatos_eleitos)
{
    cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;

    // guarda a quantidade de votos do candidato na posicao limite do numero de vagas
    int votos_min = candidatos[qtd_vagas-1].get_votos_nominais();
    int id;

    for (const Candidato &c : candidatos_eleitos) {

        id = 1 + get_indice(candidatos, c);

        if (c.get_votos_nominais() < votos_min) {
            if (c.is_federado()) {
                cout << id << " - " << "*" << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
            }
            else {
                cout << id << " - " << c.get_nm_urna_candidato() << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
            }
        }
    }
    cout << endl;
}

// Relatorio 6: (votacao dos partidos)
void votacao_partidos(Eleicao &e)
{
    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;

    // ordenando a lista de partidos
    e.ordena_lista_partidos();

    int qtd_partidos = e.get_quantidade_partidos();

    int i = 1;

    for (const Partido &p : e.get_partidos_ordenados()) {
        
        cout << i << " - " << p.get_sg_partido() << " - " << p.get_nr_partido() << ", ";

        string votos_do_partido = get_formatacao_voto(p.get_votos_totais());
        string votos_nominais = get_formatacao_nominal(p.get_votos_nominais());
        string candidatos_eleitos = get_formatacao_candidato(p.get_qtd_cd_eleitos());

        cout << votos_do_partido << " (" << votos_nominais << " e " << p.get_votos_de_legenda() << " de legenda), " << candidatos_eleitos << endl;

        i++;
    }
    cout << endl;
}

// Relatorio 7: (mais e menos votados dos partidos)
void mais_e_menos_votados_dos_partidos(Eleicao &e, int cargo)
{
    cout << "Primeiro e último colocados de cada partido:" << endl;

    int i = 1;
    string vot1, vot2;

    for (const Partido &p: e.get_partidos_ordenados()) {

        if (p.get_array_candidatos().size() == 0) { continue; }

        if (p.get_votos_nominais() != 0) {

            Candidato &c_mais_votado = p.get_candidato_mais_votado();
            Candidato &c_menos_votado = p.get_candidato_menos_votado();

            vot1 = c_mais_votado.get_votos_nominais() > 1 ? "votos" : "voto";
            vot2 = c_menos_votado.get_votos_nominais() > 1 ? "votos" : "voto";

            cout << i << " - " << p.get_sg_partido() << " - " << p.get_nr_partido() << ", "; // printando partido

            cout << c_menos_votado.get_nm_urna_candidato() << " (" << c_menos_votado.get_nr_candidato(); // printando candidatos
            cout << ", " << c_menos_votado.get_votos_nominais() << " " << vot2 << ") / ";

            cout << c_mais_votado.get_nm_urna_candidato() << " (" << c_mais_votado.get_nr_candidato();
            cout << ", " << c_mais_votado.get_votos_nominais() << " " << vot1 << ")" << endl;
        }

        i++;
    }
    cout << endl;
}

// Relatorio 8: (eleitos por faixa etaria)
void eleitos_por_faixa_etaria(Eleicao &e, vector<Candidato> &candidatos_eleitos)
{
    cout << "Eleitos, por faixa etária (na data da eleição):" << endl;

    int vet[5];

    for (int i = 0; i < 5; i++) {
        vet[i] = 0;
    }

    for (const Candidato &c : candidatos_eleitos) {

        // deve-se calcular a data de nascimento do candidato

        
    }

    cout << endl;
}

// Relatorio 9: (eleitos por genero)
void eleitos_por_genero(vector<Candidato> &candidatos_eleitos)
{
    cout << "Eleitos, por gênero:" << endl;

    int qtd_mulheres = 0, qtd_homens = 0;

    for (const Candidato &c : candidatos_eleitos) {
        if (c.get_cd_genero() == Genero::MASCULINO) {
            qtd_homens++;
        }
        else {
            qtd_mulheres++;
        }
    }

    int qtd_eleitos = candidatos_eleitos.size();

    cout << "Feminino: " << qtd_mulheres << " " << (static_cast<double>(qtd_mulheres) / qtd_eleitos)*100 << "%" << endl;
    cout << "Masculino: " << qtd_homens << " " << (static_cast<double>(qtd_homens) / qtd_eleitos)*100 << "%" << endl;

    cout << endl;
}

// Relatorio 10: (total de votos)
void total_de_votos(Eleicao &e, int cargo)
{
    int votos_nominais = 0;
    int votos_de_legenda = 0;

    for (const Partido &p : e.get_partidos_ordenados()) {
        votos_nominais += p.get_votos_nominais();
        votos_de_legenda += p.get_votos_de_legenda();
    }

    int total_validos = votos_de_legenda + votos_nominais;

    cout << "Total de votos válidos:    " << total_validos << endl;
    cout << "Total de votos nominais:   " << votos_nominais << " (" << (static_cast<double>(votos_nominais) / total_validos)*100 << "%)" << endl;
    cout << "Total de votos de legenda: " << votos_de_legenda << " (" << (static_cast<double>(votos_de_legenda) / total_validos)*100 << "%)" << endl;

    cout << endl;
}

void output_saidas(Eleicao &e, const string &data_eleicao, int flag_cargo)
{
    locale br_locale("pt_BR.UTF-8");
    cout.imbue(br_locale);
    cout << fixed << setprecision(2);

    // ordenar lista de candidatos:
    e.ordena_lista_candidatos(flag_cargo);

    // listas de candidatos:
    vector<Candidato> candidatos, candidatos_eleitos, candidatos_nao_eleitos;

    candidatos = e.get_candidatos_ordenados();
    e.create_candidatos_eleitos(candidatos_eleitos, flag_cargo);
    e.create_candidatos_nao_eleitos(candidatos_nao_eleitos, flag_cargo);

    int qtd_vagas = candidatos_eleitos.size();


    // Relatorios:

    numero_de_vagas(qtd_vagas);
    candidatos_que_foram_eleitos(candidatos_eleitos, flag_cargo);
    candidatos_mais_votados(qtd_vagas, candidatos);
    candidatos_que_nao_foram_eleitos(qtd_vagas, candidatos, candidatos_nao_eleitos);
    candidatos_eleitos_pelo_sistema_proporcional(qtd_vagas, candidatos, candidatos_eleitos);
    votacao_partidos(e);
    mais_e_menos_votados_dos_partidos(e, flag_cargo);
    eleitos_por_faixa_etaria(e, candidatos_eleitos);
    eleitos_por_genero(candidatos_eleitos);
    total_de_votos(e, flag_cargo);
}