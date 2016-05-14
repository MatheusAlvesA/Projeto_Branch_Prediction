#include "preditor.h"

Preditor::Preditor(int **matriz, int N_interacts) {
  this->saltos = matriz;
  this->interacoes = N_interacts;
}

void Preditor::processar(void) {
  for(int x = 0;this->saltos[x] != nullptr;x++) {
  	std::cout << "{[" << this->saltos[x][0] << "]";
  	for(int y = 1; y < this->interacoes; y++)
  	 std::cout << "|" << this->saltos[x][y] << "|";
  	std::cout << "}\n";
  }
}
