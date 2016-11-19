# Paulo da Cunha Passos - 10/0118577
# Pansta onde o CUnite está instalado na máquina
prefix = /opt/local
# Pasta da biblioteca do CUnit
LIBS= ${prefix}/lib
# Pasta dos arquivos headeres do CUnit			
dirinclude = ${prefix}/include 	

# Inclui os arquivos de cabecalho CUnit p compilacao
INCLUDES = -I${dirinclude}		
CC = gcc
DEPSG = grafo.h testa_grafo.h
OBJ = grafo.o testa_grafo.o main.o
all: grafo clean
	./grafo
%.o: %.c $(DEPSG)
	$(CC) -c -w -o $@ $< $(INCLUDES)

grafo: $(OBJ)
	$(CC) -L$(LIBS) -o $@ $^ -lcunit

clean:
	rm -rf *.o