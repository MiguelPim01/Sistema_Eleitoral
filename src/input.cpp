#include "../headers/input.h"

#include <fstream>
#include <sstream>

#define POS_CD_CARGO 13
#define POS_CD_SITUACAO_CANDIDATO_TOT 68
#define POS_NM_TIPO_DESTINACAO_VOTOS 67
#define POS_NR_PARTIDO 27
#define POS_SG_PARTIDO 28
#define POS_NR_CANDIDATO 16
#define POS_NM_URNA_CANDIDATO 18
#define POS_NR_FEDERACAO 30
#define POS_SIT_TOT_TURNO 56
#define POS_CD_GENERO 45
#define POS_DT_NASCIMENTO 42

#define POS_VOTE_CD_CARGO 17
#define POS_VOTE_NR_VOTAVEL 19
#define POS_VOTE_QTD_VOTOS 21


bool get_flag_read_line(int cd_cargo, int cd_situacao_candidato_tot, string nm_tipo_destinacao_votos, int cargo)
{
    if (cd_cargo == cargo) {

        if (cd_situacao_candidato_tot == 2 || cd_situacao_candidato_tot == 16) {
            return true;
        }
        else {
            if (nm_tipo_destinacao_votos.compare("Válido (legenda)")) {
                return true;
            }
        }
    }

    return false;
}

void read_arquivo_candidatos(string file_path, Eleicao &e, int flag_cargo, const string &data_eleicao)
{
    ifstream file(file_path);

    string linha;
    string info;
    vector<string> line_vector;

    int cd_cargo, cd_situacao_candidato_tot, nr_partido, nr_candidato, nr_federacao, sit_tot_turno, cd_genero;
    string nm_tipo_destinacao_votos, sg_partido, nm_urna_candidato;

    bool flag_read_line;

    getline(file, linha); // ignorando a primeira linha do arquivo
    
    while (getline(file, linha)) {

        istringstream line_stream(linha);

        while (getline(line_stream, info, ';')) {
            line_vector.push_back(info);
        }

        // agora line_vector contem todas as colunas de uma das linhas do arquivo

        cd_cargo = stoi(line_vector[POS_CD_CARGO]);
        cd_situacao_candidato_tot = stoi(line_vector[POS_CD_SITUACAO_CANDIDATO_TOT]);
        nm_tipo_destinacao_votos = line_vector[POS_NM_TIPO_DESTINACAO_VOTOS];

        flag_read_line = get_flag_read_line(cd_cargo, cd_situacao_candidato_tot, nm_tipo_destinacao_votos, flag_cargo);


        nr_partido = stoi(line_vector[POS_NR_PARTIDO]);
        sg_partido = stoi(line_vector[POS_SG_PARTIDO]);

        if (e.has_partido(nr_partido)) {
            Partido p = e.get_partido(nr_partido);
        }
        else {
            Partido p(nr_partido, sg_partido);
            e.insere_partido(nr_partido, p);
        }

        if (flag_read_line) {
            // le a linha
        }
    }

    file.close();
}

void read_arquivo_votos(string file_path, Eleicao &e, int flag_cargo)
{
    ifstream file(file_path);

    string linha;
    string info;

    vector<string> line_vector;

    getline(file, linha); // ignorando a primeira linha do arquivo
    
    while (getline(file, linha)) {

        istringstream line_stream(linha);

        while (getline(line_stream, info, ';')) {
            line_vector.push_back(info);
        }

        // agora line_vector contem todas as colunas de uma das linhas do arquivo


    }
}