#include "../headers/input.h"

#include <fstream>
#include <sstream>
#include <iostream>

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

string iso_8859_1_to_utf8(string &str)
{
    // adaptado de: https://stackoverflow.com/a/39884120 :-)
    string strOut;
    for (string::iterator it = str.begin(); it != str.end(); ++it)
    {
        uint8_t ch = *it;
        if (ch < 0x80)
        {
            // já está na faixa ASCII (bit mais significativo 0), só copiar para a saída
            strOut.push_back(ch);
        }
        else
        {
            // está na faixa ASCII-estendido, escrever 2 bytes de acordo com UTF-8
            // o primeiro byte codifica os 2 bits mais significativos do byte original (ISO-8859-1)
            strOut.push_back(0b11000000 | (ch >> 6));
            // o segundo byte codifica os 6 bits menos significativos do byte original (ISO-8859-1)
            strOut.push_back(0b10000000 | (ch & 0b00111111));
        }
    }

    return strOut;
}

void read_arquivo_candidatos(string file_path, Eleicao &e, int flag_cargo, const string &data_eleicao)
{
    ifstream file;

    try {
        file.open(file_path);

        file.exceptions(ifstream::badbit | ifstream::failbit);

        string linha;
        string info;
        vector<string> line_vector;

        int cd_cargo, cd_situacao_candidato_tot, nr_partido, nr_candidato, nr_federacao, cd_sit_tot_turno, cd_genero;
        string nm_tipo_destinacao_votos, sg_partido, nm_urna_candidato;

        bool flag_read_line;

        getline(file, linha); // ignorando a primeira linha do arquivo
        
        while (getline(file, linha)) {

            istringstream line_stream(linha);

            while (getline(line_stream, info, ';')) {
                info.erase(0, 1);
                info.erase(info.length()-1, 1); // essas duas funções tiram as aspas
                line_vector.push_back(info);
            }

            // agora line_vector contem todas as colunas de uma das linhas do arquivo

            cd_cargo = stoi(line_vector[POS_CD_CARGO]);
            cd_situacao_candidato_tot = stoi(line_vector[POS_CD_SITUACAO_CANDIDATO_TOT]);
            nm_tipo_destinacao_votos = iso_8859_1_to_utf8(line_vector[POS_NM_TIPO_DESTINACAO_VOTOS]);

            flag_read_line = get_flag_read_line(cd_cargo, cd_situacao_candidato_tot, nm_tipo_destinacao_votos, flag_cargo);


            nr_partido = stoi(line_vector[POS_NR_PARTIDO]);
            sg_partido = iso_8859_1_to_utf8(line_vector[POS_SG_PARTIDO]);

            if (!e.has_partido(nr_partido)) {
                Partido part(nr_partido, sg_partido);
                e.insere_partido(nr_partido, part);
            }
            Partido &p = e.get_partido(nr_partido); // pegando referencia de partido que está em eleicao

            if (flag_read_line) {
                
                nr_candidato = stoi(line_vector[POS_NR_CANDIDATO]);
                nm_urna_candidato = iso_8859_1_to_utf8(line_vector[POS_NM_URNA_CANDIDATO]);
                nr_federacao = stoi(line_vector[POS_NR_FEDERACAO]);
                cd_sit_tot_turno = stoi(line_vector[POS_SIT_TOT_TURNO]);
                cd_genero = stoi(line_vector[POS_CD_GENERO]);

                Candidato c(cd_cargo, cd_situacao_candidato_tot, nr_candidato, nm_urna_candidato, p,
                    nr_federacao, cd_sit_tot_turno, cd_genero, nm_tipo_destinacao_votos);

                e.insere_candidato(nr_candidato, c);
                p.add_candidato(e.get_candidato(nr_candidato), flag_cargo);
            }

            line_vector.clear();
        }

        file.close();
    }
    catch (ios_base::failure &e) {
        cerr << "Houve um erro com o input" << endl;
        cerr << e.what() << endl;
    }
    catch (out_of_range &e) {
        cerr << "Tentativa de acesso a região de memória indevida" << endl;
        cerr << e.what() << endl;
    }
    catch(invalid_argument &e) {
        cerr << "Argumento invalido na função stoi()" << endl;
        cerr << e.what() << endl;
    }
    catch (...) {
        cerr << "Alguma exceção foi lançada" << endl;
    }
}

void read_arquivo_votos(string file_path, Eleicao &e, int flag_cargo)
{
    ifstream file;
    try {
        file.open(file_path);

        file.exceptions(ifstream::badbit | ifstream::failbit);

        string linha;
        string info;

        vector<string> line_vector;

        int cd_cargo, nr_notavel, qt_votos;

        getline(file, linha); // ignorando a primeira linha do arquivo
        
        while (getline(file, linha)) {

            istringstream line_stream(linha);

            while (getline(line_stream, info, ';')) {
                info.erase(0, 1);
                info.erase(info.length()-1, 1); // essas duas funções tiram as aspas
                line_vector.push_back(info);
            }

            // agora line_vector contem todas as colunas de uma das linhas do arquivo

            cd_cargo = stoi(line_vector[POS_CD_CARGO]);
            nr_notavel = stoi(line_vector[POS_VOTE_NR_VOTAVEL]);
            qt_votos = stoi(line_vector[POS_VOTE_QTD_VOTOS]);

            bool flag_read_line;
            
            if (cd_cargo == flag_cargo && !(nr_notavel == 95 || nr_notavel == 96 || nr_notavel == 97 || nr_notavel == 98)) {

                if (e.has_candidato(nr_notavel)) {

                    Candidato &c = e.get_candidato(nr_notavel);
                    Partido &p = c.get_partido();

                    if (c.get_nm_tipo_destinacao_votos().compare("Válido (legenda)")){ //salvar essa variavel num tipo boleano
                        p.inc_votos_de_legenda(qt_votos);
                    }
                    else {
                        p.inc_votos_nominais(qt_votos);
                        c.inc_votos_nominais(qt_votos);
                    }

                    flag_read_line = false;
                }

                if (flag_read_line) {

                    if (e.has_partido(nr_notavel)) {
                        Partido &p = e.get_partido(nr_notavel);

                        p.inc_votos_nominais(qt_votos);
                    }

                }
            }

            line_vector.clear();
        }
    }
    catch (ios_base::failure &e) {
        cerr << "Houve um erro com o input" << endl;
        cerr << e.what() << endl;
    }
    catch (out_of_range &e) {
        cerr << "Tentativa de acesso a região de memória indevida" << endl;
        cerr << e.what() << endl;
    }
    catch(invalid_argument &e) {
        cerr << "Argumento invalido na função stoi()" << endl;
        cerr << e.what() << endl;
    }
    catch (...) {
        cerr << "Alguma exceção foi lançada" << endl;
    }
}