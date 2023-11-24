#include "../headers/input.h"

#include <fstream>
#include <sstream>

void read_arquivo_candidatos(char *file_path, Eleicao &e, int flag_cargo, const string &data_eleicao)
{
    ifstream file(file_path);

    string linha;
    string info;
    
    while (getline(file, linha)) {

        istringstream line_stream(linha);

        while (getline(line_stream, info, ';')) {
            // info é uma string e contem a informação sobre cada coluna do .csv
        }

    }
}

void read_arquivo_votos(char *file_path, Eleicao &e, int flag_cargo)
{
    ifstream file(file_path);

    string linha;
    string info;
    
    while (getline(file, linha)) {

        istringstream line_stream(linha);

        while (getline(line_stream, info, ';')) {
            // info é uma string e contem a informação sobre cada coluna do .csv
        }

    }
}