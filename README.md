# Sistema_Eleitoral
Trabalho Prático II desenvolvido na disciplina de Programação Orientada a Objetos

-------------------------------------------
############
# Exemplo de makefile
# Prof. João Paulo A. Almeida
# Programação OO
#
# A princípio, você não precisa alterar nada, mas aqui assume-se que o diretório atual
# é o diretório onde estão os códigos fonte (.cpp).
#
# nome do compilador
CPP = g++
# opções de compilação
CFLAGS = -Wall -g
CPPFLAGS = -std=c++17
# define lista de arquivos-fonte, assumindo que estão no diretório atual
FONTES = $(wildcard ./src/*.cpp)
# define lista dos arquivos-objeto usando nomes da lista de arquivos-fonte
OBJETOS = $(FONTES:./src/%.cpp=./objects/%.o)
# nome do arquivo executável
EXECUTAVEL = deputados
############ alvos
#
# use @ antes de todos os comandos, pois é necessário no script de teste
#
# alvo principal é o executável

all: $(EXECUTAVEL)

# para linkar o executável, precisamos dos arquivos-objetos
$(EXECUTAVEL): $(OBJETOS) ./objects/main.o
	@$(CPP) -o $@ $^

# alvo para cada arquivo-objeto depende do código fonte
# (observação, aqui não estamos capturando as dependências de arquivos .h)
./objects/%.o: ./src/%.cpp
	@$(CPP) $(CPPFLAGS) -c -o $@ $(CFLAGS) $^

./objects/main.o: main.cpp $(FONTES)
	@$(CPP) $(CPPFLAGS) -c -o $@ $(CFLAGS) $<

# comandos para execução
runfederal: $(EXECUTAVEL)
	@./$(EXECUTAVEL) --federal candidatos.csv votacao.csv 02/10/2022
runestadual: $(EXECUTAVEL)
	@./$(EXECUTAVEL) --estadual candidatos.csv votacao.csv 02/10/2022

# comando para limpeza
clean:
	@rm ./objects/*.o $(EXECUTAVEL) *.csv *.txt