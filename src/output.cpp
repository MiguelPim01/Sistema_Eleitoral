#include "../headers/output.h"
#include "../headers/candidato.h"

#include <iostream>
#include <algorithm>

void output_saidas(Eleicao &e, const string &data_eleicao, int flag_cargo)
{   
    //Acho que isso aqui da pra mudar pq eu to ordenando logo mais abaixo
    //vai ter que se chamar tipo, "inserindo_na_lista_de_candidatos"
    //==============================================
    e.ordena_lista_candidatos(flag_cargo); 
    e.inserindo_na_lista_partidos();
    //==============================================

    //==================== LISTAS (COPIAS TAMBÉM) ==========================
    vector<Candidato> lista_candidatos = e.get_candidatos_ordenados();
    vector<Candidato> lista_candidatos_eleitos = create_lista_candidatos_eleitos(e,flag_cargo);
    vector<Candidato> lista_candidatos_nao_eleitos = create_lista_candidatos_nao_eleitos(e,flag_cargo);
    vector<Partido> lista_partidos = e.get_partidos_ordenados(); 

    //============================ ORDENANDO LISTAS ====================================== //
    // ordenando lista de partidos
    std::sort(lista_partidos.begin(),lista_partidos.end(),[data_eleicao] (const Partido& a, const Partido& b) 
                                                        {
                                                            if (a.get_votos_totais() == b.get_votos_totais()){
                                                                
                                                                return a.get_nr_partido() - b.get_nr_partido();
                                                            }
                                                            return b.get_votos_totais() - a.get_votos_totais();
                                                        }
    );

    // ordenando a lista de candidados 
    std::sort(lista_candidatos.begin(), lista_candidatos.end());
    
    // ordenando a lista de candidados eleitos
    std::sort(lista_candidatos_eleitos.begin(), lista_candidatos_eleitos.end());
    //=================================================================================== //    
    
    // numero_eleitos(lista_candidatos_eleitos); //numeros de candidados eleitos
    // candidatos_eleitos(lista_candidatos_eleitos,flag_cargo);
    // candidatos_mais_votados(lista_candidatos_eleitos.size(),lista_candidatos);
    // candidados_nao_eleitos(lista_candidatos_eleitos.size(),lista_candidatos_nao_eleitos,lista_candidatos);
    // candidatos_eleitos_no_sistema_proporcional(lista_candidatos_eleitos.size(),lista_candidatos_eleitos,lista_candidatos);
    // // tem que imprimir no toString
    // votos_totais(lista_partidos);
    
    // for (auto &t : lista_candidatos_eleitos){
    //     cout << t.get_nm_urna_candidato() << " " << t.get_data_nascimento() << " " << t.get_idade(data_eleicao) << endl;
        
    // }
    // cout << "Candidatos:" << endl;
    // for (auto [nr_candidato, candidato] : e.get_candidatos()) {
    //     cout << "Numero: " << nr_candidato << " Nome: " << candidato.get_nm_urna_candidato() << "  Votos nominais: " << candidato.get_votos_nominais() << endl;
    // }

    // cout << "Partidos:" << endl;
    // for (auto [nr_partido, partido] : e.get_partidos()) {
    //     cout << "Numero: " << nr_partido << " Nome: " << partido.get_sg_partido() << " votos: " << partido.get_votos_de_legenda() << endl;
    // }
}

void votos_totais(vector<Partido> lista_partidos){
    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;

    int tam = lista_partidos.size();
    cout << lista_partidos.size() << endl;

    // essa função devera ser feita da forma antiga com todas as condições dentro dela, pois o toString de partido foi consertado
}

