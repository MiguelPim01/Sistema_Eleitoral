GPP = g++
DEPUTADOS = deputados

make : 
	@$(GPP) -c ./src/*.cpp main.cpp
	@mkdir objects
	@mv *.o ./objects
	@$(GPP) ./objects/*.o -o $(DEPUTADOS) 
	@rm -rf objects

run :
	@./$(DEPUTADOS) --estadual ./in/candidatos.csv ./in/votacao.csv 02/10/2022
	

clean :
	@rm -rf objects deputados 