#if !defined(INPUT_H)
#define INPUT_H

#include "eleicao.h"

void read_arquivo_candidatos(char *file_path, Eleicao &e, int flag_cargo, const string &data_eleicao);

void read_arquivo_votos(char *file_path, Eleicao &e, int flag_cargo);

#endif // INPUT_H
