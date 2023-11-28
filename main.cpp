#include <iostream>

#include "headers/input.h"

#define FEDERAL 6
#define ESTADUAL 7

int main(int argc, char *argv[])
{
    if (argc < 5) {
        exit(printf("Argumentos insuficientes!\n"));
    }

    string cargo(argv[1]);
    int flag_cargo;

    if (cargo.compare("--federal") == 0) {
        flag_cargo = FEDERAL;
    }
    else if (cargo.compare("--estadual") == 0) {
        flag_cargo = ESTADUAL;
    }
    else {
        // tratar exeção
        flag_cargo = -1;
    }

    string arquivo_candidatos(argv[2]);
    string arquivo_votos(argv[3]);
    string data_eleicao(argv[4]);

    cout << arquivo_candidatos << " " << arquivo_votos << " " << data_eleicao << endl;

    Eleicao e;

    // fazer leitura do arquivo
    read_arquivo_candidatos(arquivo_candidatos, e, flag_cargo, data_eleicao);

    // processar a saida

    return 0;
}