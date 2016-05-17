#include <iostream>
#include <fstream>
#include <string>

#include "preditor.h"

int extrair_saltos(std::string string, int *&numeros);
int tokenizar(int **&matriz, std::string nome);

int main(int argc, char * argv[]) {
    std::string nome;
    if ( argc > 1 )
    {
        nome =  argv[1]; // recebe o nome do arquivo por parametro
    }
    else
    {
        std::cout << "\nErro !!! O local do arquivo de entrada não foi passado por parâmetro\n\n";
        return false;
    }

   int **matriz = new int*[4]; // São 3 correlações mais o primeiro salto que não possui correlação

   for(int x = 0; x < 3;x++)
    matriz[x] = nullptr;

   int quantas = tokenizar(matriz, nome); // faz a leitura e a extração dos dados para o arquivo
    Preditor preditor(matriz, quantas+1, 2);
    preditor.processar();

   for(int x = 0; x < 4; x++);
    //delete [] matriz[x]; // liberando memória

   return 0;
}

int tokenizar(int **&matriz, std::string nome) {
 std::string linha; // armazena a linha completa do arquivo

 std::ifstream arquivo; // instanciando um ponteiro pro arquivo
 arquivo.open(nome); // abrindo o arquivo

 if(!(arquivo.is_open() && arquivo.good()))  { // verificar se abriu e se está "usavel"
   std::cout << "\nFalha !!!  Não foi possivel abrir o arquivo \"" << nome << "\"\n\n";
   exit(0); // saida do programa por erro fatal
 }

int x = 0; // essa vriavel coloca os saltos em suas posições na matriz
int quantos; // guarda quantas interaçãoes esses saltos vão ter
while(!arquivo.fail() && x < 4) { // esse loop vai percorrer linha a linha do arquivo lendo até 4 saltos
 std::getline(arquivo, linha); // lendo a linha e guardando na string linha
 quantos = extrair_saltos(linha, matriz[x]); // extraindo todos os numeros encontratos na linha e armazenando na matriz
 x++;
}

arquivo.close(); // fechando apos terminar de ler
return quantos-1; // menos um retornará o resultado correto
}

int extrair_saltos(std::string bruto, int *&saltos) {
  saltos = new int[bruto.size()]; // alocando espaço para todas as interações
  saltos[0] = 0; // esse elemento representa a correlação do saltos
  int x = 1; // variável de controle para o vetor de saltos
  bool lendo_correlacao = true; // esse booleano controla se a correlação está sendo lida nesse momento
   for(int i = 0; bruto[i] != '\0'; i++)  { // percorrer todos os caracteres
    if(lendo_correlacao) {//  verificar se o o salto tem correlação
      if(bruto[i] == '-') { // caso não aja correlação de salto
        saltos[0] = 0; // não tem correlação com ninguem
      }
      else {
       if(bruto[i] == ' ')
        lendo_correlacao = false; // terminou de ler correlação e vai começar com as interações
       else {
        if(bruto[i] == '/') saltos[0] *= 10; // abrindo espaço para por a nova correlação
        else saltos[0] += bruto[i] - '0'; // convertendo de caractere para inteiro
       }
      }
    }
    else { // caso o caracter atual NÃO seja um numero porem o ultimo caracter lido era um numero
      if(bruto[i] == 'T')
        saltos[x] = 1;
      else
        saltos[x] = 0;
      x++;
    }
  }
  return x;
}
