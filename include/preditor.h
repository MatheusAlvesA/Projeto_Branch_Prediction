#ifndef _PREDITOR_
#define _PREDITOR_
#include <iostream>

class Preditor {

public:
Preditor(int *[4], int, int predit = 2); // este construtor seta os valores
~Preditor() {/*vazio*/}

void processar(void);

private:
 int interacoes;
 int preditor;
 bool bitA = true;
 bool bitB = true;
 bool prediction = true; // cimeça como tomado
 int **saltos;
 int **resultados; // guarda se ouve acerto ou erro naquela predição

 int *extrair_correlacao(int); // extrai a correlação em um vetor que contem os saltos correlacionados
 bool checar_correlacao(int, int); // retorna se existe alguma correlação e se deve testar o salto
 bool prever(int); // função de controle de fluxo
 bool bits(int); // preditor de 2 bits
 bool bit(int); // preditor de 1 bit
 void limpar_cache(); // faz a predição voltar ao estado inicial de tomado

};
#include "preditor.cpp" // criando ligação entre a implementação e a classe
#endif
