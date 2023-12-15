#include <iostream>

#include "headers/input.h"
#include "headers/output.h"

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
        cout << "Argumento invalido, as opções são: --federal ou --estadual" << endl;
        exit(EXIT_FAILURE);
    }

    string arquivo_candidatos(argv[2]);
    string arquivo_votos(argv[3]);
    string data_eleicao(argv[4]);

    Eleicao e(data_eleicao);

    // fazer leitura do arquivo
    read_arquivo_candidatos(arquivo_candidatos, e, flag_cargo, data_eleicao);
    read_arquivo_votos(arquivo_votos, e, flag_cargo);

    // processar a saida
    output_saidas(e, data_eleicao, flag_cargo);

    return 0;
}