void candidatos_eleitos_no_sistema_proporcional(int num_vagas, vector<Candidato> lista_candidatos_eleitos, vector<Candidato> lista_candidatos){
    cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;

    int votos_ultimo_candidato = lista_candidatos[num_vagas-1].get_votos_nominais();

    int id;

    for (vector<Candidato>::iterator it; it < lista_candidatos_eleitos.end(); it++) {
        if ((*it).get_votos_nominais() < votos_ultimo_candidato) {
            id = 1 + get_posicao_candidato(lista_candidatos, *it);
            cout << id << " - " << (*it) << " (" << (*it).get_partido().get_sg_partido() << ", " << (*it).get_votos_nominais() << " votos)" << endl;
        }
    }

    // for (auto &c : lista_candidatos_eleitos){
    //     int id = 1 + get_posicao_candidato(lista_candidatos,c);

    //     if (c.get_votos_nominais() < votos_ultimo_candidato){

    //         int id = 1 + get_posicao_candidato(lista_candidatos,c);
    //         string str = (c.get_nr_federacao() == -1) ? c.get_nm_urna_candidato() : "*" + c.get_nm_urna_candidato();
    //         cout << id << " - " << str << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)\n";
    //     }
    // }
    
    cout << endl;
}

void candidados_nao_eleitos(int num_vagas, vector<Candidato> lista, vector<Candidato> lista_candidatos) {
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
    cout << "(com sua posição no ranking de mais votados)" << endl;
    
    int votos_ultimo_candidato = lista_candidatos[num_vagas-1].get_votos_nominais();
    
    int index = 0;
    for (auto &c : lista){

        
        if (lista[index].get_votos_nominais() < votos_ultimo_candidato) continue;
        
        if (c.get_votos_nominais() <= lista[index].get_votos_nominais()){
            
            int id = 1 + get_posicao_candidato(lista_candidatos,c);
            cout << id << " - " << c << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)\n";

            index++;
        }
    }

     cout << endl;
    
}

void candidatos_mais_votados(int num_vagas, vector<Candidato> lista){
   
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    int index = 1;
    for (auto &cand : lista){
        if (index > num_vagas) break;
        string str = (cand.get_nr_federacao() == -1) ? cand.get_nm_urna_candidato() : "*" + cand.get_nm_urna_candidato();
        cout << index << " - " << str << " (" << cand.get_partido().get_sg_partido() << ", " << cand.get_votos_nominais() << " votos)\n";

        index++;
    }
    cout << endl;
}

void candidatos_eleitos(vector<Candidato> lista, int flag_cargo) {
    //usamos enum nesse caso 
    string str = (flag_cargo == 6) ? "Deputados federais eleitos:" : "Deputados estaduais eleitos:";
    //1 - SERGIO MENEGUELLI (REPUBLICANOS, 138.523 votos) 
    cout << str << endl;
    int i = 1;
    for (auto &c : lista){

        str = (c.get_nr_federacao() == -1) ? c.get_nm_urna_candidato() : "*" + c.get_nm_urna_candidato();
        cout << i << " - " << str << " (" << c.get_partido().get_sg_partido() << ", " << c.get_votos_nominais() << " votos)" << endl;
        i++;
    }

    cout << endl;
}

void numero_eleitos(vector<Candidato> lista){
    cout << "Número de vagas: " << lista.size() << "\n" << endl; 
}

//retornando a posição do candidato na lista de candidatos
const int get_posicao_candidato(vector<Candidato> lista, Candidato cand) {

    int index = distance(lista.begin(), find(lista.begin(), lista.end(), cand));

    return index;
}

const vector<Candidato> create_lista_candidatos_eleitos(Eleicao &e, int flag_cargo){
    vector<Candidato> aux;

    for (auto &c : e.get_candidatos_ordenados()){
        if (c.is_eleito(flag_cargo)){
            aux.push_back(c);
        }  
    }
    return aux;
}

const vector<Candidato> create_lista_candidatos_nao_eleitos(Eleicao &e, int flag_cargo){
    vector<Candidato> aux;

    for (auto &c : e.get_candidatos_ordenados()){
        if (!c.is_eleito(flag_cargo)){
            aux.insert(aux.begin(),c); // inserindo do começo
        }  
    }
    return aux;
}