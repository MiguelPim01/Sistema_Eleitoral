#if !defined(INPUT_H)
#define INPUT_H

#include "eleicao.h"

void read_arquivo_candidatos(string file_path, Eleicao &e, int flag_cargo, const string &data_eleicao);

void read_arquivo_votos(string file_path, Eleicao &e, int flag_cargo);

#endif // INPUT_H
