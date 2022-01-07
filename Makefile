CC=g++
LIBS = -std=c++11
LIB = ./lib
DIR = ./src

pca: pca.o driver.o
	$(CC) -o pca $(DIR)/Pca.cpp $(DIR)/driver.cpp $(LIBS)

pca.o: $(DIR)/Pca.cpp $(DIR)/Pca.h
	$(CC) -c -o $(DIR)/pca.o $(DIR)/Pca.cpp $(LIBS)

driver.o: $(DIR)/driver.cpp 
	$(CC) -c -o $(DIR)/driver.o $(DIR)/driver.cpp $(LIBS)

run:
	export LD_LIBRARY_PATH = ./pca

clean:
	@rm $(DIR)/*.o
	@rm ./pca