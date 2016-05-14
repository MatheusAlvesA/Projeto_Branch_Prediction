#ifndef _PREDITOR_
#define _PREDITOR_
#include <iostream>

class Preditor {

public:
Preditor(int *[4], int); // este construtor seta os valores
~Preditor() {/*vazio*/}

void processar(void);

private:
 int interacoes;
 int **saltos;

};
#include "preditor.cpp" // criando ligação entre a implementação e a classe
#endif